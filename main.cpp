#include <iostream>
#include <Fitness.h>
#include <F6.h>
#include <random>
#include <limits>
#include <cstdlib>
#include <Fitness.h>
#include <cstdlib>   // rand and srand
#include <fstream>
#include <ArrayTools.h>
#include <Dantzig.h>
#include <LireEcrire.h>
#include <stdio.h>
#include "GenerateurInstance.h"
#include <GWOA.h>
using namespace std;

int main()
{
    char* fileName = "Inst-n-c.txt";
    int* s_indice = (int*) malloc(sizeof(int));
    GenerateurInstance *G = new GenerateurInstance();
    G->generat_Inst_non_correlee();
    G->generat_Inst_correlee();
    G->generat_Inst_fortement_correlee(50);
    //G->assurWSuppC(fileName);
    //int kk = G->verifyCandW(fileName);
    // cout << "kk = " << kk;
    int* nbObjet = (int*) malloc(sizeof(int));

    std::ifstream infile(fileName);
    infile >> *nbObjet;
    infile.close();
    double* src_p = (double*) malloc(*(nbObjet + 1)*sizeof(double));
    double* src_w = (double*) malloc(*(nbObjet + 1)*sizeof(double));
    double* capacitySack = (double*) malloc(sizeof(double));

    Lire(fileName,nbObjet,capacitySack, src_p, src_w);
    cout << "\ndantzig : \n" ;
    double* res= DantzigAlgo(s_indice, src_p, src_w, *capacitySack);

    for(double* m = res; *m != '\0'; m++){
        cout << *m <<" ,";
    }
        cout << "\ndantzig ended : \n";
    Ecrire(fileName,nbObjet,capacitySack, src_p, src_w, *s_indice);
    delete[] src_p;
    delete[] src_w;
    Fitness *f = new F6();
    int ub[3] = {100, 100,'\0'};
    int lb[3] = {-100, -100,'\0'};
    //GWO(f, ub, lb, 2, 20, 20);
    return 0;
}
