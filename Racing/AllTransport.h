//
// Created by fair on 08.11.2020.
//

#ifndef RACING_ALLTRANSPORT_H
#define RACING_ALLTRANSPORT_H
#include "string"
#include "iostream"

class AllTransport {
public:
    AllTransport() = default;

    AllTransport(std::string transportName ,double transportSpeed, double transportDelay);

    double getDelay();

    std::string getName() const;

    void setSpeed(double newSpeed);

    void setDelay(double newDelay);

    double getSpeed();

    virtual double timeDelation( double distance) = 0;

protected:
    std::string name ;

    double speed , delay ;
};


#endif //RACING_ALLTRANSPORT_H
