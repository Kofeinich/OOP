#ifndef SELFPARSERINI_FETCHER_H
#define SELFPARSERINI_FETCHER_H
#include <map>
#include <vector>
#include <string>


class Fetcher{
public:
    Fetcher() = default;
    ~Fetcher() = default;
    explicit Fetcher(const std::map<std::string, std::map<std::string, std::string>>& Data) { this->Data = Data; };
    int getDataInt(const std::string& CategoryName, const std::string& FieldName);
    float getDataFloat(const std::string& CategoryName, const std::string& FieldName);
    std::string getDataString(const std::string& CategoryName, const std::string& FieldName);
private:
    std::map< std::string, std::map<std::string, std::string>> Data;
};
#endif //SELFPARSERINI_FETCHER_H
