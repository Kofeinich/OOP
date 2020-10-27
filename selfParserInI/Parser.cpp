#include "Parser.h"
#include <regex>
using namespace std;

Parser::Parser(){
    filepath = "";
}

void Parser::setFile(const std::string& fp){
    this->filepath = fp;
    file.open(this->filepath);
    if (file.is_open()) {
        std::string Buffer;
        std::string CurrentHeader;

        std::regex HeaderRegular("(\\[)"
                                 "([\\w]+)"
                                 "(\\])");


        std::regex FieldRegular("([\\w]+)" // Имя параметра
                                          "[\\s]??" // Возможно пробел
                                          "[=]{1}" // =
                                          "[\\s]??" // Возможно пробел
                                          "([\\w.\\/]+)" // Значение
                                          "[\\s;]??" // Пробел или ;
                                          ".*?" // Комментарий
                                          );

        while (!file.eof()){
            std::getline(file, Buffer, '\n');
            if (Buffer[Buffer.size()-1]=='\r'){
                Buffer = Buffer.erase(Buffer.size()-1);
            }
            std::smatch result;

            if (std::regex_match(Buffer, result, HeaderRegular)){
                CurrentHeader = result[2];
                Data.insert({CurrentHeader, map<string, string>()});
            }
            else{
                if (std::regex_match(Buffer, result, FieldRegular)) {
                    if (!(CurrentHeader.empty())) {
                        Data[CurrentHeader].insert({result[1].str(), result[2].str()});
                    }
                    else{
                        throw std::logic_error("Incorrect Format File!" );
                    }
                }
            }
        }
    }
    else{
        throw std::logic_error("File does not open");
    }
}

std::map<std::string, std::map<std::string, std::string>> Parser::getData(){
    return Data;
}

