//
// Created by fair on 08.11.2020.
//

#include "AirTransport.h"

AirTransport::AirTransport(std::string name, double speed, double delay) : AllTransport(name,speed,delay){}

double AirTransport::timeDelation(double distance) {
    if (getSpeed() == 10){
        double finalDistance = distance;
        if (distance >= 1000.0 && distance <= 5000.0)
            delay = 3;
        else if (distance >= 5000.0 && distance <= 10000.0)
            delay = 10;
        else if (distance >= 10000.0)
            delay = 5;
        finalDistance = distance * (100.0 - delay) / 100.0;
        double finalTime = finalDistance/getSpeed();
        return finalTime;
    }
    if (getSpeed() == 8){
        double finalDistance = distance;
        finalDistance = distance * (100 - delay) / 100.0;
        double finalTime = finalDistance/getSpeed();
        return finalTime;
    }
    if (getSpeed() == 20){
        double finalDistance = distance;
        while (finalDistance > 0.0){
            if (finalDistance >= 1000.0) {
                finalDistance -= 1000.0;
                delay++;
            }
            finalDistance -= 1000.0;
        }
        double finalTime = (((100.0 - delay) / 100.0 ) * distance)/getSpeed();
        return finalTime;
    }
}
