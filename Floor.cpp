//
// Created by starrynight on 2018/11/25.
//

#include "Floor.h"
#include <iostream>

using namespace std;

Floor::Floor(int rowIn, int columnIn, string &typeIn) {
    Slot S = Slot(typeIn);
    int i, j;
    row = rowIn;
    column = columnIn;
    vector<Slot> a;
    for (i = 0; i < column; ++i) {
        a.clear();
        a.push_back(S);
        for (j = 0; j < row; ++j) {
            slots.push_back(a);
        }
    }
}

Slot &Floor::find_empty_slot() {
//    vector<Slot> a;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            if (slots[i][j].Is_empty() == 1) {
                return slots[i][j];
            }
        }
    }
}
vector<Slot>& Floor::operator[](int row) {
    return slots[row];
}

void Floor::clear_slot(int rowIn, int columnIn) {
    slots[rowIn][columnIn].Make_empty();
}