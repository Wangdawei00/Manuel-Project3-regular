//
// Created by lenovo on 2018/11/28.
//
#include "parkingLot.h"
#include <fstream>
#include <random>
#include <map>

using namespace std;


ParkingLot::ParkingLot(string fileName) {//take the filename as an input
    ifstream in;
    in.open(fileName, ios::in);
    if (in.is_open()) {
        string temp;
        for (int j = 0; in >> temp; ++j) {
            names.push_back(temp);
            namesMap.insert(make_pair(names[j], j));//use make_pair to regard name and its ID as a whole part
        }
        in.close();
    } else {
        for (int i = 0; i < numOfVehicleDefault; ++i) {
            names.emplace_back(vehicleNames[i]);
            namesMap.insert(make_pair(names[i], i));
        }
    }
    random_device randomDevice;
    for (int i = 0; i < names.size(); ++i) {
        floors.insert(make_pair(names[i], Floor(randomDevice() % 2 + 5, randomDevice() % 2 + 5, names[i], i)));
    }//generate "floors":each floor has its name, as well as a "floor" which contains its size and type
}


vector<int> const &ParkingLot::find_empty_slot(string type) {
    Floor &floor = floors.find(type)->second;
    static vector<int> result(3, 0);
    result = floor.find_empty_slot();
    result.insert(result.begin(), namesMap.find(
            type)->second);//in "result", there are three elements,which are [floor number][row][column] respectively
    return result;
}

void ParkingLot::clearSlot(string const &type, int row, int column) {
    floors.find(type)->second.clear_slot(row, column);
}

Floor &ParkingLot::operator[](int floorIndex) {
    return floors.find(names[floorIndex])->second;//return the "floorIndex" floor
}

void ParkingLot::pushSlot(Vehicle &vehicle, int row, int column) {
    (*this)[(namesMap.find(vehicle.getType()))->second][row][column].put_vehicle(vehicle);
}


