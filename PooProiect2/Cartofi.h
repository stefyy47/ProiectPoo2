#ifndef CARTOFI_H_INCLUDED
#define CARTOFI_H_INCLUDED
#include <string>
#include "Produs.h"
class Cartofi : public Produs<double>{
    static double disponibilRosii;
    static double disponibilAlbi;
    string culoare;
public:
    Cartofi();
    Cartofi(double,double,string);
    ~Cartofi();
    Cartofi(const Cartofi&);
    static double getDisponibilRosii(){
        return disponibilRosii;
    }
    static double getDisponibilAlbi(){
        return disponibilAlbi;
    }
    string getCuloare() const{
        return culoare;
    }
    void afisare();
    int calculeazaCerinta(double&);
    Cartofi& operator=(Cartofi&);
    friend istream& operator>>(istream&,Cartofi&);
};


#endif // CARTOFI_H_INCLUDED
