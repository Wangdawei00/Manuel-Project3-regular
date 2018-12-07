//
// Created by Wangdawei on 2018/12/7.
//

#ifndef PROJECT3_SLOT_H
#define PROJECT3_SLOT_H

#include "Vehicle.h"

class Slot {
private:
    Vehicle vehicle;
    bool empty;
public:
    Slot();

    bool isEmpty() const;

    void pushVehicle(const Vehicle &vehicle);

    Vehicle &popVehicle();

    Vehicle &getVehicle();
};

#endif //PROJECT3_SLOT_H
