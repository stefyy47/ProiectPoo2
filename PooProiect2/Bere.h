#ifndef BERE_H_INCLUDED
#define BERE_H_INCLUDED
#include <string>
#include "Produs.h"
class Bere : public Produs<int>{
    string brand;
    string tip;
public:
    Bere();
    Bere(int,double,string,string);
    Bere(const Bere&);
    ~Bere();
    void afisare();
    string getBrand() const;
    string getTip() const;
    void setBrand(string);
    void setTip(string);
    Bere& operator=(Bere&);
    friend istream& operator>>(istream&,Bere&);
    int calculeazaCerinta(int&);
};


#endif // BERE_H_INCLUDED
