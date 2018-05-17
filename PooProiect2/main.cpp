#include "Varza.h"
#include "Faina.h"
#include "Bere.h"
#include "Vin.h"
#include "Jucarii.h"
#include "Cartofi.h"
#include <exception>
#include <typeinfo>
int main()
{
    int n;
    double pret;
    Produs<double> *Temporal;
    Produs<int> *Verze, **Beri, **jucarii, *VinSoi;
    Produs<double> *faina, **cartofi, *VinButoi;
    cout << "Introduceti numarul de verze din magazin " << endl;
    cin >> n;
    cout << "Introduceti pretul/varza " << endl;
    cin >> pret;
    Verze = new Varza(n, pret);
    faina = new Faina[4];
    for(int i = 1 ; i <= 3 ; i++){
        cout << "Introduceti cate kg de faina de calitate " << i << " sunt disponibile in magazin "<< endl;
        cin >> n;
        cout << "Introduceti pretul/kg de faina cal "<< i << endl;
        cin >> pret;
        Temporal = new Faina(i, n, pret);
        try{
            static_cast<Faina&>(faina[i]) = *(dynamic_cast<Faina*>(Temporal));

        }
        catch(bad_cast& e){
            cout << e.what() << endl;

        }
        delete Temporal;
    }
    cout << "Introduceti numarul de doze de bere "<< endl;
    cin >> n;
    Beri = new Produs<int>*[n+1];
    for(int i = 1 ; i <= n ; i++){
        string brand, tip;
        cout << "Introduceti numele brandului " << endl;
        cin >> brand;
        cout << "Introduceti tipul berii(blonda/bruna) " << endl;
        cin >> tip;
        cout << "Introduceti pretul " << endl;
        cin >> pret;
        Beri[i] = new Bere(1, pret, brand, tip);
    }
    cartofi = new Produs<double>*[3];
      for(int i = 1 ; i <= 2 ; i++){
        string culoare;
        if(i == 1)
            culoare = "rosii";
        else culoare = "albi";
        cout << "Introduceti cate kg de cartofi de culoare "<<culoare<<" sunt disponibile in magazin "<< endl;
        cin >> n;
        cout << "Introduceti pretul/kg de cartofi " << culoare << endl;
        cin >> pret;
        cartofi[i] = new Cartofi(n, pret, culoare);
    }
    cout << "Introduceti numarul de jucarii din magazin " << endl;
    cin >> n;
    jucarii = new Produs<int>*[n+1];
    for(int i = 1 ; i <= n ; i++){
        try{
            jucarii[i] = new Jucarii;
        }
        catch(bad_alloc& e){
            cout << e.what() << endl;
        }
        cin >> *dynamic_cast<Jucarii*>(jucarii[i]);
    }

    return 0;
}
