#include <ArrayTools.h>
#include <iostream>
#include <cstdlib>   // rand and srand
#include <random>
#include <limits>
using namespace std;
//copy un des valeurs d'un tableau dans un autre
void copyTab(double* src, double* target)
{
    double *k, *m;
    for(k = src, m = target; *k != '\0', *m != '\0'; k++, m++){
        *m = *k;
    }
}
// return the max value in array
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
//ordonate array from biger to smolar
void ordonerArray(double* target)
{
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
// normalization an array and return new int array
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
                result ++;
            } else {
                *result = 0;
                result ++;
            }
        }
        *result = '\0';
    return result;
}
//ordonate object selon le raport (p/w); return the ordonated array with value (p/w)
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
