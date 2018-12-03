//
// Created by starrynight on 2018/11/25.
//

#ifndef MANUEL_PROJECT3_MASTER_SLOT_H
#define MANUEL_PROJECT3_MASTER_SLOT_H

#include "Vehicle.h"
#include <iostream>

class Slot {
public:
    explicit Slot(std::string typein);

    bool Is_empty();

    Vehicle &return_vehicle();

    std::string return_type();

    void Make_empty();

    void put_vehicle(Vehicle &temp);

private:
    Vehicle V;
    std::string type;
    bool empty;
};

#endif //MANUEL_PROJECT3_MASTER_SLOT_H
