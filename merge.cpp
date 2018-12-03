//
// Created by Wangdawei on 2018/12/3.
//

#include "merge.h"
#include "Ticket.h"

void printArriTicket(Vehicle const &v, int floor, int row, int column) {
    ArriTicket arriTicket;
    arriTicket.set(v.getArriTime(), floor, row, column, v.getType());
    arriTicket.print();
}

void printDepartTicket(Vehicle const &v) {
    DepartTicket departTicket;
    departTicket.set(v.get_all_time(), v.getPrice(), v.getType());
    departTicket.print();
}