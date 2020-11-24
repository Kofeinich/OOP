//
// Created by fair on 08.11.2020.
//

#ifndef RACING_LANDTRANSPORT_H
#define RACING_LANDTRANSPORT_H
#include "AllTransport.h"

class LandTransport : public AllTransport {
public:
    LandTransport() = default;
    LandTransport(std::string name ,double speed, double  delay, double duration_x);
    double timeDelation( double distance);

protected:
    double duration;
};


#endif //RACING_LANDTRANSPORT_H
