#include "Bank.h"

void Bank::transaction(int accountId, double amount, time_t current_time) {
    if (amount>=0){
        accounts[accountId]->topUpMoney(amount, current_time);
    } else{
        accounts[accountId]->withdrawMoney(-amount, current_time);
    }
}

std::string Bank::getName() {
    return bankName;
}

void Bank::addAccount(int id, Account *account) {
    accounts.insert({id, account});
}

void Bank::saveBank() {
    for (auto i : accounts){
        i.second->save();
    }
}

void Bank::getHistory() {
//    return bankHistory;
    for (auto i : accounts){
        i.second->undo();
    }
}