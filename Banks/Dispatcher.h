#ifndef BANKS_DISPATCHER_H
#define BANKS_DISPATCHER_H


#include "Bank.h"

class Dispatcher {
private:
    std::map<std::string, Bank*> banks;

    time_t curTime = 0;

public:
    void addToTime(unsigned int value){
        curTime = curTime + value;
    }

    time_t getToTime(){
        return curTime;
    }

    void addBank(Bank* bank){
        banks.insert({bank->getName(), bank});
    }
};


#endif //BANKS_DISPATCHER_H
