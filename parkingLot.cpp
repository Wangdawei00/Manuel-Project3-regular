//
// Created by lenovo on 2018/11/28.
//
#include "Floor.h"
#include "parkingLot.h"
#include <string>
//#include <cstdlib>
#include <vector>
#include <fstream>
#include <random>
#include <map>

using namespace std;
static const int numOfVehicleDefault = 4;
static const char *vehicleNames[numOfVehicleDefault] = {"Car", "Van", "Motorbike", "Bicycle"};

ParkingLot::ParkingLot(string fileName) {//take the filename as an input
    ifstream in;
    in.open(fileName, ios::in);
    string temp;
    for (int j = 0; in >> temp; ++j) {
        names.push_back(temp);
        namesMap.insert(make_pair(names[j], j));//use make_pair to regard name and its ID as a whole part
    }
    random_device randomDevice;
//    namesMap.insert(make_pair("Car", 0));
//    namesMap.insert(make_pair("Van", 1));
//    namesMap.insert(make_pair("Bicycle", 2));
//    namesMap.insert(make_pair("Motorbike", 3));
//    names[0] = "Car";
//    names[1] = "Van";
//    names[2] = "Bicycle";
//    names[3] = "Motorbike";
    for (int i = 0; i < names.size(); ++i) {
        floors.insert(make_pair(names[i], Floor(randomDevice() % 2 + 5, randomDevice() % 2 + 5, names[i], i)));
    }//generate "floors":each floor has its name, as well as a "floor" which contains its size and type
    in.close();
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
//    int i;
    //map<string,int> floorMap;
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

ParkingLot::ParkingLot() {
    for (int i = 0; i < numOfVehicleDefault; ++i) {
        names.emplace_back(vehicleNames[i]);
        namesMap.insert(make_pair(names[i], i));
    }
    random_device randomDevice;
    for (int i = 0; i < names.size(); ++i) {
        floors.insert(make_pair(names[i], Floor(randomDevice() % 2 + 5, randomDevice() % 2 + 5, names[i], i)));
    }
}
