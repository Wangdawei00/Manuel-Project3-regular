//
// Created by Wangdawei on 2018/12/7.
//

#ifndef PROJECT3_PARKINGLOT_H
#define PROJECT3_PARKINGLOT_H

#include "Floor.h"

class ParkingLot {
private:
    map<string, Floor> floors;
public:
    explicit ParkingLot(const string &fileName);

    vector<Vehicle> refreshOut();

    void refreshIn();

};

#endif //PROJECT3_PARKINGLOT_H
