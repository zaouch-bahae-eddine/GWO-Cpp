#include "F6.h"
#include <iostream>

#include <cstdlib>
#include <math.h>       /* pow */

#include<Fitness.h>
using namespace std;

F6::F6()
{
}
/*
    Fonction Fitness F6
    parameter: tableau des valeurs à trouver leurs fitness
    retourne: le fitness des valeurs
*/
double F6::objcF(double* par)
{
    double sum = 0;
    for(double* i = par; *i != '\0'; i++ ){
        sum += pow(abs(*i + 0.5), 2.0);
    }
    return sum;
}

F6::~F6()
{
    //dtor
}
