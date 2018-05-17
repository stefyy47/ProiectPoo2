#ifndef VARZA_H_INCLUDED
#define VARZA_H_INCLUDED
#include "Produs.h"
class Varza : public Produs<int>{
public:
    Varza();
    Varza(int, double);
    Varza(const Varza&);
    ~Varza();
    void afisare();
    friend istream& operator>>(istream&,Varza&);
    Varza& operator=(Varza&);
    int calculeazaCerinta(int&);
};


#endif // VARZA_H_INCLUDED
