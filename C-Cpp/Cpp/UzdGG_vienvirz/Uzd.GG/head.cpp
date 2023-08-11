#include "head.h"

void deleteElem(elem *&first){ /// funkcija G18
    elem *p=first;
    int i = 1, k = 0;

    while(p!=NULL){
        if(i == first->num){ /// izdzes pirmo elementu, ja tas ir vienads ar kartas sk.
            elem *yes = first;
            first = first->next;
            delete yes;
            i++;
            if(first==NULL) k = 1;
        }
        else if (first!=NULL){ /// izdzes parejos elementus, ja tie ir vienadi ar kartas sk.
            if(i==1) i++;
            if (first->next!=NULL) {
                elem *prev = first, *now = first->next;
                while (now) {
                    if (now->num == i) {
                        elem *yes = now;
                        now=now->next;
                        prev->next = now;
                        delete yes;
                    } else {
                        prev = prev->next;
                        now = now->next;
                    }
                    if(now==NULL) k = 1;
                    i++;
                }
            }
        }
        if(k==1) break;
    }
}
