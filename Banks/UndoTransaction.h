//
// Created by fair on 05.12.2020.
//

#ifndef BANKS_UNDOTRANSACTION_H
#define BANKS_UNDOTRANSACTION_H
#include "Command.h"

class UndoTransaction : public Command{
public:
    UndoTransaction(Dispatcher* dispatcher1, Bank* bank1, Bank* bank2) :  Command(dispatcher1, bank1, bank2){}

    void execute() override {
       bankTo->getHistory();
       bankFrom->getHistory();
    }

};

#endif //BANKS_UNDOTRANSACTION_H
