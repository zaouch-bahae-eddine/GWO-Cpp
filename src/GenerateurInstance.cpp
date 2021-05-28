#include "GenerateurInstance.h"
#include <cstdlib>   // rand and srand
#include <fstream>
#include <random>
#include <cstdlib>
#include <cstdio>
#include <iostream>
using namespace std;
GenerateurInstance::GenerateurInstance()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(1000, 50000);//uniform distribution between 1000 and 50000
    //ctor
    this->nbObjet = (int) (dis(gen)) + 1;
    std::uniform_real_distribution<> cap(250, 1000);
    this->capacitySack = (int) (cap(gen)) + 1;
}

void GenerateurInstance::generat_Inst_correlee()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0, 20);

    std::ofstream myfile;
    char* fileName = "Inst-c.txt";
    myfile.open(fileName);
    myfile << this->nbObjet << "\n";
    myfile << this->capacitySack << "\n";
    int wi = 0;
    for(int i = 0; i < this->nbObjet - 1; i++){
        wi = ((int) (dis(gen)) + 1);
        myfile << ((int)( wi + (dis(gen)) + 1))<< " " << wi << "\n";
    }
    wi = ((int) (dis(gen)) + 1);
    myfile << ((int)( wi + (dis(gen)) + 1))<< " " << wi;
    myfile.close();
}

void GenerateurInstance::generat_Inst_non_correlee()
{
std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0, 20);

    std::ofstream myfile;
    char* fileName = "Inst-n-c.txt";
    myfile.open(fileName);
    myfile << this->nbObjet << "\n";
    myfile << this->capacitySack << "\n";
    for(int i = 0; i < this->nbObjet - 1; i++){
        myfile << ((int) (dis(gen)) + 1) << " " << ((int) (dis(gen)) + 1) << "\n";
    }
    myfile << ((int) (dis(gen)) + 1) << " " << ((int) (dis(gen)) + 1);
    myfile.close();
}

void GenerateurInstance::generat_Inst_fortement_correlee(int constanteCorrelation)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0, 20);

    std::ofstream myfile;
    char* fileName = "Inst-f-c.txt";
    myfile.open(fileName);
    myfile << this->nbObjet << "\n";
    myfile << this->capacitySack << "\n";
    int wi = 0;
    for(int i = 0; i < this->nbObjet - 1; i++){
        wi = ((int) (dis(gen)) + 1);
        myfile << (wi + constanteCorrelation)<< " " << wi << "\n";
    }
    wi = ((int) (dis(gen)) + 1);
    myfile << (wi + constanteCorrelation)<< " " << wi;
    myfile.close();
}


bool GenerateurInstance::assurWSuppC(char* fileName)
{
    double n,c,p,w;
    int checked = this->verifyCandW(fileName);
    if(checked > 1){
        int nbLigne = 0;
        std::ofstream myfile;
        myfile.open ("prepas.txt");
        myfile << n << "\n";
        myfile << c << "\n";

        std::ifstream infile(fileName);
        infile.clear();
        infile.seekg(0);
        infile >> n;
        infile >> c;

        while((infile >> p >> w) && nbLigne < this->nbObjet - 1){
            myfile << p << " " << (w + checked -1 ) << "\n";
            nbLigne++;
        }
        myfile << p << " " << (w + checked -1);

        myfile.close();
        infile.close();
        remove(fileName);
        rename("prepas.txt", fileName);
        //Les valeur vont changer aprés l'appel de cette fonction
        return true;
    } else {
        //Les valeurs n'ont pas changé
        return false;
    }
}


int GenerateurInstance::verifyCandW(char* fileName){
    double sum = 0, sumW = 0;
    double n,c,p,w;
    int checked = 1;
    std::ifstream infile(fileName);
    infile >> n;
    infile >> c;
    while(infile >> p >> w){
        sumW += w;
    }
    sum = sumW;
    check:
    if(sum <= c){
        checked++;
        sum = sumW * checked;
        goto check;
    }
    return checked;
}
