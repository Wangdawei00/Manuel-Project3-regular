#include <iostream>
#include "merge.h"
#include "Ticket.h"
#include <thread>
#include <cstring>
//#include <parkingLot.h>
//#include <GL/glut.h>
using namespace std;

int main(int argc, char *argv[]) {
    string fileName;
    int timePeriod = 0;
    for (int i = 0; i < argc; ++i) {
        if (strcmp(argv[i], "--file") == 0) {
            fileName = argv[i + 1];
        } else if (strcmp(argv[i], "--time") == 0) {
            timePeriod = stoi(argv[i + 1], nullptr, 10);
        }
    }
    cout << timePeriod << endl;
    ParkingLot parkingLot(fileName);
    Vehicle::setPrice(fileName);
//    cout << "Hello, World!" << endl;
    return 0;
}