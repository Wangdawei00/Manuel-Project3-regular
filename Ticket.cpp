//
// Created by Wangdawei on 2018/11/22.
//

#include <iostream>
#include "Ticket.h"
void ArriTicket::print() {
    std::string s(50,'*');
    std::cout<<s<<std::endl;
    std::cout<<"Time of arrival: "<<this->arriTime<<std::endl;
    std::cout<<"Type of the vehicle: "<< this->type<<std::endl;
    std::cout<<"Empty slot location: Floor "<<this->floor<<" Row "<<this->row<<" Column "<<this->column<<std::endl;
    std::cout<<s<<std::endl;
}

void DepartTicket::print() {
    std::string s(50,'*');
    std::cout<<s<<std::endl;
    std::cout<<"Time spent in the parking lot: "<<this->time<<" minutes"<<std::endl;
    std::cout<<"Type of the vehicle: "<< this->type<<std::endl;
    std::cout<<"Price: "<<this->price<<std::endl;
    std::cout<<s<<std::endl;
}

void DepartTicket::set(int time, double price, std::string) {
    this->time=time;
    this->price=price;
    this->type=std::move(type);
}

void ArriTicket::set(std::string arriTime, int floor, int column, int row, std::string type) {
    this->type=std::move(type);
    this->floor=floor;
    this->column=column;
    this->row=row;
    this->arriTime=std::move(arriTime);
}

ArriTicket::ArriTicket() {
    floor=column=row=-1;
    type=arriTime="";
}

DepartTicket::DepartTicket() {
    price=time=-1;
    type="";
}