//
// Created by starrynight on 2018/11/25.
//

#include "slot.h"
#include "Vehicle.h"

Slot::Slot(std::string typein) {
    type = std::move(typein);//set the type of the slot
    empty = true;//make this slot be empty
}

bool Slot::Is_empty() const {
    return empty;
}

Vehicle &Slot::return_vehicle() {
    return V;
}

std::string Slot::return_type() {
    return type;
}

void Slot::Make_empty() {
    V.depart();
    empty = true;
}

void Slot::put_vehicle(Vehicle &temp) {
    V = temp;//set the V to be the vehicle "temp"
    V.arrive();
    empty = false;
}