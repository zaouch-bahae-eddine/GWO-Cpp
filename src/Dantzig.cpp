#include <iostream>
#include <Fitness.h>
#include <F6.h>
#include <random>
#include <limits>
#include <cstdlib>
#include <Fitness.h>
#include <cstdlib>   // rand and srand
#include <fstream>
#include "Dantzig.h"


double maxArray(double* src)
{
    double m = 0;
    double* i = NULL;
    for(i= src; *i != '\0'; i++ ){
        if(*i>m){
            m = *i;
        }
    }
    return m;
}
void ordonerArray(double* target){
    double permute = 0;

    for(double* p = target; *p != '\0'; p++){
        for(double* k = p; *k != '\0'; k++){
            if(*p < *k){
                permute = *p;
                *p = *k;
                *k = permute;
            }
        }
    }
}

int* normalisation(double* src)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0, 1);//uniform distribution between 0 and 1

    double maxValue = maxArray(src);
    int sizeOfArray = 1;
    double rand;

        for(double* i = src; *i != '\0'; i++){
            if(maxValue > 1){
                *i /= maxValue;
            }
            sizeOfArray++;
        }
        int* result = (int*) malloc(sizeOfArray * sizeof(int));
        for(double* i = src; *i != '\0'; i++ )
        {
            rand = (double)(dis(gen));
            if(*i >= rand){
                *result = 1;
                cout << *result;
                result ++;
            } else {
                *result = 0;
                cout << *result;
                result ++;
            }
        }
        *result = '\0';
    return result;
}

double* ordonerObjet(double* p, double* w)
{
    double *i = NULL;
    double *j = NULL;
    int cmp = 1;
    for( i = p; *i != '\0'; i++){
        cmp++;
    }
    double* result = (double *) malloc(cmp * sizeof(double));
    int k;
    for(k = 0, i = p, j = w; k < cmp , *i != '\0', *j != '\0'; k++, i++, j++){
        result[k] = (*i) / (*j);
        cout << "r = " <<result[k] << " p = " << *i << " w = " << *j;
    }
    result[cmp] = '\0';

    double* point_p1 = NULL;
    double* point_w1 = NULL;
    double* point_p2 = NULL;
    double* point_w2 = NULL;
    double permut_result, permut_p, permut_w;
    for(i = result, point_p1 = p, point_w1 = w; *i != '\0', *point_p1 != '\0', *point_w1 != '\0'; i++, point_p1++, point_w1++){
        for(j = i, point_p2 = point_p1, point_w2 = point_w1; *j != '\0', *point_p2 != '\0', *point_w2 != '\0'; j++, point_p2++, point_w2++){
            if(*j > *i){
                permut_result = *i;
                *i = *j;
                *j = permut_result;

                permut_p = *point_p1;
                *point_p1 = *point_p2;
                *point_p2 = permut_p;

                permut_w = *point_w1;
                *point_w1 = *point_w2;
                *point_w2 = permut_w;
            }
        }
    }
    return result;
}
double* DantzigAlgo(double* p, double* w)
{
    int cmp = 1;
    double _c = 0;
    double* pi = NULL;
    double* wi = NULL;
    double z = 0;
    for(pi = p, wi = w; pi != '\0', wi != '\0'; pi++, wi++){
       _c = _c + (*pi)*(*wi);
       cmp++;
    }
cout << "_c = " << cmp << endl;
    double* _x = (double*) malloc(cmp * sizeof(double));

    return _x;
}
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
        cout << "\nx["<< j << "] = " << _x[j];
        z += p[j] * min(1.0, (_c / w[j]));
        _c -= w[j] * min(1.0, (_c / w[j]));
        j++;
    }
    cout << "\nindice s = " << j - 1;
    return _x;
}
