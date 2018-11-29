cmake_minimum_required(VERSION 3.12)
project(testcpp)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(testcpp
        Floor.cpp
        Floor.h
        main.cpp
        parkingLot.cpp
        parkingLot.h
        Singleton.cpp
        Singleton.h
        slot.cpp
        slot.h
        Ticket.cpp
        Ticket.h
        vector.cpp
        vector.h
        Vehicle.cpp
        Vehicle.h)
