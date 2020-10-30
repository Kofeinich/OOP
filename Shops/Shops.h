#ifndef SHOPS_SHOPS_H
#define SHOPS_SHOPS_H

#include "OnlyOneShop.h"

class Shops {
public:
    Shops();

    std::map<std::string, OnlyOneShop> getAllShopAssortment();

    void addShop(const OnlyOneShop &Shop);

    void showAllShops();

    std::string cheepShop(const Product &ProductInfo);

    std::string cheepListOfShop(const std::vector <std::pair< Product &, int>> &list);

private:
    std::map<std::string, OnlyOneShop> allShops;
};


#endif //SHOPS_SHOPS_H
