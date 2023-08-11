#include <iostream>
#include "../Uzd.GG/head.h"
using namespace std;

void test1() {
    elem *first=NULL, *last = NULL;
    int a[]={1,2,3,4,5,0};
    for(int i=0; a[i]!=0; i++){  /// (a) Ievada elementus sarakstâ kamer nav ievadita nulle(0)
        elem *p=new elem;
        p->num=a[i];
        p->next=NULL;
        if(first==NULL){ /// Pirma elementa ievadisana sarakstaa
            first=last=p;
        }
        else { /// Parejo elementu ievadisana sarakstaa
            last->next=p;
            last=p;
        }
    }
    deleteElem(first);
}
void test2() {
    elem *first=NULL, *last = NULL;
    int a[]={5,4,3,2,1,0};
    for(int i=0; a[i]!=0; i++){  /// (a) Ievada elementus sarakstâ kamer nav ievadita nulle(0)
        elem *p=new elem;
        p->num=a[i];
        p->next=NULL;
        if(first==NULL){ /// Pirma elementa ievadisana sarakstaa
            first=last=p;
        }
        else { /// Parejo elementu ievadisana sarakstaa
            last->next=p;
            last=p;
        }
    }
    deleteElem(first);
}
void test4() {
    try {
        elem *first=NULL, *last = NULL;
        int a[]={0};
        for(int i=0; a[i]!=0; i++){  /// (a) Ievada elementus sarakstâ kamer nav ievadita nulle(0)
            elem *p=new elem;
            p->num=a[i];
            p->next=NULL;
            if(first==NULL){ /// Pirma elementa ievadisana sarakstaa
                first=last=p;
            }
            else { /// Parejo elementu ievadisana sarakstaa
                last->next=p;
                last=p;
            }
        }
        deleteElem(first);
    }catch(const char *msg){
        cout<<msg<<endl;
    }
    catch(...) {
        cout<<"Wrong Error thrown OK"<<endl;
    }
}
void test3() {
    elem *first=NULL, *last = NULL;
    int a[]={-11,2,-13,4,-100,0};
    for(int i=0; a[i]!=0; i++){  /// (a) Ievada elementus sarakstâ kamer nav ievadita nulle(0)
        elem *p=new elem;
        p->num=a[i];
        p->next=NULL;
        if(first==NULL){ /// Pirma elementa ievadisana sarakstaa
            first=last=p;
        }
        else { /// Parejo elementu ievadisana sarakstaa
            last->next=p;
            last=p;
        }
    }
    deleteElem(first);
}


int main()
{
    test1(); //int a[]={1,2,3,4,5,0};
    test2(); //int a[]={5,4,3,2,1,0};
    test3(); //int a[]={-11,2,-13,4,-100,0};
    test4(); //int a[]={0};  ---> outputs msg "List is empty"
}

