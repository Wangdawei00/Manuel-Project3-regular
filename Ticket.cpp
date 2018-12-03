//
// Created by Wangdawei on 2018/11/22.
//

#include <iostream>
#include "Ticket.h"

using namespace std;

void ArriTicket::print() {
    string s(50, '*');
    cout << s << endl;//draw a line with 50 "*" stars
    cout << "Time of arrival: " << this->arriTime << endl;
    cout << "Type of the vehicle: " << this->type << endl;
    cout << "Empty slot location: Floor " << this->floor << " Row " << this->row << " Column " << this->column << endl;
    cout << s << endl;
}

void DepartTicket::print() {
    string s(50, '*');
    cout << s << endl;
    cout << "Time spent in the parking lot: " << this->time << " minutes" << endl;
    cout << "Type of the vehicle: " << this->type << endl;
    cout << "Price: " << this->price << endl;
    cout << s << endl;
}

void DepartTicket::set(double time, double price, string const &type) {
    this->time = time;
    this->price = price;
    this->type = type;
}

void ArriTicket::set(string const &arriTime, int floor, int row, int column, string const &type) {
    this->type = type;
    this->floor = floor;
    this->column = column;
    this->row = row;
    this->arriTime = arriTime;
}

ArriTicket::ArriTicket() {//initialization of the arriving part
    floor = column = row = -1;
    type = arriTime = "";
}

DepartTicket::DepartTicket() {//initialization of the departing part
    price = time = -1;
    type = "";
}