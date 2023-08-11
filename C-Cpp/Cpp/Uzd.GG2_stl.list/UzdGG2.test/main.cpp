#include <iostream>
#include <list>
#include "../Uzd_GG.2/head.h"

using namespace std;

void test1() {
    list<int> saraksts;
    int a[]={1,2,3,4,5,0};
    for(int i=0; a[i]!=0; i++){ /// (a) Ievada elementus sarakstâ kamer nav ievadita nulle(0)
        saraksts.push_back(a[i]); /// Elementu ievadisana sarakstaa
    }
    deleteElem(saraksts);
}
void test2() {
    int a[]={5,4,3,2,1,0};
    list<int> saraksts;
    for(int i=0; a[i]!=0; i++){ /// (a) Ievada elementus sarakstâ kamer nav ievadita nulle(0)
        saraksts.push_back(a[i]); /// Elementu ievadisana sarakstaa
    }
    deleteElem(saraksts);
}
void test4() {
    int a[]={0};
    list<int> saraksts;
    try {
        for(int i=0; a[i]!=0; i++){ /// (a) Ievada elementus sarakstâ kamer nav ievadita nulle(0)
            saraksts.push_back(a[i]); /// Elementu ievadisana sarakstaa
        }
        deleteElem(saraksts);
    }catch(const char *msg){
        cerr<<msg<<endl;
    }
    catch(...) {
        cout<<"Wrong Error thrown OK"<<endl;
    }
}
void test3() {
    int a[]={-11,2,-13,4,-100,0};
    list<int> saraksts;
    for(int i=0; a[i]!=0; i++){ /// (a) Ievada elementus sarakstâ kamer nav ievadita nulle(0)
        saraksts.push_back(a[i]); /// Elementu ievadisana sarakstaa
    }
    deleteElem(saraksts);
}


int main()
{
    test1(); //int a[]={1,2,3,4,5,0};
    test2(); //int a[]={5,4,3,2,1,0};
    test3(); //int a[]={-11,2,-13,4,-100,0};
    test4(); //int a[]={0}; ---> outputs msg "List is empty"
}
