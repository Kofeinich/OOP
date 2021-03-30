//
// Created by fair on 05.12.2020.
//

#ifndef BANKS_COMMAND_H
#define BANKS_COMMAND_H
#include "Dispatcher.h"
#include "Bank.h"

class Command {
public:
    virtual ~Command() {};

    virtual void execute()  = 0;

protected:
    Dispatcher* dispatcher; Bank* bankFrom; Bank* bankTo;
    Command(Dispatcher* dispatcherS, Bank* bank1, Bank* bank2) : dispatcher(dispatcherS), bankFrom(bank1), bankTo(bank2) {};
};
#endif //BANKS_COMMAND_H
