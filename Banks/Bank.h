#ifndef BANKS_BANK_H
#define BANKS_BANK_H
#include "Account.h"
#include <map>

class Bank {
public:
    explicit Bank(std::string& bankName): bankName(bankName){}

    void transaction(int accountId, double amount, time_t current_time);

    std::string getName();

    void addAccount(int id, Account* account);

    void saveBank();

    void getHistory();

private:
    std::string bankName;
    std::map<int, Account*> accounts;
};


#endif //BANKS_BANK_H
