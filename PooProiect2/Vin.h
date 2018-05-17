#ifndef VIN_H_INCLUDED
#define VIN_H_INCLUDED
#include "Produs.h"
#include <string>
template <class T>
class Vin : public Produs<T>{
    string tip;
    string brand;
    static double disponibilAlb;
    static double disponibilRosu;
public:
    Vin(){}
    Vin(T masura, double pret, string tip):Produs<T>(masura, pret){
        this->tip = tip;
        if(tip == "Alb" || tip == "alb")
            disponibilAlb += masura;
        else if(tip == "Rosu" || tip == "rosu")
            disponibilRosu += masura;
        else {
            tip = "alb";
            disponibilAlb += masura;
        }
    }
    Vin(const Vin& v):Produs<T>(v.getMasura(),v.getPret()){
        this->tip = v.tip;
        this->brand = v.brand;
        if(brand == "\0"){
            if(tip == "alb" || tip == "Alb")
                disponibilAlb += v.getMasura();
            else if(tip == "rosu" || tip == "Rosu")
                disponibilRosu += v.getMasura();
        }
    }
    Vin(T masura,double pret, string tip, string brand):Produs<T>(masura, pret){
        this->tip = tip;
        this->brand = brand;
    }
    ~Vin(){
        if(brand == "\0"){
            if(tip == "Alb" || tip == "alb")
                disponibilAlb -= this->getMasura();
            else if(tip == "Rosu" || tip == "rosu")
                disponibilRosu -= this->getMasura();
        }
    }
    Vin& operator=(Vin& v){
        if(brand == "\0"){
            if(tip == "Alb" || tip == "alb")
                disponibilAlb -= this->getMasura();
            else if(tip == "Rosu" || tip == "rosu")
                disponibilRosu -= this->getMasura();
            this->brand = v.brand;
            this->tip = v.tip;
            setMasura(v.getMasura());
            setPret(v.getPret());
            if(tip == "Alb" || tip == "alb")
                disponibilAlb += this->getMasura();
            else if(tip == "Rosu" || tip == "rosu")
                disponibilRosu += this->getMasura();
        }
        else if(brand != "\0"){
            this->brand = v.brand;
            this->tip = v.tip;
            setMasura(v.getMasura());
            setPret(v.getPret());
        }
        return v;
    }
    void afisare(){
        Produs<T>::afisare();
        cout<<"Tipul vinului: "<<tip<<endl;
        if(brand != "\0")
            cout<<"Brandul vinului: "<<brand<<endl;
    }
    static double getDisponibilAlb(){
        return disponibilAlb;
    }
    static double getDisponibilRosu(){
        return disponibilRosu;
    }
    int calculeazaCerinta(T& cerinta){
        if(this->getMasura() > cerinta && brand == "\0"){
            setMasura(this->getMasura() - cerinta);
        if(tip == "Rosu" || tip == "rosu")
            disponibilRosu -= cerinta;
        else if(tip == "Alb" || tip == "alb")
            disponibilAlb -= cerinta;
        cerinta = 0;
        return 1;
     }
    else if(this->getMasura() <= cerinta && brand == "\0"){
        cerinta -= this->getMasura();
        delete this;
        return 2;
    }
    else if(brand != "\0"){
        cerinta--;
        delete this;
        return 1;
    }
    return 0;
}

};

#endif // VIN_H_INCLUDED
