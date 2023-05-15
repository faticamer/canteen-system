#include <iostream>
#include <string.h>
#include <vector> // for dynamically allocated arrays.
#include <chrono> // for measuring time.
#include <thread> // for creating threads.
#include <fstream> // for file I/O operations.
#include "setting_header.h"
#include "food_item.h"
#include "bag.h"

std::vector<FoodItem> foodItems;

using namespace std;
using namespace std::this_thread; // sleep_for, sleep_until
using namespace std::chrono; // nanoseconds, system_clock, seconds

// function handles the login process for the admin.
// It prompts the user for a username and password and checks if they match the admin credentials.
void adminLogin(string username, string password)
{
    string user, pass;
    bool controller = true;
    char choice = '0';

    while(controller)
        checkLoginDetails(user, pass, controller);
    controller = true;

    while(controller)
    {
        viewAdminSelectionList();
        cout << "\nOperation: ";
        cin >> choice;
        executeAdminChoice(choice, controller, foodItems);
    }
}

// updated version of addFoodItems
// function allows the admin to add food items to the inventory. It prompts the admin to enter the name, category, quantity, and price of the food item.
// this function updates category vectors, which are later assigned to a vectors in FoodItem struct
// category vectors provide an option to search items using categories when buyer mode is activated
void addFoodItems(vector<FoodItem>& foodItems)
{
    string name, category;
    vector<string> mCategory, vCategory, dCategory;
    int quantity;
    float price;

    cout << "\nEnter the name of the food item: ";
    cin.ignore();
    getline(cin, name);

    cout << "Enter the category of the food item (meat meals, vegetable meals, drinks): ";
    while(true)
    {
        getline(cin, category);
        if((category != "meat meals") && (category != "vegetable meals") &&
                (category != "drinks") && (category != "meat meal") && (category != "vegetable meal") &&
                (category != "drink"))
        {
            cout << "Wrong category. Please try again... " << endl;
            sleepSetting();
        }
        else {
            if(category == "meat meal")
                mCategory.push_back(name);
            else if(category == "meat meals")
                mCategory.push_back(name);
            else if(category == "vegetable meal")
                vCategory.push_back(name);
            else if(category == "vegetable meals")
                vCategory.push_back(name);
            else if(category == "drink")
                dCategory.push_back(name);
            else if(category == "drinks");

            break;
        }
        cout << "-> ";
    }

    cout << "Enter the quantity of the food item: ";
    while(true)
    {
        cin >> quantity;
        if(quantity <= 0) {
            cout << "Setting the quantity failed. \nQuantity cannot be 0 or negative number. Please try again..." << endl;
            sleepSetting();
        }
        else break;
        cout << "-> ";
    }


    cout << "Enter the price of the food item: $";
    while(true)
    {
        cin >> price;
        if(price <= 0) {
            cout << "Setting the price failed. \nPrice cannot be negative. Please try again..." << endl;
            sleepSetting();
        }
        else break;
        cout << "-> ";
    }

    cin.ignore(); // Ignore the newline character left in the input buffer
    foodItems.push_back({ name, category, mCategory, vCategory, dCategory, quantity, price });
}


// function fetches the inventory report. It prompts the admin to choose between a console report or a file report
void fetchInventoryReport(vector<FoodItem>& foodItems)
{
    char selection;
    cout << "\nPress 1 for Console Report. \nPress 2 for File Report. \n\n-> ";
    cin >> selection;
    switch(selection)
    {
    case '1':
        cout << "\nFetching the data...\n" << endl;
        sleepSetting();
        for (const auto& foodItem: foodItems)
        {
            cout << "Name: " << foodItem.name << "\nCategory: " << foodItem.category << "\nQuantity: " << foodItem.quantity << "\nPrice: $"
                 << foodItem.price << "\n" << endl;
        }
        break;
    case '2':
        writeToReportFile(foodItems);
        break;
    default:
        cout << "Wrong input. Terminating the program... " << endl;
        sleepSetting();
        exit(-1);
    }
}

// function displays the menu options for the admin. It lists the available operations that the admin can perform.
void viewAdminSelectionList()
{
    cout << "\n<<< MANAGER MENU >>>" << endl;
    cout << "Press '1' to add food items. " << endl;
    cout << "Press '2' to get a report of the inventory. " << endl;
    cout << "Press '3' to get a report of completed sales. " << endl;
    cout << "Press 'Q' to exit the manager menu. " << endl;
}

// function executes the admin's selected choice from the menu. It takes the operation code,
// a controller flag, and the foodItems vector as parameters, and performs the corresponding action based on the admin's choice.
void executeAdminChoice(char operation, bool& controller, vector<FoodItem>& foodItems)
{
    switch(operation)
    {
    case '1':
        addFoodItems(foodItems);
        break;
    case '2':
        fetchInventoryReport(foodItems);
        break;
    case '3':
        writeToSalesFileFromAdmin();
        break;
    case 'Q':
        cout << "You're about to leave the manager menu... \n\n";
        sleepSetting();
        controller = false;
        break;
    case 'q':
        cout << "You're about to leave the manager menu... \n\n";
        sleepSetting();
        controller = false;
        break;
    default:
        cout << "Your selection was invalid. Terminating the program. ";
        exit(-1);
    }
}

// function checks the admin's login details.
// It prompts the admin to enter a username and password and verifies
// if they match the expected credentials. The controller flag is used to control the login loop
// if a user makes a mistake during input.
void checkLoginDetails(string user, string pass, bool& controller)
{
    cout << "\nEnter login details: " << endl;
    cout << "Username: ";
    cin >> user;

    cout << "Password: ";
    cin >> pass;

    if ((user != "admin") || (pass != "admin"))
        cout << "Wrong username or password. Please try again. " << endl;
    else
    {
        cout << "\nYou've successfully logged in. Welcome " << user << ". " << endl;
        controller = false;
    }
}

// function writes the inventory report to a file.
// It opens or creates the "inventory.txt" file and writes the details of each food item in the foodItems vector.
void writeToReportFile(vector<FoodItem>& foodItems) {
    ofstream inventory("canteen_reports/inventory.txt");
    if (!inventory.is_open()) {
        // File doesn't exist, create it
        inventory.open("canteen_reports/inventory.txt");
    }

    inventory << "<<< Inventory Report >>>\n " << endl;
    for (const auto& foodItem : foodItems) {
        inventory << "Name: " << foodItem.name << "\n";
        inventory << "Category: " << foodItem.category << "\n";
        inventory << "Quantity: " << foodItem.quantity << "\n";
        inventory << "Price: $" << foodItem.price << "\n\n";
    }

    sleepSetting();
    cout << "\n~ Inventory Report generated successfully. " << endl;
    inventory.close();
}

// function writes the finalized sales report to a file.
// It opens or creates the "sales.txt" file and appends the sales report data. It is called from the admin menu.
void writeToSalesFileFromAdmin()
{
    if (!sales.is_open())
    {
        // File doesn't exist, create it
        sales.open("canteen_reports/sales.txt");
    }

    sales.seekp(0, std::ios::end);
    if(sales.tellp() == 0) {
        sales << "No collected data. Sales file empty. " << endl;
    }
    else {
        sales << "<<< Sales Report finalized. Closing>>>\n" << endl;
    }
    cout << "~ Sales Report Updated Successfully. " << endl;
    sleepSetting();
    sales.close();
}

// This function provides a short delay in the program execution.
// It pauses the program for a short period of time using the std::this_thread::sleep_for and std::this_thread::sleep_until functions.
void sleepSetting()
{
    sleep_for(nanoseconds(50));
    sleep_until(system_clock::now() + seconds(1));
}
