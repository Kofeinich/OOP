#include "Product.h"

Product::Product() {

}

Product::Product(const std::string &nameOfProduct) {
    this->productName = nameOfProduct;
    for (int i =0; i < 5; i++) {
        productZip = char(rand() % 26 + 0x61 ) + productZip;
    }
}

std::string Product::getProductZip() const {
    return productZip;
}

