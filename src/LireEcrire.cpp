#include <LireEcrire.h>
#include <fstream>
#include <iostream>
#include <string>
#include <bits/stdc++.h>

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

    while(infile >> *pi >> *wi){
        pi++;
        wi++;
    }
    *(pi + 1) = '\0';
    *(wi + 1) = '\0';
}

//Ecrire un fichhier csv des resultat
void Ecrire(char* fileName, int* nObject, double* capacitySack, double* p, double* w, int indiceSolution)
{
    std::ofstream myfile;
    char r_fileName[50] = "R-";
    strcat(r_fileName, fileName);
    int k;
    for(k = 0; k < 50; k++){
        if(r_fileName[k] == '.'){
            break;
        }
    }
    r_fileName[k + 1] = 'c';
    r_fileName[k + 2] = 's';
    r_fileName[k + 3] = 'v';
    myfile.open (r_fileName);
    myfile << "Nombre d'objet," << *nObject <<"\n";
    myfile << "Capacité," << *capacitySack <<"\n";
    myfile << "Indice S," << indiceSolution <<"\n";
    myfile << "P," << "W\n";
    for(int i = 0; i < indiceSolution; i++){
        myfile << *(p+i) << "," << *(w + i) << "\n";
    }
    myfile.close();
}
