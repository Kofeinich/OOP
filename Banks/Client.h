#ifndef BANKS_CLIENT_H
#define BANKS_CLIENT_H
#include <string>
#include <iostream>

class Client {
public:

    void setName(std::string newName);

    std::string getName();

    void setSurname(std::string newSurname);

    std::string getSurname();

    void setAddress(std::string newAddress);

    std::string getAddress();

    void setPassport(std::string newPassport);

    std::string getPassport();

    bool getReality();

    Client* client;

private:
    std::string name, surname, address, passport;
    bool reliability;
};


#endif //BANKS_CLIENT_H
