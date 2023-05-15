#ifndef FOOD_ITEM_H_INCLUDED
#define FOOD_ITEM_H_INCLUDED
#include <string>
#include <vector> // for dynamically allocated arrays.

struct FoodItem {
    std::string name;
    std::string category;
    std::vector<std::string> mCategory;
    std::vector<std::string> vCategory;
    std::vector<std::string> dCategory;
    int quantity;
    double price;
};

extern std::vector<FoodItem> foodItems;
// extern std::ofstream inventory("canteen_reports/inventory.txt", std::ios_base::app);
// extern std::ofstream sales("canteen_reports/sales.txt", std::ios_base::app);

#endif // FOOD_ITEM_H_INCLUDED
