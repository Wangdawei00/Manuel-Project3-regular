//
// Created by Wangdawei on 2018/11/22.
//

#ifndef PROJECT3_TICKET_H
#define PROJECT3_TICKET_H

#include <string>

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
    ArriTicket();
    void print() override;
    void set(std::string arriTime,int floor,int column, int row,std::string type);
};

class DepartTicket:public Ticket{
    int time; double price;
public:
    DepartTicket();
    void print() override;
    void set(int time,double price, std::string);
};
#endif //PROJECT3_TICKET_H
