//
// Created by lenovo on 2018/11/28.
//

#ifndef TESTCPP_PARKINGLOT_H
#define TESTCPP_PARKINGLOT_H

#include <iostream>
#include <vector>
#include "Floor.h"

using namespace std;

class ParkingLot {
public:
    explicit ParkingLot(string fileName);

    vector<int> const &find_empty_slot(string type);

    // return floor and the location;
    void clearSlot(string const &type, int row, int column);

    void pushSlot(Vehicle &vehicle, int row, int column);

    Floor &operator[](int floorIndex);

private:

    map<string, Floor> floors;
    map<string, int> namesMap;
    vector<string> names;

};

#endif //TESTCPP_PARKINGLOT_H
