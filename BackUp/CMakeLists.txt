cmake_minimum_required(VERSION 3.17)
project(BackUp)

set(CMAKE_CXX_STANDARD 17)

add_executable(BackUp main.cpp File.h BackUp.cpp BackUp.h RestorePoint.h IncPoint.h FullPoint.h CreationStrategy.h StorageStrategy.h)