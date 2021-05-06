#include "Fitness.h"

#include <iostream>
using namespace std;

Fitness::~Fitness()
{
    //dtor
}
double Fitness::objcF(double* par)
{
    cout << "Hello Fitness!";
    return 1;
}

