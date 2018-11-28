//
// Created by starrynight on 2018/11/25.
//

#include "slot.h"
#include "Vehicle.h"

Slot::Slot(std::string typein, Vehicle *temp) {
    type = std::move(typein);
    V = temp;
}

Slot::Slot(std::string typein) {
    type = std::move(typein);
    V = nullptr;
}

int Slot::Is_empty() {
    if (V == nullptr) empty = 1;
    else empty = 0;
    return empty;
}

Vehicle &Slot::return_vehicle() {
    if (V != nullptr) {
        return *V;
    }
}

std::string Slot::return_type() {
    return type;
}

void Slot::Make_empty() {
    if (V != nullptr) {
        V = nullptr;
    }
}