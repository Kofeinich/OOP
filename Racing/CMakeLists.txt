cmake_minimum_required(VERSION 3.17)
project(Racing)

set(CMAKE_CXX_STANDARD 20)

add_executable(Racing main.cpp AllTransport.cpp AllTransport.h AirTransport.cpp AirTransport.h LandTransport.cpp LandTransport.h Centaur.cpp Centaur.h Boots.cpp Boots.h UsualCamel.cpp UsualCamel.h SpeedCamel.cpp SpeedCamel.h Carpet.cpp Carpet.h Spoop.cpp Spoop.h Broom.cpp Broom.h MatchingRace.h)