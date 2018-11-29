//
// Created by starrynight on 2018/11/25.
//

#include "Floor.h"
#include <iostream>

using namespace std;

Floor::Floor(int rowIn, int columnIn, string typeIn) {
    Slot S = Slot(std::move(typeIn));
    int i, j;
    row = rowIn;
    column = columnIn;
    vector<Slot> a;
    for (i = 0; i < column; ++i) {
        a.push_back(S);
        for (j = 0; j < row; ++j) {
            slots.push_back(a);
        }
    }
}

vector<int> &Floor::find_empty_slot() {
//    int (*empty)[2];
    for (int i = 0; i < row; i++) {
        vector<Slot> a = slots[i];
        for (int j = 0; j < column; j++) {
            if (a[j].Is_empty() == 1) {
//                return a[i][j];
                static vector<int> ret(2, 0);
                ret[0] = i;
                ret[1] = j;
                return ret;
            }
        }
    }
    static vector<int> b = vector<int>(2, -1);
    return b;
}


void Floor::clear_slot(int rowIn, int columnIn) {
    vector<Slot> a = slots[rowIn];
    a[columnIn].Make_empty();
}

vector<Slot> &Floor::operator[](int a) {
    return slots[a];
}