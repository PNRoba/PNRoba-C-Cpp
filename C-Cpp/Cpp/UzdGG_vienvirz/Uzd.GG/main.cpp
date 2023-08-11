#include <iostream>
#include "head.h"
#include "head.cpp"
using namespace std;

/**
==============================================================================
Paula Roba, pr19015  ---> (1) vienvirziena saistitais saraksts
=== GG18 ======================================================================
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
GG18. Uzrakstît funkciju, kas izmet no saraksta tos elementus, kuriem vçrtîba vienâda ar to kârtas numuru.
**/

void printList(elem *first){  /// funkcija saraksta drukasanai uz ekrana
    elem *p = first;
    while(p){
        cout << p->num << " ";
        p = p->next;
    }
    cout << endl;
}

void deleteList(elem *&first){ /// saraksta dzesanas funkcija
    elem *p=first;
    while(p!=NULL){
        elem *yes = first;
        first = first->next;
        delete yes;
        p=p->next;
    }
}



int main()
{
    elem *first=NULL, *last = NULL;
    int a;
    cin>>a;
    for(int i=0; a!=0; i++){  /// (a) Ievada elementus sarakstâ kamer nav ievadita nulle(0)
        elem *p=new elem;
        p->num=a;
        p->next=NULL;
        if(first==NULL){ /// Pirma elementa ievadisana sarakstaa
            first=last=p;
        }
        else { /// Parejo elementu ievadisana sarakstaa
            last->next=p;
            last=p;
        }
        cin>>a; /// Ievada nakamo elementu, for cikls parbauda vai nav nulle

    }
    cout<<"Saraksta saturs:"<<endl;
    printList(first);
    deleteElem(first); /// (b)
    cout<<"Saraksta saturs, iznemot elementus kuri vienadi ar kartas sk.:"<<endl;
    printList(first); /// (c)
    deleteList(first); /// (d)
    cout<<"Saraksta saturs pec dzesanas:"<<endl;
    printList(first); /// Parbauda vai saraksts ir izdzests, to izdrukajot
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
