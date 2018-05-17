#include "Bere.h"
Bere::Bere(int masura, double pret, string brand, string tip):Produs<int>(masura,pret){
    this->brand = brand;
    this->tip = tip;
}
Bere::Bere(){
    this->brand = "\0";
    this->tip = "\0";
}
Bere::~Bere(){};
void Bere::afisare(){
    Produs<int>::afisare();
    cout << "Brand: " << brand <<' ' << "Tipul berii: " <<tip<<endl;
}
Bere::Bere(const Bere& b):Produs<int>(b.getMasura(),b.getPret()){
    this->brand = b.brand;
    this->tip = b.tip;
}
Bere& Bere::operator=(Bere& b){
    cout<<"WTF";
    this->brand.clear();
    this->tip.clear();
    this->tip.assign(b.tip);
    setMasura(b.getMasura());
    setPret(b.getPret());
    return b;
}
istream& operator>>(istream& in,Bere& b){
    cout<<"Introduceti tipul berii(Blonda/Bruna)"<<endl;
    in >> b.tip;
    cout<<"Introduceti numele brandului"<<endl;
    in >> b.brand;
    cout<<"Introduceti numarul de doze de bere"<<endl;
    int masura;
    double pret;
    in >> masura;
    b.setMasura(masura);
    cout<<"Introduceti pretul/doza"<<endl;
    in >> pret;
    b.setPret(pret);
    b.setCostul(masura*pret);
    return in;
}
int Bere::calculeazaCerinta(int& cerinta){
    if(cerinta > 0){
        cerinta--;
        delete this;
        return 1;
    }
    return 0;
}
string Bere::getBrand() const{
    return brand;
 }
string Bere::getTip() const{
    return tip;
}
void Bere::setBrand(string brand){
    this->brand = brand;
}
void Bere::setTip(string tip){
    this->tip = tip;
}
