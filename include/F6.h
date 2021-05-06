#ifndef F6_H
#define F6_H
#include<Fitness.h>

class F6 : public Fitness
{
    public:
        F6();
        virtual double objcF(double* par);
        virtual ~F6();

    protected:

    private:
};

#endif // F6_H
