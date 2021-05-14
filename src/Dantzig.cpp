#include <iostream>
#include <Fitness.h>
#include <F6.h>
#include <random>
#include <limits>
#include <cstdlib>
#include <Fitness.h>
#include <cstdlib>   // rand and srand
#include <fstream>
double maxArray(double* src)
{
    double m = 0;
    for(double* i = src; *i != '\0'; i++ ){
        if(*i>m){
            m = *i;
        }
    }
    return *i;
}
void ordonerArray(double* target){
    double maxValue = 0;
    for(double* p = target; *p != '\0'; p++){
        for(double* k = p; *k != '\0'; k++){
            if(*p < *k){
                *p = *k;
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
    double rand;

    int* result =  (int *) malloc(sizeof(int));;
    if(maxValue > 1){
        for(double* i = src; *i != '\0'; i++){
            *i =/ maxValue;
            rand = (double)(dis(gen));
            if(*i >= rand){
                *result = 1;
                result = (int *) malloc(sizeof(int));
                result ++;
            } else {
                *result = 0;
                result = (int *) malloc(sizeof(int));
                result ++;
            }
        }
        *result = '\0';
    }
    return result;
}
double* ordonerObjet(double* p, double* w)
{
    double *i = NULL;
    double *j = NULL;
    double* result = (double *) malloc(sizeof(double));
    for( i = p, j = w; *i != '\0', *j != '\0'; i++, j++){
        *result = (double) (*p / *w);
        result = (double *) malsloc(sizeof(double));
        result ++;
    }
    *result = '\0';
    ordonerArray(result);
    return result;
}
double* Dantzig(double* p, double* w, int* x)
{
    double _c = 0;
    int* xi = NULL;
    double* wi = NULL;
    for(xi = x, wi = w; xi != '\0', wi != '\0'; xi++, wi++){
        _c += (*xi) * (*wi);
    }

}
