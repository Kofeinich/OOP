#include "Client.h"

void Client::setName(std::string newName) {
    name = newName;
}

std::string Client::getName() {
    return name;
}

void Client::setSurname(std::string newSurname) {
    surname = newSurname;
}

std::string Client::getSurname() {
    return surname;
}

void Client::setAddress(std::string newAddress) {
    address = newAddress;
}

std::string Client::getAddress() {
    return address;
}

void Client::setPassport(std::string newPassport) {
    passport = newPassport;
}

std::string Client::getPassport() {
    return passport;
}

bool Client::getReality() {
    return !((getPassport().empty()) || (getAddress().empty()));
}
