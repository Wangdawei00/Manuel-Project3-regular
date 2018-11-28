#include <iostream>
#include <chrono>
#include "vector.h"
#include "Ticket.h"
#include "Singleton.h"
#include "Vehicle.h"
#include <thread>
//#include <ctime>
//#include <GL/glut.h>
using namespace std;

int main() {
    Vehicle::setPrice();
    Vehicle a("Car");
    a.arrive();
    this_thread::sleep_for(10s);
    a.depart();
    cout<<a.getPrice()<<endl;
//    cout<<Vehicle::a.find(1)->second<<endl;
//    Vehicle::setPrice();
//    Singleton &a=Singleton::getInstance();

    return 0;
}