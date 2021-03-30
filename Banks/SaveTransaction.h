//
// Created by fair on 05.12.2020.
//

#ifndef BANKS_SAVETRANSACTION_H
#define BANKS_SAVETRANSACTION_H
#include "Command.h"

class SaveTransaction : public Command{
public:
    SaveTransaction(Dispatcher* dispatcher1, Bank* bank1, Bank* bank2)  : Command(dispatcher1, bank1, bank2){}

    void execute() override{
        bankFrom->saveBank();
        bankTo->saveBank();
    }

};

#endif //BANKS_SAVETRANSACTION_H
