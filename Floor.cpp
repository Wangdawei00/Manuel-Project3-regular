//
// Created by starrynight on 2018/11/25.
//

#include "Floor.h"
#include <iostream>

using namespace std;

Floor::Floor(int rowIn, int columnIn, string typeIn,int index) {//generate a new floor according to the rowIn,columnIn and typeIn
    Slot S = Slot(std::move(typeIn));//generate a new slot(a type defined in "slot.h") with the type of "typeIn"
    int i, j;
    row = rowIn;
    column = columnIn;
    vector<Slot> a;//generate a vector of Slot(a type defined in "slot.h")
    for (i = 0; i < column; ++i) {
        a.push_back(S);//add new element(a new slot "S")to the end of the vector "a"
    }
    this->index=index;
    for (j = 0; j < row; ++j) {
        slots.push_back(a);//add "a"to the end of the whole slots
    }
}

vector<int> const &Floor::find_empty_slot() {
//    int (*empty)[2];
    for (int i = 0; i < row; i++) {
        vector<Slot> a = slots[i];//take out the "i" row of the whole "slots"
        for (int j = 0; j < column; j++) {
            if (a[j].Is_empty() == 1) {//if there exists an empty slot
//                return a[i][j];
                static vector<int> ret(2, 0);//generate a vector containing 2 integers
                ret[0] = i;
                ret[1] = j;
                return ret;
            }
        }
    }
    static const vector<int> b = vector<int>(2, -1);//otherwise return (-1,-1) to indicate no empty slot
    return b;
}


void Floor::clear_slot(int rowIn, int columnIn) {
    vector<Slot> a = slots[rowIn];//set "a" to be a single row(row number:rowIn) from "slots"
    a[columnIn].Make_empty();//set the "columnIn" slot to be empty
}

vector<Slot> &Floor::operator[](int a) {
    return slots[a];//return a single row "a" from "slots"
}