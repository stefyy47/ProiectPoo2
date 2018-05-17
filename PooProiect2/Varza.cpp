#include "Varza.h"
Varza::Varza(int masura, double pret):Produs<int>(masura,pret){
}
Varza::Varza(){}
Varza::~Varza(){
}
void Varza::afisare(){
    Produs<int>::afisare();
}
Varza::Varza(const Varza& v):Produs<int>(v.getMasura(),v.getPret()){}
istream& operator>>(istream& in,Varza& v){
    int masura;
    double pret;
    cout<<"Introduceti numarul de verze"<<endl;
    in >> masura;
    v.setMasura(masura);
    cout<<"Introduceti pretul/kg"<<endl;
    in >> pret;
    v.setPret(pret);
    v.setCostul(masura*pret);
    return in;
}
Varza& Varza::operator=(Varza& v){

    setMasura(v.getMasura());
    setPret(v.getPret());
    return v;
}
int Varza::calculeazaCerinta(int& cerinta){
    if(cerinta > 0){
        cerinta--;
        if(getMasura() == 0){
             cout << "Varza indisponibila"<<endl;
             delete this;
            }
        else{
            setMasura(getMasura() - 1);
            return 1;
        }
    }
    return 0;
}
