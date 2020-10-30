#include "OnlyOneShop.h"

OnlyOneShop::OnlyOneShop() {

}

OnlyOneShop::OnlyOneShop(const std::string &nameOfShop, const std::string &addressOfShop) {
    this->shopName = nameOfShop;
    this->shopAddress = addressOfShop;
    for (int i =0; i < 5; i++) {
        shopZip = char(rand() % 21 + 0x61 ) + shopZip;
    }
}

std::string OnlyOneShop::getName() {
    return shopName;
}

std::string OnlyOneShop::getAddress(){
    return shopAddress;
}

const std::string &OnlyOneShop::getZip() const {
    return shopZip;
}

std::map<std::string, std::pair<int, int>> OnlyOneShop::getShopAssortment(){
    return stock;
}

void OnlyOneShop::addProduct(const Product &ProductInfo, int price, int amount) {
    bool flag = 1;
    for (const auto &it : stock) {
        if (ProductInfo.getProductZip() == it.first){
            flag = 0;
        }
    }
    if (flag == 1) {
        stock.insert({ProductInfo.getProductZip(), {price, amount}});
    }
    else{
        std::cout << "Please don't push this product, incorrect Zip" << std::endl;
    }
}

void OnlyOneShop::showShopProducts(){
    std::map<std::string, std::pair<int, int>> ::iterator it;
    if (!stock.empty()){
        for (it=stock.begin(); it!=stock.end(); it++){
            std::cout << it->first <<"      "<< it->second.first <<"        "<< it->second.second << '\n';
        }
    }
}

void OnlyOneShop::changeProductPrice(const Product& ProductInfo, int newPrice) {
    if (stock.count(ProductInfo.getProductZip()) == 1) {
        std::pair<int, int> value = stock.at(ProductInfo.getProductZip());
        value.first = newPrice;
        stock.erase(ProductInfo.getProductZip());
        stock.insert({ProductInfo.getProductZip(), {value.first, value.second}});
    }
    else{
        std::cout << "This product does not exist" << std:: endl;
    }
}

void OnlyOneShop::changeProductAmount(const Product &ProductInfo, int newAmount){
    if (stock.count(ProductInfo.getProductZip()) == 1) {
        std::pair<int, int> value = stock.at(ProductInfo.getProductZip());
        value.second = newAmount;
        stock.erase(ProductInfo.getProductZip());
        stock.insert({ProductInfo.getProductZip(), {value.first, value.second}});
    }
    else{
        std::cout << "This product does not exist" << std:: endl;
    }
}

std::vector <std::pair<int, std::string >> OnlyOneShop::buySomething(int sum){
    std::vector <std::pair<int, std::string >> Data;
    std::pair<int, std::string> makePair;
    if (!stock.empty()){
        for (const auto& it : stock){
            int currentPrice = it.second.first;
            int currentAmount = it.second.second;
            int otherSum = 0; int otherAmount = 0;
            while (otherSum < sum){
                otherAmount++;
                if (otherAmount <= currentAmount){
                    otherSum = currentPrice * otherAmount;
                }
            }
            if (otherSum > sum){otherAmount--;}
            makePair.first = otherAmount; makePair.second = it.first;
            Data.emplace_back(makePair);
        }
    }
    return Data;
}

int OnlyOneShop::listOfProducts(const std::vector <std::pair< Product &, int>> &list ){
    int sum = 0;
    for (auto& iter : list){

        for (const auto& it : stock){
            if (it.first == iter.first.getProductZip()){
                int currentAmount = iter.second;
                int currentPrice = it.second.first;
                if ( iter.second > it.second.second){return -1;}
                sum = (currentAmount * currentPrice) + sum;
            }
        }
    }
    return sum;
}