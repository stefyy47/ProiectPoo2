#ifndef FAINA_H_INCLUDED
#define FAINA_H_INCLUDED
#include "Produs.h"
class Faina : public Produs<double>{
    static double disponibil_cal1, disponibil_cal2, disponibil_cal3;
    int calitate;
public:
    Faina();
    Faina(int,double,double);
    Faina(const Faina&);
    ~Faina();
    static int getDisponibil1(){
        return disponibil_cal1;
    }
    static int getDisponibil2(){
        return disponibil_cal2;
    }
    static int getDisponibil3(){
        return disponibil_cal3;
    }
    void afisare();
    Faina& operator=(Faina&);
    friend istream& operator>>(istream&,Faina&);
    int calculeazaCerinta(double&);
};


#endif // FAINA_H_INCLUDED
