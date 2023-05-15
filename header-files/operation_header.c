#ifndef OPERATION_HEADER_H_INCLUDED
#define OPERATION_HEADER_H_INCLUDED
#include <string>
#include <vector> // for dynamically allocated arrays.
#include "food_item.h"
#include "bag.h"

using namespace std;

void listAvailableItems(vector<FoodItem>& foodItems);
void searchFoodItem(vector<FoodItem>& foodItems);
void executeBuyerChoice(char selection, vector<FoodItem>& foodItems, bool& controller);
void notifyAboutEmptyCart();
void askForPay(double buyerCheck, vector<FoodItem>& foodItem, int quantity);
void addToBag(string item_selection, vector<FoodItem>& foodItems, vector<BuyerBag>& buyerBag);
void searchFoodItemLogic(vector<FoodItem> foodItems, string searchStr);
void writeToSalesFileFromOperation(vector<BuyerBag>& buyerBag);
void listTheBagItemsForSalesReport(vector<BuyerBag>& buyerBag);
void resetTheMainPrice(double& mainPrice);
void purchaseSingleItem(string searchStr);
void purchaseForCategories();
void viewBuyerMenu();
void viewBuyerSelectionList();
void sleep();
void checkout();
void purchaseItemQuery();


#endif // OPERATION_HEADER_H_INCLUDED
