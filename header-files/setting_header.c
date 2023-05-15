#ifndef SETTING_HEADER_H_INCLUDED
#define SETTING_HEADER_H_INCLUDED
#include <string>
#include <vector> // for dynamically allocated arrays.
#include "food_item.h"

using namespace std;

void adminLogin(string username, string password);
void executeAdminChoice(char operation, bool& controller, vector<FoodItem>& foodItems);
void checkLoginDetails(string user, string pass, bool& controller);
void addFoodItems(vector<FoodItem>& foodItems);
void fetchInventoryReport(vector<FoodItem>& foodItems);
void writeToReportFile(vector<FoodItem>& foodItems);
void writeToSalesFileFromAdmin();
void viewAdminSelectionList();
void sleepSetting();

#endif // SETTING_HEADER_H_INCLUDED
