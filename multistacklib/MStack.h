#ifndef __MSTACK_H
#define __MSTACK_H

#include <TStack.h> 

template <class ValType>
class MStack : public TStack<ValType>
{
public:
    MStack(ValType* ind = NULL, int Size = 0);
    void SetMem(ValType* ind, int Size);
    ~MStack();
};

template<class ValType>
MStack<ValType>::MStack(ValType * ind, int Size)
{
    this->mem = ind;
    this->top = -1;
    this->memSize = Size;
}


template<class ValType>
void MStack<ValType>::SetMem(ValType * ind, int Size)
{
    this->mem = ind;
    this->memSize = Size;
}
template<class ValType>
MStack<ValType>::~MStack()
{
    this->mem = NULL;
}
#endif
