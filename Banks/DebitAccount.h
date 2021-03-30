#ifndef BANKS_DEBITACCOUNT_H
#define BANKS_DEBITACCOUNT_H

#endif //BANKS_DEBITACCOUNT_H
#include "Account.h"

class DebitAccount : public Account{
public:

    DebitAccount(class Client* client, double bankLimit, time_t createTime, double percent) : Account(client, bankLimit,  createTime), percent(percent){}

    double getAmount(time_t current_time) override{
        double amount = startBalance;
        time_t time = creationTime;
        int i = 0;
        int days = 0;
        double percents = 0;
        while(time <= (current_time)){
            if (transactions.size() > i) {
                if (transactions[i].first <= time+3600*24) {
                    amount += transactions[i].second;
                    i++;
                }
            }
            percents += amount*percent/100;
            days ++;
            if (days == 30){
                days = 0;
                amount += percents;
                percents = 0;
            }
            time += 3600*24;
        }
        return amount;
    };

    void withdrawMoney(double money, time_t current_time) override{
        if (Client->getReality() || money < limit){
            if (getAmount(current_time) >= money ){
                transactions.emplace_back(std::make_pair(current_time, -money));
            }
            else{
                throw std::logic_error("No money in startBalance");
            }
        }
        else{
                throw std::logic_error("Please check our account status");
        }
    }

private:
    double percent;
};