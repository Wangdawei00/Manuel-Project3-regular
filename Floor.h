//
// Created by Wangdawei on 2018/12/7.
//

#ifndef PROJECT3_FLORR_H
#define PROJECT3_FLORR_H

#include <vector>
#include "slot.h"

class Floor {
private:
    vector<vector<Slot>> slots;
    unsigned int row, column;
    string type;
    int index;
public:
    vector<Slot> &operator[](int row);

    Floor(const string &type, int index);

    vector<Vehicle> refresh();

    vector<int> findEmpty() const;

    bool isFull() const;

    int getIndex() const ;
};


#endif //PROJECT3_FLORR_H
