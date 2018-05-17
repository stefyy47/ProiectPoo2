#ifndef PRODUS_H_INCLUDED
#define PRODUS_H_INCLUDED
#include <iostream>
using namespace std;
template <class T>
class Produs{
private:
    T masura; //greutatea produsului sau numarul de bucati sau volumul
    double pret;
    double costul;
public:
    Produs(){
        pret = 0;
        masura = 0;
        costul = 0;
    }
    T getMasura() const{
        return masura;
    }
    double getPret() const{
        return pret;
    }
    double getCostul() const{
        return costul;
    }
    void setMasura(T masura){
        this->masura = masura;
    }
    void setPret(double pret){
        this->pret = pret;
    }
    void setCostul(double costul){
        this->costul = costul;
    }
    Produs(T masura, double pret){
        this->masura = masura;
        this->pret = pret;
        costul = masura*pret;
    }
    virtual ~Produs(){};
    virtual void afisare(){
        cout<< "Cantitatea: " << masura << ' ' << "Pretul/unitate de masura: " << pret << ' ' << "Costul produsului: " << costul << ' ';
    }
    virtual int calculeazaCerinta(T&) = 0;
};


#endif // PRODUS_H_INCLUDED
