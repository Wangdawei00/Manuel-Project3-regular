//
// Created by Wangdawei on 2018/12/7.
//

#include "slot.h"

bool Slot::isEmpty() const {
    return empty;
}

Vehicle &Slot::popVehicle() {
    empty = true;
    vehicle.depart();
    return vehicle;
}

void Slot::pushVehicle(const Vehicle &vehicle) {
    this->vehicle = vehicle;
    this->vehicle.arrive();
    empty = false;
}

Slot::Slot() {
    vehicle = Vehicle();
    empty = true;
}

Vehicle &Slot::getVehicle() {
    return vehicle;
}