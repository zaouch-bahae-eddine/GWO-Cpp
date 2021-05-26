#include <iostream>
#include "Dantzig.h"
#include "ArrayTools.h"
using namespace std;

double* DantzigAlgo(double* p, double* w, double knapsackTaille)
{
    //ordonner décroissant
    ordonerObjet(p, w);
    int cmp = 1;
    double c = knapsackTaille;
    double* pi = NULL;
    double* wi = NULL;
    double z = 0;
    for( pi = p; *pi != '\0'; pi++){
        cmp++;
    }
    double _c = c;
    double* _x = (double*) malloc(cmp * sizeof(double));


    int j = 0;
    for(int i = 0; i <cmp; i++){
        _x[i] = 0;
    }
    _x[cmp] = '\0';
    while(j < cmp && _c > 0){
        _x[j] = min(1.0, (_c / (w[j])));
        cout << "\nx["<< j << "] = " << _x[j] << " p = " << p[j] << " w = " << w[j];
        z += p[j] * min(1.0, (_c / w[j]));
        _c -= w[j] * min(1.0, (_c / w[j]));
        j++;
    }
    cout << "\nindice s = " << j - 1 << endl;
    return _x;
}
