//
// Created by Wangdawei on 2018/11/23.
//

#ifndef PROJECT3_VEHICLE_H
#define PROJECT3_VEHICLE_H

#include <map>

static const int numOfVehicleDefault = 4;
static const char *vehicleNames[numOfVehicleDefault] = {"Car", "Van", "Motorbike", "Bicycle"};

class Vehicle {
private:
    std::string type;
    static std::map<std::string, double> typePrice;
    double price;
    time_t arriTime, departTime;

public:
    explicit Vehicle(std::string);

    Vehicle();

    static void setPrice(std::string fileName);

    static void setPrice();

    double get_all_time() const;//in seconds'
    double getPrice() const;

    void arrive();

    std::string getArriTime() const;

    void depart();

    std::string getType() const;
};

#endif //PROJECT3_VEHICLE_H
