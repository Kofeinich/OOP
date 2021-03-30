#ifndef BANKS_ACCOUNT_H
#define BANKS_ACCOUNT_H
#include "Client.h"
#include "cmath"
#include <vector>

class Account {
public:

    Account(class Client* Client, double bankLimit, time_t creationTime) : Client(Client), limit(bankLimit), creationTime(creationTime){}

    void topUpMoney(double money, time_t current_time){
        transactions.emplace_back(std::make_pair(current_time, money));
    }

    virtual void withdrawMoney(double money, time_t current_time) = 0;

    virtual double getAmount(time_t current_time)=0;

    double getLimit(){
        return limit;
    }

    void save(){
        last_state = transactions;
    }

    void undo(){
        transactions = last_state;
        last_state.erase(last_state.begin(), last_state.end());
    }

protected:
    std::vector<std::pair<time_t, double >> transactions;
    std::vector<std::pair<time_t, double >> last_state;
    double startBalance;
    time_t creationTime;
    double limit;
    Client* Client;
};


#endif //BANKS_ACCOUNT_H
