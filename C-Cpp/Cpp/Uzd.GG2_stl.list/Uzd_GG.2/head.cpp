#include "head.h"
void deleteElem(std::__cxx11::list<int>& saraksts){ /// funkcija G18
    std::__cxx11::list<int>::iterator b;
    int i = 1;
    if(saraksts.empty()) throw "List is empty";
    for (b=saraksts.begin(); b!=saraksts.end();++b){
        int pag = *b;
        if (pag==i){ /// izdzes elementus, ja tie ir vienadi ar kartas sk.
            b=saraksts.erase(b);
            --b; /// kad izdzes elementu, ta vietu aiznem nakamais elements, tadel, lai vinu neizlaistu, raksta --b
        }
        ++i;
    }
}
