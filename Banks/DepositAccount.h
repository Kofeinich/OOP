#ifndef BANKS_DEPOSITACCOUNT_H
#define BANKS_DEPOSITACCOUNT_H

#include "Account.h"
#include <ctime>

class DepositAccount : public Account{
public:

    double getAmount(time_t current_time) override{
        double amount = startBalance;
        for (auto transaction : transactions){
            amount += transaction.second;
        }
        return amount;
    };

    DepositAccount(class Client* client, double bankLimit, time_t createTime, time_t frozenTime) : Account(client, bankLimit,  createTime), delta(frozenTime){}

    void withdrawMoney(double money, time_t current_time) override{
        if (Client->getReality() || money < limit) {
                if (delta > (currentTime - createTime)) {
                    if (getAmount(current_time) >= money) {
                        transactions.emplace_back(std::make_pair(current_time, -money));
                    } else {
                        throw std::logic_error("No money in startBalance");
                    }
                } else {
                    throw std::logic_error("Your account is frozen");
                }
            }
        else{
            throw std::logic_error("Please check your account status");
        }
    }

private:
    time_t createTime, currentTime, delta;
};

#endif //BANKS_DEPOSITACCOUNT_H