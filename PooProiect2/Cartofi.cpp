#include "Cartofi.h"
double Cartofi::disponibilAlbi = 0;
double Cartofi::disponibilRosii = 0;
Cartofi::Cartofi(){};
Cartofi::Cartofi(double masura, double pret, string culoare):Produs<double>(masura,pret){
    this->culoare = culoare;
    if(culoare == "rosii" || culoare == "Rosii")
        disponibilRosii += masura;
    else if(culoare == "albi" || culoare == "Albi")
        disponibilAlbi += masura;
    else {
        culoare = "rosii";
        disponibilRosii += masura;
    }
}
Cartofi& Cartofi::operator=(Cartofi& c){
    if(culoare == "rosii" || culoare == "Rosii")
        disponibilRosii -= getMasura();
    else if(culoare == "albi" || culoare == "Albi")
        disponibilAlbi -= getMasura();
    this->culoare = c.culoare;
    if(culoare == "rosii" || culoare == "Rosii")
        disponibilRosii += c.getMasura();
    else if(culoare == "albi" || culoare == "Albi")
        disponibilAlbi += c.getMasura();
    setMasura(c.getMasura());
    setPret(c.getPret());
    return c;
}
Cartofi::Cartofi(const Cartofi& c):Produs<double>(c.getMasura(),c.getPret()){
    this->culoare = c.culoare;
    if(culoare == "rosii" || culoare == "Rosii")
        disponibilRosii += c.getMasura();
    else if(culoare == "albi" || culoare == "Albi")
        disponibilAlbi += c.getMasura();
}
Cartofi::~Cartofi(){
    if(culoare == "rosii" || culoare == "Rosii")
        disponibilRosii -= getMasura();
    else if(culoare == "albi" || culoare == "Albi")
        disponibilAlbi -= getMasura();
}
void Cartofi::afisare(){
      Produs<double>::afisare();
      if(culoare == "rosii" || culoare == "Rosii")
        cout<< "Kilograme de cartofi rosii disponibile: "<<disponibilRosii<<endl;
      else if(culoare == "albi" || culoare == "Albi")
        cout<< "Kilograme de cartofi albi disponibile: "<<disponibilAlbi<<endl;
}
int Cartofi::calculeazaCerinta(double& cerinta){
     if(getMasura() > cerinta){
        setMasura(getMasura() - cerinta);
        if(culoare == "Rosii" || culoare == "rosii")
            disponibilRosii -= cerinta;
        else if(culoare == "Albi" || culoare == "albi")
            disponibilAlbi -= cerinta;
        cerinta = 0;
        return 1;
     }
    else if(getMasura() <= cerinta){
        cerinta -= getMasura();
        delete this;
        return 2;
    }
    return 0;
}
istream& operator>>(istream& in,Cartofi& c){
    cout<<"Culoarea cartofilor?(Rosii/Albi)"<<endl;
    in >> c.culoare;
    cout<<"Cate kilograme de cartofi?"<<endl;
    int masura;
    double pret;
    in >> masura;
    c.setMasura(masura);
    cout<<"Pret/kg de cartofi?"<<endl;
    in >> pret;
    c.setPret(pret);
    c.setCostul(masura*pret);
    return in;
}
