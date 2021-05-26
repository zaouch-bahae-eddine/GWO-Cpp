#include <LireEcrire.h>
#include <fstream>
#include <iostream>
#include <string>
using namespace std;
//Lire un fichhier Txt
void Lire(char* fileName, int* nObject, double* capacitySack, double* p, double* w)
{
    std::ifstream infile(fileName);
    infile >> *nObject;
    infile >> *capacitySack;
    std::cout << "\nnObject = " << *nObject;
    std::cout << "\ncapacitySack = " << *capacitySack;
    double *pi = p;
    double *wi = w;
    *(pi + *nObject) = '\0';
    *(wi + *nObject) = '\0';

    while(infile >> *pi >> *wi){

        cout << "\np = " << *pi;
        cout << "\nw = " << *wi;
        pi++;
        wi++;
    }
}
