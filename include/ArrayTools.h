#ifndef ARRAYTOOLS_H_INCLUDED
#define ARRAYTOOLS_H_INCLUDED

    //copy un des valeurs d'un tableau dans un autre
    void copyTab(double*, double*);

    //return the max value in array
    double maxArray(double*);

    //ordonate array from biger to smolar
    void ordonerArray(double*);

    // normalization an array and return new int array
    int* normalisation(double*);

    //ordonate object selon le raport (p/w); return the ordonated array with value (p/w)
    double* ordonerObjet(double*, double*);

#endif // ARRAYTOOLS_H_INCLUDED
