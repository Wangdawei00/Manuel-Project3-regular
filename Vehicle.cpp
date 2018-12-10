//
// Created by Wangdawei on 2018/12/7.
//

#include "Vehicle.h"
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <random>
#include <ctime>

const time_t Vehicle::base = time(nullptr);
map<string, double> Vehicle::typePrice;

Vehicle::Vehicle() {
    string type;
//    std::mt19937 mt((unsigned int) time(nullptr));
//    std::uniform_int_distribution<int> dist(1, 10);

    while (type.empty()) {
        for (auto const &item:typePrice) {
            if (rand() % 10 < 5) {
                type = item.first;
            }
        }
    }
    this->type = type;
    this->price = typePrice[type];
}

void Vehicle::setPrice(const string &fileName) {
    if (typePrice.empty()) {
        ifstream in;
        in.open(fileName, ios::in);
        if (in.is_open()) {
            string name;
            for (int i = 0; in >> name; ++i) {
                typePrice.insert(make_pair(name, 0));
            }
			in.close();
        } else {
            for (auto const &item:vehicleNames) {
                typePrice.insert(make_pair(item, 0));
            }
        }
        string s(50, '*');
        cout << s << endl;
        cout << "Please set the price for the following vehicles (in RMB per hour): " << endl;
        for (auto &item:typePrice) {
            cout << item.first << ": ";
            cin >> item.second;
        }
        cout << s << endl;
    } else {
        cerr << "You have already set the price for the vehicles!\n";
    }

}

void Vehicle::arrive() {
    time(&arriTime);
    arriTime += (arriTime - base) * 599;
//    cout<<asctime(localtime(&arriTime))<<endl;
}

void Vehicle::depart() {
    time(&departTime);
    departTime += (departTime - base) * 599;
//    cout<<asctime(localtime(&departTime));
}

const string &Vehicle::getArriTime() const {
    static string s;
//    cout<<"Test! "<<s;
    s = asctime(localtime(&arriTime));
    return s;
}

const string &Vehicle::getType() const {
    return type;
}

double Vehicle::getInterval() const {
    return difftime(departTime, arriTime);
}

double Vehicle::getPrice() const {
    return price * getInterval() / 3600;
}
