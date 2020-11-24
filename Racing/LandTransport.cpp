//
// Created by fair on 08.11.2020.
//

#include "LandTransport.h"

LandTransport::LandTransport(std::string name ,double speed, double  delay, double duration_x) : AllTransport(name, speed, delay), duration(duration_x){}

double LandTransport::timeDelation( double distance){
    double currentTime = distance/getSpeed();
    double finalTime = 0;
    if (currentTime >= getDelay()) {
        finalTime = finalTime + duration;
        currentTime -= getDelay();
        if (getSpeed() == 40) {
            duration = 6.5;
        }
        if (getSpeed() == 10) {
            duration = 8;
        }
        if (getSpeed() == 6) {
            duration = 5;
        }
    }
    if ((currentTime >= getDelay()) && (duration == 6.5)) {
        finalTime = finalTime + duration;
        currentTime -= getDelay();
        duration = 8;
    }

    while (currentTime >= getDelay()) {
        finalTime += duration;
        currentTime -= getDelay();
    }

    finalTime = distance/getSpeed() + finalTime;

    return finalTime;
}