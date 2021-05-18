#ifndef DANTZIG_H_INCLUDED
#define DANTZIG_H_INCLUDED

double maxArray(double* src);
void ordonerArray(double* target);
int* normalisation(double* src);
double* ordonerObjet(double* p, double* w, double sizeKnapsack);
double* Dantzig(double* p, double* w, int* x);

#endif // DANTZIG_H_INCLUDED
