#include <iostream>
#include <string>
#include <chrono> // for measuring time.
#include <thread> // for creating threads.
#include "setting_header.h"
#include "operation_header.h"

using namespace std;
using namespace std::this_thread;
using namespace std::chrono;

void mainMenuDisplay(string user, string pass);
void displayGreetingMessage();

int main()
{
    string username = "admin";
    string password = "admin";
    ofstream sales("canteen_reports/sales.txt", std::ios::trunc);
    ofstream inventory("canteen_reports/inventory.txt", std::ios::trunc);
    sales.close();
    inventory.close();
    buyerBag.clear();

    displayGreetingMessage();
    cout << "-- NOTE: Avoid entering the Buyer mode without previously filling up the inventory. ---\n" << endl;
    while(true)
        mainMenuDisplay(username, password);

    return 0;
}

void mainMenuDisplay(string user, string pass) // distribute to both buyer and manager
{
    char selection;

    cout << "Please select your mode: \nB - Buyer mode\nS - Setting mode (for manager)\nQ - Exit the program\n\n-> ";
    cin >> selection;

    switch(selection)
    {
    case 'B':
        viewBuyerMenu();
        break;
    case 'b':
        viewBuyerMenu();
        break;
    case 'S':
        adminLogin(user, pass);
        break;
    case 's':
        adminLogin(user, pass);
        break;
    case 'Q':
        cout << "You're about to leave the program. Terminating..." << endl;
        sleep_for(nanoseconds(50));
        sleep_until(system_clock::now() + seconds(1));
        exit(-1);
    case 'q':
        cout << "You're about to leave the program. Terminating..." << endl;
        sleep_for(nanoseconds(50));
        sleep_until(system_clock::now() + seconds(1));
        exit(-1);
    default:
        cout << "Invalid. " << endl;
        exit(-1);
    }
}

void displayGreetingMessage()
{
    cout << "<<<< Welcome to Canteen!>>>>\n" << endl;
}
