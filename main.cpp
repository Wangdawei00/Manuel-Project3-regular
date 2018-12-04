#include <iostream>
#include "merge.h"
#include "Ticket.h"
#include <thread>
//#include <parkingLot.h>
//#include <GL/glut.h>
using namespace std;

int main(int argc, char *argv[]) {
    string fileName;
    if (argc > 1) {
        fileName = argv[2];
    }
    ParkingLot parkingLot(fileName);
    Vehicle::setPrice(fileName);
    int timePeriod;
    cout << "Please input a ";
    cin >> timePeriod;
//    cout << "Hello, World!" << endl;
    return 0;
}