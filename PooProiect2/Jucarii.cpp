#include "Jucarii.h"
Jucarii::Jucarii(){}
Jucarii::Jucarii(int masura, double pret, string nume):Produs<int>(masura,pret){
    this->nume = nume;
}
Jucarii::~Jucarii(){};
void Jucarii::afisare(){
    Produs<int>::afisare();
    cout << nume << endl;
}
int Jucarii::calculeazaCerinta(int& cerinta){
    if(cerinta > 0){
        cerinta--;
        delete this;
        return 1;
    }
    return 0;
}
Jucarii& Jucarii::operator=(Jucarii& j){
    this->nume = j.nume;
    setMasura(j.getMasura());
    setPret(j.getPret());
    return j;
}
Jucarii::Jucarii(const Jucarii& j):Produs<int>(j.getMasura(),j.getPret()){
    this->nume = j.nume;
}
istream& operator>>(istream& in,Jucarii& j){
    cout<<"Numele jucariei"<<endl;
    in >> j.nume;
    cout<<"Cate jucarii?"<<endl;
    int masura;
    double pret;
    in >> masura;
    j.setMasura(masura);
    cout<<"Pretul/bucata?"<<endl;
    in >> pret;
    j.setPret(pret);
    j.setCostul(masura*pret);
    return in;
}
