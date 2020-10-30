#include "Shops.h"

int main() {
    Product Product_1("pork");
    Product Product_2("cheese");
    Product Product_3("tomato");
    OnlyOneShop Shop_1("Magnit", "St.Petersburg, Pushkina, 145");
    OnlyOneShop Shop_2("Lenta", "St.Petersburg, Lomomosova, 8");
    Shop_1.addProduct(Product_1, 180, 10);
    Shop_1.addProduct(Product_2, 560, 4);
    Shop_1.addProduct(Product_3, 90, 183);
    Shop_1.changeProductPrice(Product_1, 175);  // changing price
    Shop_1.changeProductAmount(Product_1, 8); // changing amount
    Shop_2.addProduct(Product_1, 160, 13);
    Shop_2.addProduct(Product_2, 590, 8);
    Shop_2.addProduct(Product_3, 87, 432);
    Shops Shopping;
    Shopping.addShop(Shop_1); Shopping.addShop(Shop_2);
    Shopping.showAllShops();
    std::cout << "\n" << std::endl;
    Shop_1.showShopProducts();
    std::cout << "\n" << std::endl;
    Shop_2.showShopProducts();


    //Task4
    std::cout << "\n" << std::endl;
    std::cout << "Cheapest shop for that product :  "<< Shopping.cheepShop(Product_2) << std::endl; std::cout << "\n" << std::endl;

    //Task5
    std::vector <std::pair<int, std::string >> result = Shop_2.buySomething(300);
    for (const auto& it : result){
        std::cout << it.first <<"   " << it.second << std::endl;
    }
    std::cout << "\n" << std::endl;

    //Task6
    std::vector <std::pair< Product &, int>> productList;
    productList.push_back({Product_1, 1});
    productList.push_back({Product_2, 4});
    productList.push_back({Product_3, 1});
    std::cout << "All price of list in Magnit is : "<< Shop_1.listOfProducts(productList) << std::endl;
    std::cout << "All price of list in Lenta is : "<< Shop_2.listOfProducts(productList) << std::endl;
    std::cout << "\n" << std::endl;

    //Task7
    std::cout << Shopping.cheepListOfShop(productList) << std::endl;
}
