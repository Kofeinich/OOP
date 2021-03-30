#ifndef BANKS_CREDITACCOUNT_H
#define BANKS_CREDITACCOUNT_H
#include "Account.h"

class CreditAccount : public Account{
public:

    double getAmount( time_t current_time) override{
        double amount = startBalance;
        time_t time = creationTime;
        int i = 0;
        while(time < current_time){
            if (transactions.size() > i) {
                if (transactions[i].first < time) {
                    amount += transactions[i].second;
                    i++;
                }
            }
            if(amount<0){
                amount -= comission;
            }
            time += 3600*24;
        }
        return amount;
    };

    CreditAccount(class Client* client, double bankLimit, time_t creation_time,double newCreditLimit, double comission) : Account(client, bankLimit, creation_time), creditLimit(newCreditLimit), comission(comission){}

    double getCreditLimit(){
        return creditLimit;
    };

    void withdrawMoney(double money, time_t current_time) override {
        if (Client->getReality() || money < limit) {
            if (getAmount(current_time) -money >= -creditLimit){
                transactions.emplace_back(std::make_pair(current_time, -money));
            }
            else{
                throw std::logic_error("Dont allowed, check your CreditLimit");
            }
        }
        else{
            throw std::logic_error("Please check your account status");
        }
    }

private:
    double creditLimit, comission;
};
#endif //BANKS_CREDITACCOUNT_H
