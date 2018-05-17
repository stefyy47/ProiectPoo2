#ifndef JUCARII_H_INCLUDED
#define JUCARII_H_INCLUDED
#include "Produs.h"
#include <string>
class Jucarii : public Produs<int>{
    string nume;
public:
    Jucarii();
    Jucarii(int,double,string);
    Jucarii(const Jucarii&);
    ~Jucarii();
    void afisare();
    Jucarii& operator=(Jucarii&);
    friend istream& operator>>(istream&,Jucarii&);
    int calculeazaCerinta(int&);
};


#endif // JUCARII_H_INCLUDED
