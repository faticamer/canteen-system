#include <iostream>
#include <string>
#include <vector>
#include <chrono> // for measuring time.
#include <thread> // for creating threads.
#include <fstream> // for file I/O operations.
#include <cmath> // for mathematical operations.
#include "operation_header.h"
#include "food_item.h"
#include "bag.h"

std::vector<BuyerBag> buyerBag; // array of structs representing the buyer's bag of purchased items.
BuyerBag structBuyerBag;
double mainPrice = 0;   // a double representing the total price of the items in the bag.
double buyerCheck = 0;  // a double representing the amount of money the buyer inserts at checkout.
int quantityToBuy;

using namespace std;
using namespace std::this_thread;
using namespace std::chrono;


// displays the buyer menu and waits for the user's selection until they choose to exit.
void viewBuyerMenu()
{
    bool controller = true;
    char choice = '0';
    while(controller)
    {
        viewBuyerSelectionList();
        cout << "\nOperation: ";
        cin >> choice;
        executeBuyerChoice(choice, foodItems, controller);
    }
}

// receives the buyer's selection and decides which operation to execute.
void executeBuyerChoice(char selection, vector<FoodItem>& foodItems, bool& controller)
{
    switch(selection)
    {
    case '1':
        listAvailableItems(foodItems);
        purchaseItemQuery();
        break;
    case '2':
        searchFoodItem(foodItems);
        break;
    case 'Q':
        cout << "You're about to leave the buyer menu... \n\n";
        sleep_for(nanoseconds(50));
        sleep_until(system_clock::now() + seconds(1));
        controller = false;
        break;
    case 'q':
        cout << "You're about to leave the buyer menu... \n\n";
        sleep_for(nanoseconds(50));
        sleep_until(system_clock::now() + seconds(1));
        controller = false;
        break;

    }
}

// displays a list of available food items and their details.
void listAvailableItems(vector<FoodItem>& foodItems)
{
    cout << "Fetching the data...\n" << endl;
    sleep();
    for (const auto& foodItem: foodItems) {
        cout << "Name: " << foodItem.name << "\nCategory: " << foodItem.category << "\nQuantity: " << foodItem.quantity << "\nPrice: $"
        << foodItem.price << "\n" << endl;
    }
}

// prompts the user to enter a food item's name or category and displays the first item that matches the search string.
// searchFoodItem updated
void searchFoodItem(vector<FoodItem>& foodItems)
{
    string searchStr;
    char selection;
    cout << "\nEnter the name or category of the food item to search: ";
    cin.ignore();
    getline(cin, searchStr);

    sleep();
    bool found = false;
    for (auto& item : foodItems) {
        if ((item.name == searchStr) || (item.category == searchStr)) {
            found = true;
            if(item.category == searchStr)
            {
                searchFoodItemLogic(foodItems, searchStr);
                break;
            }
            cout << "\nItem found: " << item.name << " (" << item.category << ")" << endl;

            cout << "Would you like to purchase this item? (Y/N): ";
            cin >> selection;

            if((selection == 'Y') || (selection == 'y'))
                purchaseSingleItem(searchStr);
            else
            {
                cout << "Continuing to buyer's menu... " << endl;
                sleep();
            }
            break; // exit the loop after finding the first matching item
        }
    }

    if (!found) {
        cout << "Not found." << endl;
    }
}

void searchFoodItemLogic(vector<FoodItem> foodItems, string searchStr)
{
    char selection;
    cout << "Opening the catalog... " << endl;
    sleep();

    if(searchStr == "meat meal")
    {
        cout << "From meat meals category: " << endl;
        sleep();
        for(const auto& article : foodItems)
            for(const auto& articleCat : article.mCategory)
                cout << "- " << articleCat << endl;

        cout << "Would you like to purchase any item? (Y/N): ";
        cin >> selection;
        if((selection == 'Y') || (selection == 'y'))
            purchaseForCategories();
        else
        {
            cout << "Continuing to buyer's menu... " << endl;
            sleep();
        }
    }
    else if(searchStr == "meat meals")
    {
        cout << "From meat meals category: " << endl;
        sleep();
        for(const auto& article : foodItems)
            for(const auto& articleCat : article.mCategory)
                cout << "- " << articleCat << endl;

        cout << "Would you like to purchase any item? (Y/N): ";
        cin >> selection;
        if((selection == 'Y') || (selection == 'y'))
            purchaseForCategories();
        else
        {
            cout << "Continuing to buyer's menu... " << endl;
            sleep();
        }
    }
    else if(searchStr == "vegetable meal")
    {
        cout << "From vegetable meals category: " << endl;
        sleep();
        for(const auto& article : foodItems)
            for(const auto& articleCat : article.vCategory)
                cout << "- " << articleCat << endl;

        cout << "Would you like to purchase any item? (Y/N): ";
        cin >> selection;
        if((selection == 'Y') || (selection == 'y'))
            purchaseForCategories();
        else
        {
            cout << "Continuing to buyer's menu... " << endl;
            sleep();
        }
    }
    else if(searchStr == "vegetable meals")
    {
        cout << "From vegetable meals category: " << endl;
        sleep();
        for(const auto& article : foodItems)
            for(const auto& articleCat : article.vCategory)
                cout << "- " << articleCat << endl;

        cout << "Would you like to purchase any item? (Y/N): ";
        cin >> selection;
        if((selection == 'Y') || (selection == 'y'))
            purchaseForCategories();
        else
        {
            cout << "Continuing to buyer's menu... " << endl;
            sleep();
        }
    }
    else if(searchStr == "drink")
    {
        cout << "From drinks category: " << endl;
        sleep();
        for(const auto& article : foodItems)
            for(const auto& articleCat : article.dCategory)
                cout << "- " << articleCat << endl;

        cout << "Would you like to purchase any item? (Y/N): ";
        cin >> selection;
        if((selection == 'Y') || (selection == 'y'))
            purchaseForCategories();
        else
        {
            cout << "Continuing to buyer's menu... " << endl;
            sleep();
        }
    }
    else if(searchStr == "drinks")
    {
        cout << "From drinks category: " << endl;
        sleep();
        for(const auto& article : foodItems)
            for(const auto& articleCat : article.dCategory)
                cout << "- " << articleCat << endl;

        cout << "Would you like to purchase any item? (Y/N): ";
        cin >> selection;
        if((selection == 'Y') || (selection == 'y'))
            purchaseForCategories();
        else
        {
            cout << "Continuing to buyer's menu... " << endl;
            sleep();
        }
    }
    else {
        cout << "Unexpected error occurred. Terminating the program... " << endl;
        exit(-1);
    }
}

// asks the buyer if they want to purchase a single or multiple items or exit the program.
void purchaseItemQuery()
{
    char selection = '0';
    string item_selection;
    bool controller = true;

    cout << "Would you like to buy any of the listed items?\nY - Single item purchase\nM - Multiple items purchase\nN - no purchase\n " << endl;
    cout << "Operation: ";
    cin >> selection;

    while(controller)
    {
        switch(selection)
        {
        case 'Y':
            cout << "Select an item you want to purchase: ";
            cin.ignore(); // discard a character \n that is left in the input buffer
            getline(cin, item_selection);
            addToBag(item_selection, foodItems, buyerBag);
            checkout();
            cout << "~ Insert money: $";
            cin >> buyerCheck;
            askForPay(round(buyerCheck * 100.0) / 100.0, foodItems, quantityToBuy);
            notifyAboutEmptyCart();
            resetTheMainPrice(mainPrice);
            controller = false;
            break;
        case 'y':
            cout << "Select an item you want to purchase: ";
            cin.ignore();
            getline(cin, item_selection);
            addToBag(item_selection, foodItems, buyerBag);
            checkout();
            cout << "~ Insert money: ";
            cin >> buyerCheck;
            askForPay(round(buyerCheck * 100.0) / 100.0, foodItems, quantityToBuy);
            notifyAboutEmptyCart();
            resetTheMainPrice(mainPrice);
            controller = false;
            break;
        case 'M':
            cout << "Select items you want to purchase.\nAfter you finish, Press C to go to checkout... "
            << "\nPress Q to return to menu...\n" << endl;
            while(true)
            {
                cout << "Item entry -> ";
                cin >> item_selection;
                if((item_selection == "C") || (item_selection == "c"))
                {
                    checkout();
                    controller = false;
                    break;
                }
                addToBag(item_selection, foodItems, buyerBag);
                cout << "Price of the cart so far: $" << mainPrice << "\n" << endl;
            }
            cout << "~ Insert money: ";
            cin >> buyerCheck;
            askForPay(round(buyerCheck * 100.0) / 100.0, foodItems, quantityToBuy);
            notifyAboutEmptyCart();
            break;
        case 'm':
            cout << "\nFirst, select items you want to purchase.\nAfter you finish, Press C to go to checkout... "
            << "\nPress Q to return to menu...\n" << endl;
            while(true)
            {
                cout << "Item entry -> ";
                cin >> item_selection;
                if((item_selection == "C") || (item_selection == "c"))
                {
                    checkout();
                    controller = false;
                    break;
                }
                addToBag(item_selection, foodItems, buyerBag);
                cout << "~ Price to pay so far: $" << mainPrice << "\n" << endl;
            }
            cout << "~ Insert money: ";
            cin >> buyerCheck;
            askForPay(round(buyerCheck * 100.0) / 100.0, foodItems, quantityToBuy);
            notifyAboutEmptyCart();
            break;
        case 'N':
            cout << "\nReturning back to the Buyer's menu..." << endl;
            controller = false;
            sleep();
            break;
        case 'n':
            cout << "\nReturning back to the Buyer's menu..." << endl;
            controller = false;
            sleep();
            break;
        }
    }
}

// function to handle the checkout if user searched items using categories
// asks user for an input, and calls purchaseSingleItem function
void purchaseForCategories()
{
    string item;
    cout << "Select item you want to purchase: ";
    cin.ignore();
    getline(cin, item);

    purchaseSingleItem(item);
}

// special function if user wishes to purchase a single item
void purchaseSingleItem(string searchStr)
{
    addToBag(searchStr, foodItems, buyerBag);
    checkout();
    cout << "~ Insert money: ";
    cin >> buyerCheck;
    askForPay(round(buyerCheck * 100.0) / 100.0, foodItems, quantityToBuy);
    notifyAboutEmptyCart();
    resetTheMainPrice(mainPrice);
}

// adds a food item to the buyer's bag and updates the total price.
void addToBag(string item_selection, vector<FoodItem>& foodItems, vector<BuyerBag>& buyerBag)
{
    vector<string> items;
    vector<double> prices;
    bool found = false;
    for (auto& item : foodItems) {
        if (item.name == item_selection /*|| item.category == item_selection*/) {
            found = true;
            if (item.quantity > 0) {
                sleep();
                cout << "\nItem is available. \nQuantity: " << item.quantity << endl;
                cout << "Price per unit: $" << item.price << endl;
                cout << "Enter quantity to purchase: ";

                quantityToBuy = 0; // pass it to writeSales function to determine the price of each sale...
                cin >> quantityToBuy;
                cin.ignore(); // ignore the newline character after the integer input

                if (quantityToBuy > 0 && quantityToBuy <= item.quantity) {
                    item.quantity -= quantityToBuy;
                    double totalPrice = item.price * quantityToBuy; // totalPrice relates to the price for the current item
                    mainPrice += totalPrice;    // mainPrice relates to the price of the whole cart
                    items.push_back(item_selection);
                    prices.push_back(totalPrice); // capture individual prices * quantity

                    structBuyerBag.items = items;
                    structBuyerBag.individualPrices = prices;
                    structBuyerBag.price = mainPrice; // Price of the whole bag
                    buyerBag.push_back(structBuyerBag);

                    sleep();
                    cout << "\n---------------------------------" << endl;
                    cout << "Added to cart. \nBag updated. \nTotal cost of your bag: $" << totalPrice << endl;
                    writeToSalesFileFromOperation(buyerBag); // UPDATING SALES FILE
                    cout << "---------------------------------" << endl;

                } else {
                    cout << "Invalid quantity. Purchase failed." << endl;
                    buyerBag.clear(); //
                    ofstream sales("canteen_reports/sales.txt", std::ios::trunc);
                    sales.close();
                }
            } else {
                cout << "Item is not available." << endl;
            }
            break; // exit the loop after finding the first matching item
        }
    }

    if (!found) {
        cout << "Item not found." << endl;
    }
}


// takes in a vector of BuyerBags and prints out a list of the items in each bag, along with the total price.
void listTheBagItemsWithPrice(vector<BuyerBag>& buyerBag)
{
    sleep();
    cout << "Items: " << endl;
    for(const auto& bag : buyerBag)
    {
        for(const auto& item : bag.items)
            cout << "- " << item << endl;
    }
    cout << "Total price: $" << mainPrice << endl;
    cout << "----------------------" << endl;
}

/*
This function takes in the amount of money the buyer is paying and a vector of FoodItems.
If the buyer has insufficient funds, their cart is emptied and they are returned to the main menu.
If they pay the exact amount, the payment is processed without change.
Otherwise, their change is calculated and printed.

WARNING: Do not remove round( ) function called on buyerCheck variable.
            There are cases where the comparison does not behave as intended.
            Without round( ), if user prompts buyerCheck that seems to be equal to
            mainPrice, the compiler will not consider buyerCheck == mainPrice to be satisfied
            and therefore, program chooses different execution path. Reason behind this are the
            decimal points that will most likely not be visible to a user. Those last decimals
            usually differ by +-1.
            Example:
            - buyerCheck = 1.27(0000007)
            - mainPrice = 1.27(0000006)
            Decimals in parenthesis are the ones that are not visible. Refer to the last decimal.
*/
void askForPay(double buyerCheck, vector<FoodItem>& foodItems, int quantity)
{
    double remainder = 0;

    if(round(buyerCheck * 100.0) / 100.0 < round(mainPrice* 100.0) / 100.0) {
        cout << "Insufficient funds. Emptying cart and returning to menu. \n" << endl;
        for(auto& item : foodItems)
            item.quantity += quantity;
        buyerBag.clear();
        mainPrice = 0;
    }
    else if(round(buyerCheck * 100.0) / 100.0 == round(mainPrice* 100.0) / 100.0)
    {
        cout << "Processing payment..." << endl;
        sleep();
        cout << "No change. Payment complete. \n" << endl;
    }
    else {
        cout << "Processing payment..." << endl;
        sleep();
        remainder = buyerCheck - mainPrice;
        remainder = round(remainder * 100.0) / 100.0;
        if(remainder == 0)
            cout << "No change. Payment complete. \n" << endl;
        else
        {
            cout << "Payment complete. Your change: $" << remainder << "\n" << endl;
        }
    }
    buyerCheck = remainder;
    buyerBag.clear();
}

// takes in a vector of BuyerBags and writes a report of the items in each bag, along with the individual prices and the total price.
void listTheBagItemsForSalesReport(vector<BuyerBag>& buyerBag)
{
    sales << "Items: " << endl;
    for(const auto& bag : buyerBag)
    {
        for(int i = 0; i < (int) bag.items.size() && i < (int) bag.individualPrices.size(); i++)
        {
            const auto& item = bag.items[i];
            const auto& price = bag.individualPrices[i];

            sales << "- " << item << endl;
            sales << "~ Price of " << item << " you've purchased: $" << price << "\n" << endl;
        }
    }
    sales << "----------------------------------" << endl;
    sales << "Total Price so far: $" << mainPrice << endl;
}

// This function takes in a vector of BuyerBags and writes a report of the items in each bag,
// along with the individual prices and the total price, to a sales file. If the file doesn't exist, it is created.
void writeToSalesFileFromOperation(vector<BuyerBag>& buyerBag)
{
    if (!sales.is_open())
    {
        // File doesn't exist, create it
        sales.open("canteen_reports/sales.txt");
    }

    sales.seekp(0, std::ios::end);
    if(sales.tellp() == 0) {
        sales << " <<< Sales Report >>>\n" << endl;
        listTheBagItemsForSalesReport(buyerBag);
        sales << "\n-- Sales Report updated successfully. --\n" << endl;
    }
    else {
        listTheBagItemsForSalesReport(buyerBag);
        sales << "\n-- Sales Report updated successfully. --\n" << endl;
    }
}

// notifies the user that their cart has been emptied.
void notifyAboutEmptyCart()
{
    sleep();
    cout << "Be advised that you have emptied your cart. \nNext time you wish to select the item/s, your cart will be empty. "
    << "\nHave a nice day! " << endl;
    buyerBag.clear();
    sleep();
}

// prints out the buyer menu options.
void viewBuyerSelectionList()
{
    cout << "\n<<< BUYER's MENU >>>" << endl;
    cout << "Press '1' to list all available items. " << endl;
    cout << "Press '2' to search the specific item (by name/by category). " << endl;
    cout << "Press 'Q' to exit the buyer menu. " << endl;
}

// calls listTheBagItemsWithPrice(vector<BuyerBag> buyerBag) and finalizes the session by
// displaying items with their corresponding prices
void checkout()
{
    cout << "\n<<< CHECKOUT >>>\n" << endl;
    listTheBagItemsWithPrice(buyerBag);
}

// resets the total session cost after session ends.
void resetTheMainPrice(double& mainPrice)
{
    mainPrice = 0;
}

// specifies the delay.
void sleep()
{
    sleep_for(nanoseconds(50));
    sleep_until(system_clock::now() + seconds(1));
}
