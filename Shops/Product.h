#ifndef SHOPS_PRODUCT_H
#define SHOPS_PRODUCT_H
#include <iostream>
#include "string"

class Product {
public:
    Product();

    Product(const std::string &nameOfProduct);

    [[nodiscard]] std::string getProductZip() const;

private:
    std::string productName;
    std::string productZip;
};

#endif //SHOPS_PRODUCT_H
