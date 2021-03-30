cmake_minimum_required(VERSION 3.17)
project(Banks)

set(CMAKE_CXX_STANDARD 17)

add_executable(Banks main.cpp Bank.cpp Bank.h Client.cpp Client.h Account.h DebitAccount.h CreditAccount.h DepositAccount.h Dispatcher.h Builder.h ClientBuilder.h Command.h CommandTransaction.h SaveTransaction.h UndoTransaction.h)