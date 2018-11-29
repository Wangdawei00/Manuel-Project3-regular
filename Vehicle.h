//
// Created by Wangdawei on 2018/11/23.
//

#ifndef PROJECT3_VEHICLE_H
#define PROJECT3_VEHICLE_H

#include <map>

class Vehicle {
private:
    std::string type;
    static std::map<std::string, double> typePrice;
    double price;
    time_t arriTime, departTime;

public:
    explicit Vehicle(std::string);

    Vehicle();

    static void setPrice();

    double get_all_time();//in seconds'
    double getPrice();

    void arrive();

    std::string getArriTime();

    void depart();

    std::string getType();
};

#endif //PROJECT3_VEHICLE_H
