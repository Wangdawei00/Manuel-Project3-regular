//
// Created by starrynight on 2018/11/25.
//

#ifndef MANUEL_PROJECT3_MASTER_FLOOR_H
#define MANUEL_PROJECT3_MASTER_FLOOR_H

#include <iostream>
#include "slot.h"
#include <vector>
using namespace std;
class Floor {
public:
    Floor(int row,int column,string typeIn,int index);

    vector<int> const &find_empty_slot();
    void clear_slot(int rowIn,int columnIn);
    vector<Slot> &operator[](int a);
private:
    int row,column;
    vector<vector<Slot>> slots;
    std::string type;
    int index;
};

#endif //MANUEL_PROJECT3_MASTER_FLOOR_H
