#include "GenerateurInstance.h"
#include <cstdlib>   // rand and srand
#include <fstream>
#include <random>
#include <cstdlib>
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
    myfile.open (fileName);
    myfile << this->nbObjet << "\n";
    myfile << this->capacitySack << "\n";
    for(int i = 0; i < this->nbObjet; i++){
        myfile << ((int) (dis(gen)) + 1) << " " << ((int) (dis(gen)) + 1) << "\n";
    }
    myfile.close();
    if(this->assurWSuppC(fileName)){
        cout << "Valuer modifies"<< endl;
    }else {
        cout << "Valeur non modifes" << endl;
    }
}

void GenerateurInstance::generat_Inst_non_correlee()
{
    std::ofstream myfile;
    myfile.open ("Inst-n.txt");

    myfile.close();
}

void GenerateurInstance::generat_Inst_fortement_correlee()
{
    std::ofstream myfile;
    myfile.open ("Inst-fc.txt");

    myfile.close();
}
bool GenerateurInstance::assurWSuppC(char* fileName)
{
    std::ifstream infile(fileName);
    double sum = 0, sumW = 0;
    double n,c,p,w;
    int checked = 1;
    infile >> n;
    infile >> c;

    while(infile >> p >> w){
        sumW += w;
    }
    cout << "sumW = " << sumW;
    check:
    if(sum < c){
        checked++;
        sum = sumW * checked;

        goto check;
    }
    cout <<"\n checked = " << checked;
    if(checked > 1){
        std::fstream myfile;
        myfile.open ("prepas.txt");
        myfile << n << "\n";
        myfile << c << "\n";

        infile.clear();
        infile.seekg(0);

        infile >> n;
        infile >> c;
        cout<< "hh";
        while(infile >> p >> w){
            myfile << p << " " << (w + checked -1 ) << "\n";
        }
        myfile.close();
        infile.close();
        //remove(fileName);
        //rename("prepa.txt", fileName);
        //Les valeur vont changer aprés l'appel de cette fonction
        return true;
    } else {
        //Les valeurs n'ont pas changé
        return false;
    }
}
