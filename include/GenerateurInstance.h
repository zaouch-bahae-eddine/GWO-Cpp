#ifndef GENERATEURINSTANCE_H
#define GENERATEURINSTANCE_H


class GenerateurInstance
{
    public:
        GenerateurInstance();
        void generat_Inst_correlee();
        void generat_Inst_non_correlee();
        void generat_Inst_fortement_correlee();
        bool assurWSuppC(char*);

    protected:

    private:
        int nbObjet;
        double capacitySack;
};

#endif // GENERATEURINSTANCE_H
