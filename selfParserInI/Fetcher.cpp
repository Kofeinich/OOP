#include "Fetcher.h"

int Fetcher::getDataInt(const std::string& CategoryName, const std::string& FieldName){
    for (auto& i : Data[CategoryName]){
        if (i.first == FieldName){
            return std::stoi(i.second);
        }
    }
    return 0;
}

float Fetcher::getDataFloat(const std::string& CategoryName, const std::string& FieldName){
    for (auto& i : Data[CategoryName]){
        if (i.first == FieldName){
            return std::stof(i.second);
        }
    }
    return 0;
}

std::string Fetcher::getDataString(const std::string& CategoryName, const std::string& FieldName){
    for (auto& i : Data[CategoryName]){
        if (i.first == FieldName){
            return i.second;
        }
    }
    return "No such string";
}


