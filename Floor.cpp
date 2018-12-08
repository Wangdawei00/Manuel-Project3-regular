//
// Created by Wangdawei on 2018/12/7.
//

#include "Floor.h"
#include <ctime>
#include <random>
#include "Ticket.h"
#include <iostream>
#include <vector>

Floor::Floor(const string &type, int index) {
//    cout << "A floor is created.\n";
    this->type = type;
//    std::mt19937 mt((unsigned int) time(nullptr));
//    std::uniform_int_distribution<unsigned int> dist(1, 10);
//    column = dist(mt);
//    row = dist(mt);
//    column = row = 5;
    row = (unsigned int) rand() % 8 + 1;
    column = (unsigned int) rand() % 8 + 1;
//    Slot newSlot;
//    vector<Slot> slotRow(column, newSlot);
//    for (int i = 0; i < row; ++i) {
//        slots.push_back(slotRow);
//    }
    vector<vector<Slot>> temp(row, vector<Slot>(column, Slot()));
    slots = temp;
    this->index = index;

}

vector<Slot> &Floor::operator[](int row) {
    return slots[row];
}

vector<Vehicle> Floor::refresh() {
    vector<Vehicle> vehicles;
//    std::mt19937 mt((unsigned int) time(nullptr));
//    std::uniform_int_distribution<unsigned int> dist(1, 10);
    for (auto &vec:slots)
        for (auto &slot:vec) {
            if (!slot.isEmpty() && rand() % 10 <= 5) {
                vehicles.push_back(slot.popVehicle());
            }
        }
    return vehicles;
}

vector<int> Floor::findEmpty() const {
    if (!isFull())
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < column; j++) {
                if (slots[i][j].isEmpty()) {//if there exists an empty slot
                    //                return a[i][j];
                    vector<int> ret(2, 0);//generate a vector containing 2 integers
                    ret[0] = i;
                    ret[1] = j;
                    return ret;
                }
            }
        }
    return vector<int>(2, -1);
}

bool Floor::isFull() const {
    for (auto const &slotRow:slots) {
        for (auto const &slot:slotRow) {
            if (slot.isEmpty())
                return false;
        }
    }
    return true;
}

int Floor::getIndex() const {
    return index;
}
