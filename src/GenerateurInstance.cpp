#include "GenerateurInstance.h"

GenerateurInstance::GenerateurInstance()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(1000, 50000);//uniform distribution between 1000 and 50000
    //ctor
    this.nbObjet = (int) (dis(gen)) + 1;
    std::uniform_real_distribution<> dis(250, 1000);
    this.capacitySack = (int) (dis(gen)) + 1;
}

void GenerateurInstance::generat_Inst_correlee()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0, 20);

    std::ofstream myfile;
    myfile.open ("Inst-c.txt");
    myfile << this.nbObjet << "\n";
    myfile << this.capacitySack << "\n";
    for(int i = 0; i < this.nbObjet; i++){
        myfile << ((int) (dis(gen)) + 1) << " " << ((int) (dis(gen)) + 1) << "\n";
    }
}

void GenerateurInstance::generat_Inst_non_correlee()
{
    std::ofstream myfile;
    myfile.open ("Inst-n.txt");
}

void GenerateurInstance::generat_Inst_fortement_correlee()
{
    std::ofstream myfile;
    myfile.open ("Inst-fc.txt");
}
