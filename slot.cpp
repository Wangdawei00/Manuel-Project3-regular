//
// Created by starrynight on 2018/11/25.
//

#include "slot.h"
#include "Vehicle.h"

Slot::Slot(std::string typein) {
    type = std::move(typein);
    empty = true;
}

bool Slot::Is_empty() {
    return empty;
}

Vehicle &Slot::return_vehicle() {
    return V;
}

std::string Slot::return_type() {
    return type;
}

void Slot::Make_empty() {
    empty = true;
}

void Slot::put_vehicle(Vehicle &temp) {
    V = temp;
    empty = false;
}