//
// Created by fair on 05.12.2020.
//

#ifndef BANKS_BUILDER_H
#define BANKS_BUILDER_H

class Builder{
public:
    virtual ~Builder(){}

    virtual void ClientPartA(std::string name, std::string surname) = 0;

    virtual void ClientPartB(std::string address, std::string passport) = 0;

};

#endif //BANKS_BUILDER_H
