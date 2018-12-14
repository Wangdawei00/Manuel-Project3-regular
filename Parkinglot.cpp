//
// Created by Wangdawei on 2018/12/7.
//

#include <fstream>
#include <random>
#include <ctime>
#include "Parkinglot.h"
#include "Ticket.h"

vector<Vehicle> ParkingLot::refreshOut() {
    vector<Vehicle> ret;
    for (auto &pair:floors) {
        vector<Vehicle> vehicles = pair.second.refresh();
        ret.insert(ret.end(), vehicles.begin(), vehicles.end());
    }
    return ret;
}

ParkingLot::ParkingLot(const string &fileName) {
    ifstream in;
    string name;
    in.open(fileName, ios::in);
    if (in.is_open()) {
        for (int i = 0; in >> name; ++i) {
            floors.insert(make_pair(name, Floor(name, i)));
        }
		in.close();
    } else {
        for (int i = 0; i < numOfVehicleDefault; ++i) {
            Floor floor1(vehicleNames[i], i);
            floors.insert(make_pair(vehicleNames[i], floor1));
        }
    }
}


void ParkingLot::refreshIn() {
    ArriTicket arriTicket;
    for (int i = 0; i < rand() % 6; ++i) {
        Vehicle temp;
        Floor &floor = floors.find(temp.getType())->second;
        if (!(floor.isFull())) {
            vector<int> array = floor.findEmpty();
            floor[array[0]][array[1]].pushVehicle(temp);
            arriTicket.set(floor[array[0]][array[1]].getVehicle().getArriTime(), floor.getIndex() + 1, array[0] + 1,
                           array[1] + 1, temp.getType());
            arriTicket.print();
        }
    }
}