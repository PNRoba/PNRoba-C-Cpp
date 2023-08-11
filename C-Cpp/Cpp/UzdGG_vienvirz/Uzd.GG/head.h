#ifndef HEAD_H_INCLUDED
#define HEAD_H_INCLUDED
struct elem{
    int num;
    elem *next;
};

void deleteElem(elem *&);
#endif
