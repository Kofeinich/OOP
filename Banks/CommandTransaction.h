//
// Created by fair on 05.12.2020.
//

#ifndef BANKS_COMMANDTRANSACTION_H
#define BANKS_COMMANDTRANSACTION_H
#include "Command.h"

class Transaction : public Command{
public:
    Transaction(Dispatcher* dispatcher1, Bank* bank1, Bank* bank2, int account1, int account2, double a) : Command(dispatcher1, bank1, bank2),
    accountFrom(account1), accountTo(account2), amount(a), current_time(dispatcher1->getToTime()){}

    void execute() override {
        bankFrom->saveBank(); bankTo->saveBank();
        bankFrom->transaction(accountFrom, -amount, current_time);
        bankTo->transaction(accountTo, amount, current_time);
    }

private:
    int accountFrom, accountTo;
    double amount;
    time_t current_time;
};
#endif //BANKS_COMMANDTRANSACTION_H
