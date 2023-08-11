// K2_B1.cpp
/*********************************************************************************
B. Uzrakstît C++ programmu, kurâ tiek veidota klaðu hierarhija (Darbinieks-Direktors),
kurâ klase Direktors manto no klases Darbinieks.
Klasei Darbinieks jâsatur skaitlisks lauks ApliecibasNumurs.
Klasei Direktors jâsatur lauks - simbolu virkòu masîvs Apbalvojumi.
Katrai klasei jârealizç sekojoðas metodes: konstruktors, destruktors un print metode.
Visiem laukiem jâbût ar specifikatoriem private/protected.
Programmâ jâveido katras klases objekti un katra metode jâizsauc vismaz vienreiz.
B2[9]. Lauks Apbalvojumi ar dinamisku atmiòu – patvaïîgs skaits apbalvojumu.
************************************************************************************/
#include<iostream>

using namespace std;
class Darbinieks{
    int ApliecibasNumurs;
public:
    Darbinieks( int an) {
        ApliecibasNumurs = an;
    }
    ~Darbinieks() {}
    void print() {
        cout<<"Apliecîbas numurs: "<<ApliecibasNumurs<<endl;
    }
};
class Direktors: public Darbinieks {
    int apbalvSkaits;
    string* Apbalvojumi;
public:
    Direktors(int an, int apbSkaits, const string* apb):Darbinieks(an) {
        apbalvSkaits = apbSkaits;
        Apbalvojumi = new string[apbalvSkaits];
        for(int i=0;i<apbalvSkaits;i++) Apbalvojumi[i] = apb[i];
    }
    ~Direktors() {cout << "Atbrîvo atmiòu" << endl;delete []Apbalvojumi;}
    void print() {
        Darbinieks::print();
        cout << "Apbalvojumi:" << endl;
        for (int i=0;i<apbalvSkaits;i++) cout<<Apbalvojumi[i]<<endl;
        cout << endl;
    }

};
int main() {
    const string veikumi[2]= {"1.vieta novusâ 2019", "Gada cilvçks 2020"};
    Darbinieks d(17);
    d.print();              // Apliecîbas numurs: 17
    cout<<endl;
    Direktors dir(105, 2, veikumi);
    dir.print();              // Apliecîbas numurs: 105 Apbalvojumi: 1.vieta novusâ 2019 Gada cilvçks 2020
}
