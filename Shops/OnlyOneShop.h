#ifndef SHOPS_ONLYONESHOP_H
#define SHOPS_ONLYONESHOP_H

#include "map"
#include "vector"
#include "Product.h"

class OnlyOneShop {
public:
    OnlyOneShop();

    OnlyOneShop(const std::string &nameOfShop, const std::string &addressOfShop);

    std::string getName();

    std::string getAddress();

    [[nodiscard]] const std::string &getZip() const;

    void addProduct(const Product &ProductInfo, int price, int amount);

    void changeProductPrice(const Product &ProductInfo, int newPrice);

    void changeProductAmount(const Product &ProductInfo, int newAmount);

    void showShopProducts();

    std::vector <std::pair<int, std::string>> buySomething(int sum);

    int listOfProducts(const std::vector <std::pair< Product &, int>> &list );

    std::map<std::string, std::pair<int, int>> getShopAssortment();

private:
    std::string shopName;
    std::string shopAddress;
    std::string shopZip;
    std::map<std::string, std::pair<int, int>> stock;
};


#endif //SHOPS_ONLYONESHOP_H
