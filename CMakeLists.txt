cmake_minimum_required(VERSION 3.12)
project(project3_regular)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(project3_regular
        Floor.cpp
        Floor.h
#        main.cpp
        parkingLot.cpp
        parkingLot.h
        slot.cpp
        slot.h
        Ticket.cpp
        Ticket.h
        Vehicle.cpp
        Vehicle.h merge.cpp)
