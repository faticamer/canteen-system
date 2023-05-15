#ifndef BAG_H_INCLUDED
#define BAG_H_INCLUDED
#include <string>
#include <vector>
#include <fstream>

struct BuyerBag
{
    std::vector<std::string> items;
    std::vector<double> individualPrices;
    double price;
};

// structures that are accessible in other files when header is included
extern BuyerBag structBuyerBag;
extern std::vector<BuyerBag> buyerBag;
extern std::ofstream sales;
extern std::ofstream inventory;

#endif // BAG_H_INCLUDED
