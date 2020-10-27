#include <iostream>
#include "Parser.h"
#include "Fetcher.h"

int main() {
    try {
        Parser MyParser;
        MyParser.setFile("example.ini");
        Fetcher Fetch(MyParser.getData());
        std::cout << Fetch.getDataString("ADC_DEV", "Driver") << std::endl;
        std::cout << Fetch.getDataFloat("COMMON", "StatisterTimers") << std::endl;
        return 0;
    }
    catch(std::logic_error &e){
        std::cout << e.what();
    }
}
