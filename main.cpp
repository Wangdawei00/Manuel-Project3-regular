#include <iostream>
#include <cstring>
#include <vector>
#include "Parkinglot.h"
#include <thread>
#include <chrono>
#include "Ticket.h"
#include <cstdlib>

using namespace std;

int main(int argc, char **argv) {
    srand((unsigned int) time(nullptr));
    int timep = 0;
    string fileName;
    if (argc == 1)
        cerr << "You didn't provide the period of time in the command line!\n";
    else {
        for (int i = 1; i < argc; ++i) {
            if (strcmp(argv[i], "--time") == 0)
                timep = strtol(argv[i + 1], nullptr, 10);
            if (strcmp(argv[i], "--file") == 0)
                fileName = argv[i + 1];
        }
    }
    if (timep == 0) {
        cerr << "You didn't correctly initialize the period of this simulation, please refer to the README file!"
             << endl;
        exit(233);
    }
    Vehicle::setPrice(fileName);
    ParkingLot parkingLot(fileName);
    for (int j = 0; j < timep; ++j) {
        printLeaving(parkingLot.refreshOut());
        parkingLot.refreshIn();
        this_thread::sleep_for(chrono::seconds(1));
    }
    return 0;
}