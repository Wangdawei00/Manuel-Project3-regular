cmake_minimum_required(VERSION 3.12)
project(Manuel_Project3)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Manuel_Project3
        main.cpp
        Singleton.cpp
        Singleton.h
        Ticket.cpp
        Ticket.h
        vector.cpp
        vector.h
        Vehicle.cpp
        Vehicle.h)
#        slot.cpp
#        Floor.cpp)
