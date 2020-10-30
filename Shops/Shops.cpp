#include "Shops.h"

Shops::Shops() {

}

std::map<std::string, OnlyOneShop> Shops::getAllShopAssortment(){
    return allShops;
}

void Shops::addShop(const OnlyOneShop &Shop){
    allShops.insert({Shop.getZip(), Shop});
}

void Shops::showAllShops(){
    std::map<std::string, OnlyOneShop> ::iterator it;
    if (!allShops.empty()){
        for (it=allShops.begin(); it!=allShops.end(); it++){
            std::cout << it->first <<"      "<< it->second.getName() <<"        "<< it->second.getAddress() << '\n';
        }
    }
}

std::string Shops::cheepShop(const Product &ProductInfo){
    long long lowerPrice = INT64_MAX;
    std::string cheepShopStr;
    if (!allShops.empty()){
        for (const auto& it : allShops){
            OnlyOneShop OneShop = it.second;
            for (const auto& iter : OneShop.getShopAssortment()){
                if((iter.first == ProductInfo.getProductZip()) && (iter.second.first <= lowerPrice)){
                        lowerPrice = iter.second.first;
                        cheepShopStr = OneShop.getName();
                }
            }
        }
    }
    return cheepShopStr;
}

std::string Shops::cheepListOfShop(const std::vector <std::pair< Product &, int>> &list) {
    std::vector <std::pair<std::string, int>> data;
    for (const auto &it : allShops) {
        int bestShopValue = 0;
        OnlyOneShop OneShop = it.second;
        for (const auto &iter : list) {
            Product ProductInfo = iter.first; bool bAmount = 0;
            for (const auto &item : OneShop.getShopAssortment()) {
                if ((item.first == ProductInfo.getProductZip()) && (item.second.second >= iter.second)) {
                    bAmount = 1;
                    bestShopValue = (iter.second * item.second.first) + bestShopValue;
                }
            }
            if (bAmount == 0){break;}
        }
        std::pair<std::string, int> makePair;
        makePair.first = it.first;
        makePair.second = bestShopValue;
        data.emplace_back(makePair);
    }
    long long lowerPrice = INT64_MAX; std::string topShopStr = "";
    for (const auto& it : data){
        if (it.second < lowerPrice ){
            lowerPrice = it.second;
            topShopStr = it.first;
        }
    }
    return topShopStr;
}
