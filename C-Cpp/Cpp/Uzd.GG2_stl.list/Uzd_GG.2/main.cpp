#include <iostream>
#include <list>
#include "head.h"
#include "head.cpp"
using namespace std;

/**
==============================================================================
Paula Roba, pr19015  ---> (2) STL::list
=== G18 ======================================================================
Izveidot divas programmas valodâ C++, kas strâdâ ar vçrtîbu virkni divos daþâdos veidos:
  1) to realizçjot kâ vienvirziena saistîto sarakstu, izmantojot dinamiskas datu struktûras,
  2) izmantojot STL::list konteineru.
Abâs realizâcijâs ir jâizveido prasîtâ specifiskâ vçrtîbu virknes apstrâdes funkcija un jânodemonstrç tâ darbîbâ,
cita starpâ parâdot gan sâkotnçjâs, gan rezultçjoðâs vçrtîbas.
Abâs programmâs:
  a) jâbût iespçjai ievadît saraksta elementus (izveidot patvaïîgu sarakstu),
  b) jâpielieto uzrakstîtâ funkcija sarakstam,
  c) jâizdrukâ saraksts pçc funkcijas darbîbas.
  d) beigâs jâiznîcina saraksts - korekti jâatbrîvo izdalîtâ atmiòa(lietojot delete vai clear).
Sîkâkas prasîbas sk. Laboratorijas darbu noteikumos.
==============================================================================
G18. Uzrakstît funkciju, kas izmet no saraksta tos elementus, kuriem vçrtîba vienâda ar to kârtas numuru.
**/

void printList(list <int>& saraksts){ /// funkcija saraksta drukasanai uz ekrana
    list<int>::iterator a;
    for (a=saraksts.begin(); a!=saraksts.end();++a){
        cout << *a <<endl;
    }
}

int main()
{
    list<int> saraksts;
    list<int>::iterator a;

    int c;
    cin>>c;
    for(int i=0; c!=0; i++){ /// (a) Ievada elementus sarakstâ kamer nav ievadita nulle(0)
        saraksts.push_back(c); /// Elementu ievadisana sarakstaa
        cin>>c;
    }
    cout<<"Saraksta saturs:"<<endl;
    printList(saraksts);
    deleteElem(saraksts); /// (b)
    cout<<"Saraksta saturs, iznemot elementus kuri vienadi ar kartas sk.:"<<endl;
    printList(saraksts); /// (c)
    cout<<"Saraksta saturs pec dzesanas:"<<endl;
    saraksts.clear(); /// (d)
    printList(saraksts); /// Parbauda vai saraksts ir izdzests, to izdrukajot

    return 0;
}

    /**
    ==============================================================================
    Testi
    ievade                      izvade
    ==============================================================================
    1 2 3 4 5 0                 Saraksta saturs:
                                1 2 3 4 5
                                Saraksta saturs, iznemot elementus kuri vienadi ar kartas sk.:
                                Saraksta saturs pec dzesanas:
    ==============================================================================
    5 4 3 2 1 0                 Saraksta saturs:
                                5 4 3 2 1
                                Saraksta saturs, iznemot elementus kuri vienadi ar kartas sk.:
                                5 4 2 1
                                Saraksta saturs pec dzesanas:
    ==============================================================================
    -11 2 -13 4 -100 0          Saraksta saturs:
                                -11 2 -13 4 -100
                                Saraksta saturs, iznemot elementus kuri vienadi ar kartas sk.:
                                -11 -13 -100
                                Saraksta saturs pec dzesanas:
    ==============================================================================
    0                           Saraksta saturs:
                                List is empty
                                Saraksta saturs, iznemot elementus kuri vienadi ar kartas sk.:
                                Saraksta saturs pec dzesanas:
    ==============================================================================
    **/
