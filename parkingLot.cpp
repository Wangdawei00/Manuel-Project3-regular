//
// Created by lenovo on 2018/11/28.
//
#include "Floor.h"
#include "parkingLot.h"
#include <string>
#include <cstdlib>
#include <vector>

using namespace std;

ParkingLot::ParkingLot() {
    namesMap.insert(make_pair("Car", 0));
    namesMap.insert(make_pair("Van", 1));
    namesMap.insert(make_pair("Bicycle", 2));
    namesMap.insert(make_pair("Motorbike", 3));
    names[0] = "Car";
    names[1] = "Van";
    names[2] = "Bicycle";
    names[3] = "Motorbike";
    for (int i = 0; i < 4; ++i) {
        floors.insert(make_pair(names[i], Floor(rand() % 2 + 5, rand() % 2 + 5, names[i], i)));
    }
//    floors.insert(make_pair("Car",Floor()));
//    floors.insert(make_pair("Van",1));
//    floors.insert(make_pair("Bicycle",2));
//    floors.insert(make_pair("Motorbike",3));
//    int i;
//    for (i = 0; i < 4; i++) {
//        floors[i] = Floor();
//    }
}

vector<int> &ParkingLot::find_empty_slot(string type) {
    int i;
    //map<string,int> floorMap;
    Floor &f = floors.find(type)->second;;//!!! 我觉得是不是要加入vehicle的变量，让vehicle存进去？？
    static vector<int> result(3, 0);
    result = f.find_empty_slot();
    result.push_back(namesMap.find(type)->second);
    return result;
}

void ParkingLot::clearSlot(int floor, int row, int column) {
    floors.find(names[floor])->second.clear_slot(row, column);
}