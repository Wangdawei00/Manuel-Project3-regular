//
// Created by Wangdawei on 2018/11/23.
//

#include "Vehicle.h"
#include <iostream>
#include <ctime>
#include "Ticket.h"
#include <fstream>

//#define DEBUG
//const map<int, string> Vehicle::indexType={{1,"Bicycle"},{2,"Motorbike"},{3,"Car"},{4,"Van"}};
//using namespace chrono;

using namespace std;

map<string, double> Vehicle::typePrice; //set typePrice as a map whose key is a string and value is a double

Vehicle::Vehicle(string type) {
    this->type = move(type);
    this->price = typePrice.find(this->type)->second;
}

void Vehicle::setPrice(string fileName) {
    if (typePrice.empty()) {
        string name;
        ifstream in;
        in.open(fileName,ios::in);
        string s(50, '*');
        cout << s << endl;
        cout << "Please set the price for the following vehicles (in RMB per hour): " << endl;
//        typePrice.insert(make_pair("Car", 0));
//        typePrice.insert(make_pair("Motorbike", 0));
//        typePrice.insert(make_pair("Bicycle", 0));
//        typePrice.insert(make_pair("Van", 0));
        for (int i = 0; in>>name; ++i) {
            typePrice.insert(make_pair(name,0));//initialize the price for each type of vehicles by input
        }
        for (auto &iter : typePrice) {
            cout << iter.first << ": ";
            cin >> iter.second; //output all the vehicles' type and their related prices
        }
        in.close();
    } else {
        cerr << "You have already set the price for the vehicles!\n";
    }
#ifdef DEBUG
    for (auto &iter:typePrice) {
        cout<<iter.first<<": "<<iter.second<<endl;
    }
#endif
}

double Vehicle::get_all_time() {
    return difftime(departTime, arriTime);//calculate how long the vehicle spent in the parking lot
}

double Vehicle::getPrice() {
    return (this->price) * get_all_time();//price times time=cost
}

void Vehicle::arrive() {
    time(&arriTime);
}

string Vehicle::getArriTime() {
    string s = asctime(localtime(&arriTime));//get the local time form of the car's arriving time
    return s;
}

void Vehicle::depart() {
    time(&departTime);
}

string Vehicle::getType() {
    return this->type;
}

Vehicle::Vehicle() = default;
