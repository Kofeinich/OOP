//
// Created by fair on 08.11.2020.
//

#ifndef RACING_AIRTRANSPORT_H
#define RACING_AIRTRANSPORT_H
#include "AllTransport.h"

class AirTransport : public AllTransport{
public:
    AirTransport() = default;

    AirTransport(std::string name ,double speed, double delay);

    double timeDelation(double distance);
};


#endif //RACING_AIRTRANSPORT_H
