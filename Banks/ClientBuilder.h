//
// Created by fair on 05.12.2020.
//

#ifndef BANKS_CLIENTBUILDER_H
#define BANKS_CLIENTBUILDER_H
#include "Builder.h"
#include "Client.h"

class ClientBuilder : public Builder{
private:
    Client* client;
public:
    void Reset(){
        this->client= new Client();
    }

    void ClientPartA(std::string name, std::string surname) override{
        Reset();
        this->client->setName(name);
        this->client->setSurname(surname);
    }

    void ClientPartB(std::string address, std::string passport) override{
        Reset();
        this->client->setAddress(address);
        this->client->setPassport(passport);
    }

    Client* getClient(){
        Client* result= this->client;
        this->Reset();
        return result;
    }

};
#endif //BANKS_CLIENTBUILDER_H
