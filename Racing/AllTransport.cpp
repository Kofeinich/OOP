//
// Created by fair on 08.11.2020.
//

#include "AllTransport.h"

AllTransport::AllTransport(std::string transportName ,double transportSpeed, double transportDelay) : name(transportName), speed(transportSpeed), delay(transportDelay) {}

double AllTransport::getDelay() {
    return delay;
}

double AllTransport::getSpeed() {
    return speed;
}

std::string AllTransport::getName() const {
    return name;
}

void AllTransport::setSpeed(double newSpeed){
    speed = newSpeed;
}

void AllTransport::setDelay(double newDelay) {
    delay = newDelay;
}
