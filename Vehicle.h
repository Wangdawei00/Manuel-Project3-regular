//
// Created by Wangdawei on 2018/12/7.
//

#ifndef PROJECT3_VEHICLE_H
#define PROJECT3_VEHICLE_H

#include <map>

static const int numOfVehicleDefault = 4;
static const char *vehicleNames[numOfVehicleDefault] = {"Car", "Van", "Motorbike", "Bicycle"};
using namespace std;

class Vehicle {
private:
    static map<string, double> typePrice;
    time_t arriTime, departTime;
    double price;
    string type;
    const static time_t base;
public:
    Vehicle();

    static void setPrice(const string &fileName);

    void arrive();

    void depart();

    const string &getArriTime() const;

    double getInterval() const;

    double getPrice() const;

    const string &getType() const;
};

#endif //PROJECT3_VEHICLE_H
