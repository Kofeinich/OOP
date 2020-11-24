#include "MatchingRace.h"

int main() {
    Centaur Cent;
    Boots Boots;
    Carpet MagicCarpet;
    Broom Broom;
    Spoop Stoop;
    UsualCamel Camel;
    SpeedCamel SpeedCamel;
    std::cout << Camel.getName() << "   " <<Camel.timeDelation(1000.0) << std::endl;
    std::cout << SpeedCamel.getName() << "   " <<SpeedCamel.timeDelation(1000.0)<< std::endl;
    std::cout << Cent.getName() << "   " <<Cent.timeDelation(1000.0) << std::endl;
    std::cout << Boots.getName() << "   "<<Boots.timeDelation(1000.0)<< std::endl;
    std::cout << MagicCarpet.getName()<< "  "<< MagicCarpet.timeDelation(1000.0)<< std::endl;
    std::cout << Stoop.getName()<< "    "<< Stoop.timeDelation(1000.0) << std::endl;
    std::cout << Broom.getName() << "    "<<Broom.timeDelation(1000.0) << std::endl;

    MatchingRace<AirTransport> AirRace(1000.0);
    AirRace.addTransport(&Broom);
    AirRace.addTransport(&MagicCarpet);
    AirRace.addTransport(&Stoop);
    std::cout << "Air race winner is = " << AirRace.winner()  <<  std::endl;

    MatchingRace<LandTransport> LandRace(1000.0);
    LandRace.addTransport(&Camel);
    LandRace.addTransport(&Cent);
    LandRace.addTransport(&SpeedCamel);
    LandRace.addTransport(&Boots);
    std::cout << "Land race winner is = " << LandRace.winner() << std::endl;

    MatchingRace<AllTransport> AllRace(1000.0);
    AllRace.addTransport(&Camel);
    AllRace.addTransport(&Broom);
    AllRace.addTransport(&SpeedCamel);
    AllRace.addTransport(&MagicCarpet);
    AllRace.addTransport(&Stoop);
    AllRace.addTransport(&Cent);
    AllRace.addTransport(&Boots);
    std::cout << "All transport race winner is = " << AllRace.winner() << std::endl;
    return 0;
}
