#include <iostream>
#include "ClientBuilder.h"
#include "SaveTransaction.h"
#include "CommandTransaction.h"
#include "UndoTransaction.h"
#include "Dispatcher.h"
#include "DebitAccount.h"
#include "CreditAccount.h"
#include "DepositAccount.h"

//command, builder

int main() {
    try {
        Dispatcher dispatcher;
        std::string bankName1 = "SBERBANK";
        Bank bank1(bankName1);
        std::string bankName2 = "TINKOFF";
        Bank bank2(bankName2);
        dispatcher.addBank(&bank1);
        dispatcher.addBank(&bank2);
        ClientBuilder clientBuilder1; clientBuilder1.ClientPartA("Fedor", "Konyukhov");
        clientBuilder1.ClientPartB("Puskina", "123654");
        ClientBuilder clientBuilder2; clientBuilder2.ClientPartA("Y", "Yankov");
        clientBuilder2.ClientPartB("OVRAG", "8906");


        DebitAccount account1(clientBuilder1.getClient(), 10000, 0, 0.01);
        CreditAccount account2(clientBuilder1.getClient(), 10000, 0, 10000, 100);
        DepositAccount account3(clientBuilder1.getClient(), 10000, 0, 3600 * 24 * 100);

        DebitAccount account4(clientBuilder2.getClient(), 10000, 0, 1);
        CreditAccount account5(clientBuilder2.getClient(), 10000, 0, 10000, 100);
        DepositAccount account6(clientBuilder2.getClient(), 10000, 0, 3600 * 24 * 30);

        bank1.addAccount(1, &account1);
        bank2.addAccount(2, &account2);
        bank1.addAccount(3, &account3);
        bank2.addAccount(4, &account4);
        bank1.addAccount(5, &account5);
        bank2.addAccount(6, &account6);

        account1.topUpMoney(1000, dispatcher.getToTime());
        dispatcher.addToTime(100000);

        std::cout << "Balance in 1 (debit) account = " <<account1.getAmount(dispatcher.getToTime()) << std::endl;

        account1.topUpMoney(100, dispatcher.getToTime());
        account1.withdrawMoney(500,dispatcher.getToTime());
        dispatcher.addToTime(200000);

        std::cout << "Balance in 1 (debit) account = " <<account1.getAmount(dispatcher.getToTime()) << std::endl;

        account2.topUpMoney(1500, dispatcher.getToTime());
        dispatcher.addToTime(300000);
        account2.topUpMoney(1200, dispatcher.getToTime());
        dispatcher.addToTime(400000);

        std::cout << "Balance in 2 (credit) account = " << account2.getAmount(dispatcher.getToTime()) << std::endl;

        account2.withdrawMoney(5000, dispatcher.getToTime());
        dispatcher.addToTime(500000);

        std::cout << "Balance in 2 (credit) account = " << account2.getAmount(dispatcher.getToTime()) << std::endl;

        account3.topUpMoney(1300, dispatcher.getToTime());
        account3.topUpMoney(10000, dispatcher.getToTime());
        dispatcher.addToTime(600000);

        std::cout << "Balance in 3 (deposit) account = " << account3.getAmount(dispatcher.getToTime()) << std::endl;

        account3.topUpMoney(1300, dispatcher.getToTime());
        dispatcher.addToTime(700000);

        std::cout << "Balance in 3 (deposit) account = " << account3.getAmount(dispatcher.getToTime()) << std::endl << std::endl;

        dispatcher.addToTime(700000);
        account4.topUpMoney(35000, dispatcher.getToTime());
        dispatcher.addToTime(800000);
        account5.topUpMoney(120000, dispatcher.getToTime());
        dispatcher.addToTime(900000);
        account6.topUpMoney(17000, dispatcher.getToTime());
        dispatcher.addToTime(1000000);

        std::cout << "Balance in 4 (debit) account = " <<account4.getAmount(dispatcher.getToTime()) << std::endl;
        std::cout << "Balance in 5 (credit) account = "<< account5.getAmount(dispatcher.getToTime()) << std::endl;
        std::cout << "Balance in 6 (deposit) account = "<< account6.getAmount(dispatcher.getToTime()) << std::endl << std::endl;

        account4.withdrawMoney(15000, dispatcher.getToTime());
        account1.topUpMoney(10000, dispatcher.getToTime());
        dispatcher.addToTime(1100000);

        std::cout << "Balance in 1 after pushing money = " <<account1.getAmount(dispatcher.getToTime()) << std::endl;
        std::cout << "Balance in 4 before refund = " << account4.getAmount(dispatcher.getToTime()) << std::endl << std::endl;

        std::vector<Command*> historyOff;
        historyOff.emplace_back(new Transaction(&dispatcher, &bank1, &bank2, 1, 4, 400));
        //historyOff.emplace_back(new Transaction(&dispatcher, &bank1, &bank2, 1, 4, 1000));
        historyOff.emplace_back(new UndoTransaction(&dispatcher, &bank1, &bank2));
        for (auto  i : historyOff) {
            i->execute();
        }

        std::cout << "Balance in 1  account after withDrawMoney = " <<account1.getAmount(dispatcher.getToTime()) << std::endl;
        std::cout << "Balance in 4 after refund = " << account4.getAmount(dispatcher.getToTime()) << std::endl << std::endl;

        for (auto  i : historyOff) {
            delete i;
        }
    }
    catch (std::logic_error& e) {
        std::cout << e.what() << std::endl;
    }

}
