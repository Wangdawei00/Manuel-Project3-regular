//
// Created by Wangdawei on 2018/11/23.
//

#include "Vehicle.h"
#include <iostream>
#include <ctime>
#include "Ticket.h"
//#define DEBUG
//const std::map<int, std::string> Vehicle::indexType={{1,"Bicycle"},{2,"Motorbike"},{3,"Car"},{4,"Van"}};

std::map<std::string, double> Vehicle::typePrice;

Vehicle::Vehicle(std::string type) {
    this->type = std::move(type);
    this->price = typePrice.find(this->type)->second;
}

void Vehicle::setPrice() {
    if (typePrice.empty()) {
        std::string s(50, '*');
        std::cout << s << std::endl;
        std::cout << "Please set the price for the following vehicles (in RMB per second): " << std::endl;
        typePrice.insert(std::make_pair("Car", 0));
        typePrice.insert(std::make_pair("Motorbike", 0));
        typePrice.insert(std::make_pair("Bicycle", 0));
        typePrice.insert(std::make_pair("Van", 0));
        for (auto &iter : typePrice) {
            std::cout << iter.first << ": ";
            std::cin >> iter.second;
        }
    } else {
        std::cerr << "You have already set the price for the vehicles!\n";
    }
#ifdef DEBUG
    for (auto &iter:typePrice) {
        std::cout<<iter.first<<": "<<iter.second<<std::endl;
    }
#endif
}

double Vehicle::get_all_time() {
    return difftime(departTime, arriTime);
}

double Vehicle::getPrice() {
    return (this->price) * get_all_time();
}

void Vehicle::arrive() {
    time(&arriTime);
}

std::string Vehicle::getArriTime() {
    std::string s = asctime(localtime(&arriTime));
    return s;
}

void Vehicle::depart() {
    time(&departTime);
}
