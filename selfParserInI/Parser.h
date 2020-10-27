//
// Created by fair on 27.10.2020.
//

#ifndef SELFPARSERINI_PARSER_H
#define SELFPARSERINI_PARSER_H
#include <string>
#include <fstream>
#include <map>
#include "Fetcher.h"

class Parser{
public:
    Parser();
    void setFile(const std::string& fp);
    std::map< std::string, std::map< std::string, std::string>> getData();
private:
    std::string filepath;
    std::ifstream file;
    std::map< std::string, std::map< std::string, std::string>> Data;
};
#endif //SELFPARSERINI_PARSER_H
