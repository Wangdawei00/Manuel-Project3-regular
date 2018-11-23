#include <iostream>
#include "vector.h"
#include "Ticket.h"
#include "Singleton.h"
#include "Vehicle.h"
#include <ctime>

//#include <GL/glut.h>
using namespace std;

int main() {
//    cout<<Vehicle::a.find(1)->second<<endl;
    Vehicle::setPrice();
    return 0;
}