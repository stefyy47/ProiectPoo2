#include "Faina.h"
double Faina::disponibil_cal1 = 0;
double Faina::disponibil_cal2 = 0;
double Faina::disponibil_cal3 = 0;
Faina::Faina(int calitate, double masura, double pret):Produs<double>(masura,pret){
    this->calitate = calitate;
    if(this->calitate == 1)
        disponibil_cal1 += masura;
    else if(this->calitate == 2)
            disponibil_cal2 += masura;
    else if(this->calitate == 3)
            disponibil_cal3 += masura;
    else {
        calitate = 1;
        disponibil_cal1 += masura;
    }
}
Faina::Faina(){calitate = 0;}
Faina::Faina(const Faina& f):Produs<double>(f.getMasura(),f.getPret()){
    this->calitate = f.calitate;
    if(this->calitate == 1)
        disponibil_cal1 += f.getMasura();
    else if(this->calitate == 2)
            disponibil_cal2 += f.getMasura();
    else if(this->calitate == 3)
            disponibil_cal3 += f.getMasura();
}
Faina& Faina::operator=(Faina& f){
    if(this->calitate == 1)
        disponibil_cal1 -= getMasura();
    else if(this->calitate == 2)
            disponibil_cal2 -= getMasura();
    else if(this->calitate == 3)
            disponibil_cal3 -= getMasura();

    this->calitate = f.calitate;

    if(this->calitate == 1)
        disponibil_cal1 += f.getMasura();
    else if(this->calitate == 2)
            disponibil_cal2 += f.getMasura();
    else if(this->calitate == 3)
            disponibil_cal3 += f.getMasura();
    setMasura(f.getMasura());
    setPret(f.getPret());
    return f;

}
Faina::~Faina(){
    if(this->calitate == 1)
        disponibil_cal1 -= getMasura();
    else if(this->calitate == 2)
            disponibil_cal2 -= getMasura();
    else if(this->calitate == 3)
            disponibil_cal3 -= getMasura();
}
void Faina::afisare(){
    Produs<double>::afisare();
    cout << "Cantitatea de faina ramasa: ";
    if(calitate == 1)
        cout << disponibil_cal1 << endl;
    else if(calitate == 2)
            cout<< disponibil_cal2 << endl;
    else if(calitate == 3)
            cout<< disponibil_cal3 << endl;
}
int Faina::calculeazaCerinta(double& cerinta){
     cout << "Introduceti calitatea dorita(1/2/3)" << endl;
     if(getMasura() > cerinta){
        setMasura(getMasura() - cerinta);
        if(calitate == 1)
            disponibil_cal1 -= cerinta;
        else if(calitate == 2)
            disponibil_cal2 -= cerinta;
        else if(calitate == 3)
            disponibil_cal3 -= cerinta;
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
istream& operator>>(istream& in,Faina& f){
    int calitate;
    double masura,pret;
    cout<<"Introduceti calitatea fainii(cal 1/2/3)"<<endl;
    in >> calitate;
    cout<<"Introduceti nr de kilograme de faina"<<endl;
    in >> masura;
    cout<<"Introduceti pretul/kg"<<endl;
    in >> pret;
    f.calitate = calitate;
    f.setMasura(masura);
    f.setPret(pret);
    f.setCostul(pret*masura);
    return in;
}
