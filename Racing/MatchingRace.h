#ifndef RACING_MATCHINGRACE_H
#define RACING_MATCHINGRACE_H
#include <vector>
#include <float.h>
#include "Boots.h"
#include "Broom.h"
#include "Carpet.h"
#include "Spoop.h"
#include "Centaur.h"
#include "SpeedCamel.h"
#include "UsualCamel.h"

template < typename T >
class MatchingRace {
public:
    explicit MatchingRace( double raceDistance) : rDistance(raceDistance){};

    void addTransport(T* object){
        dataRace.push_back(object); // -> MatchingRace<AirTransport> race;
    }

    std::vector<T> getData(){
        return dataRace;
    }

    std::string winner(){
        std::pair<double, std::string> minTime = {DBL_MAX, ""};
        for (auto it : dataRace){
            if ( it -> timeDelation(rDistance) < minTime.first ){
                minTime.first = it -> timeDelation(rDistance);
                minTime.second = it -> getName();
            }
        }
        return minTime.second;
    }

private:
    double rDistance;
    std::vector<T*> dataRace;
};


#endif //RACING_MATCHINGRACE_H
