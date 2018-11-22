//
// Created by Wangdawei on 2018/11/22.
//

#ifndef PROJECT3_TICKET_H
#define PROJECT3_TICKET_H

#include <string>
//#include <wsman.h>

class Ticket{
protected:
    std::string type;
public:
    virtual void print()=0;
};

class ArriTicket:public Ticket{
    std::string arriTime;
    int floor, column, row;
public:
    ArriTicket(std::string arriTime,int floor,int column, int row,std::string type);
    void print() override;
};

class DepartTicket:public Ticket{
    int time; double price;
public:
    DepartTicket(int time,double price, std::string);
    void print() override;
};
#endif //PROJECT3_TICKET_H
