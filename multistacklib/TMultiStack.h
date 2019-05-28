#ifndef __MULTISTACK_H
#define __MULTISTACK_H
#include "MStack.h"
#include <TExeption.h>

template <class ValType>
class TMultiStack
{
protected:
    MStack <ValType> ** pStack; // стеки - память выделяется из StackMem
    int memSize; // всего выделено памяти
    ValType** stackInd;
    int relocationCount;
    int currentCount; // число элементов в мультистеке в данный момент
    int *stackTops;
    int stackCount; // число стеков
    ValType* stackMem; // память под стек
protected: // поля и методы для перепаковки
    ValType * * pStackMem; // базовые адреса для памяти стеков
    void StackRelocation(int nst); // перепаковка памяти
    int GetFreeMemSize(); // оценка объема свободной памяти
public:
    TMultiStack(int Size = 100, int Count = 10);
    TMultiStack(TMultiStack &ms);
    ~TMultiStack();
    int IsEmpty(int ns) const; // контроль пустоты СД
    int IsFull(int ns) const; // контроль переполнения СД
    int operator==(const TMultiStack &ms); // сравнение
    TMultiStack & operator= (const TMultiStack &ms); // присванивание
    void Put(int ns, const ValType &Val); // положить в стек 
    ValType Get(int ns); // взять из стека с удалением
    void Print();
    int GetRelocationCount() { return relocationCount; }
};

template <class ValType>
void TMultiStack<ValType>::Print()
{
    for (int i = 0; i < stackCount; i++)
    {
        pStack[i]->Print();
    }
}

template<class ValType>
int  TMultiStack<ValType>::GetFreeMemSize()
{
    return memSize - currentCount;
}

template<class ValType>
TMultiStack<ValType>::TMultiStack(int Size, int count)
{
    if ((Size <= 0) || (count <= 0))
        throw 1;
    memSize = Size;
    relocationCount = 0;
    currentCount = 0;
    stackCount = count;
    stackTops = new int[stackCount];
    for (int i = 0; i < stackCount; i++)
        stackTops[i] = 0;
    stackInd = new ValType*[stackCount];
    pStackMem = new ValType*[stackCount];
    pStack = new MStack<ValType>*[stackCount];
    stackMem = new ValType[memSize];
    int TmpSize = memSize / stackCount;
    stackInd[0] = stackMem;
    pStack[0] = new MStack<ValType>(stackInd[0], TmpSize);
    for (int i = 1; i < stackCount - 1; i++)
    {
        stackInd[i] = stackInd[i - 1] + TmpSize;
        pStack[i] = new MStack<ValType>(stackInd[i], TmpSize);
    }
    stackInd[stackCount - 1] = stackInd[stackCount - 2] + TmpSize;
    pStack[stackCount - 1] = new MStack<ValType>(stackInd[stackCount - 1], TmpSize + memSize % stackCount);
}

template<class ValType>
TMultiStack<ValType>::TMultiStack(TMultiStack & ms)
{
    memSize = ms.memSize;
    currentCount = ms.currentCount;
    relocationCount = ms.relocationCount;
    stackCount = ms.stackCount;
    stackTops = new int[stackCount];
    for (int i = 0; i < stackCount; i++)
        stackTops[i] = ms.stackTops[i];
    stackInd = new ValType*[stackCount];
    pStackMem = new ValType*[stackCount];
    pStack = new MStack<ValType>*[stackCount];
    stackMem = new ValType[memSize];
    int TmpSize = memSize / stackCount;
    stackInd[0] = stackMem;
    pStack[0] = new MStack<ValType>(stackInd[0], TmpSize);
    for (int i = 1; i < stackCount - 1; i++)
    {
        stackInd[i] = stackInd[i - 1] + TmpSize;
        pStack[i] = new MStack<ValType>(stackInd[i], TmpSize);
    }
    stackInd[stackCount - 1] = stackInd[stackCount - 2] + TmpSize;
    pStack[stackCount - 1] = new MStack<ValType>(stackInd[stackCount - 1], TmpSize + memSize % stackCount);
    stackMem = new ValType[memSize];
    for (int i = 0; i < memSize; i++)
        pStack[i] = ms.pStack[i];
}

template<class ValType>
TMultiStack<ValType>::~TMultiStack()
{
    delete[] pStack;
    delete[] stackMem;
    delete[]stackTops;
    delete[]stackInd;
}

template<class ValType>
int TMultiStack<ValType>::IsEmpty(int ns) const
{
    return pStack[ns]->IsEmpty();
}

template<class ValType>
int TMultiStack<ValType>::IsFull(int ns) const
{
    return pStack[ns]->IsFull();
}

template<class ValType>
int TMultiStack<ValType>::operator==(const TMultiStack & ms)
{
    if (memSize != ms.memSize)
        return 0;
    if (stackCount != ms.stackCount)
        return 0;
    for (int i = 0; i < currentCount; i++)
        if (stackMem[i] != ms.stackMem[i])
            return 0;
    return 1;
}

template<class ValType>
void TMultiStack<ValType>::StackRelocation(int nst)
{
    int l;
    stackTops[nst] += 1;
    int temp = GetFreeMemSize() - 1;
    if (temp > -1)
    {
        pStackMem[0] = &stackMem[0];
        for (int i = 1; i < stackCount; i++)
            pStackMem[i] = pStackMem[i - 1] + stackTops[i - 1] + temp / stackCount;
    }
    for (int i = 0; i < stackCount; i++)
        if (pStackMem[i] < stackInd[i])
        {
            for (int k = 0; k < stackTops[i]; k++)
                pStackMem[i][k] = stackInd[i][k];
            if (i != stackCount - 1)
                pStack[i]->SetMem(pStackMem[i], pStackMem[i + 1] - pStackMem[i]);
            stackInd[i] = pStackMem[i];
        }
        else if (pStackMem[i] > stackInd[i])
        {
            for (l = i; pStackMem[l + 1] > stackInd[l + 1]; l++)
                if (l == stackCount - 1)
                {
                    break;
                }
            for (int k = l; k >= i; k--)
            {
                for (int j = (stackTops[k] - 1); j >= 0; j--)
                    pStackMem[k][j] = stackInd[k][j];
                if (k != stackCount - 1)
                    pStack[k]->SetMem(pStackMem[k], pStackMem[k + 1] - pStackMem[k]);
                stackInd[k] = pStackMem[k];
            }
        }
        else
        {
            if (i != stackCount - 1)
                pStack[i]->SetMem(pStackMem[i], pStackMem[i + 1] - pStackMem[i]);
        }
    pStack[stackCount - 1]->SetMem(pStackMem[stackCount - 1], memSize - (pStackMem[stackCount - 1] - pStackMem[0]));
    stackTops[nst] -= 1;
    relocationCount++;
}

template<class ValType>
TMultiStack<ValType> & TMultiStack<ValType>::operator=(const TMultiStack & ms)
{
    if (&ms != this)
    {
        memSize = ms.memSize;
        relocationCount = ms.relocationCount;
        stackCount = ms.stackCount;
        currentCount = ms.currentCount;
        stackTops = new int[stackCount];
        for (int i = 0; i < stackCount; i++)
            stackTops[i] = ms.stackTops[i];
        stackInd = new ValType*[stackCount];
        pStackMem = new ValType*[stackCount];
        pStack = new MStack<ValType>*[stackCount];
        stackMem = new ValType[memSize];
        int TmpSize = memSize / stackCount;
        stackInd[0] = stackMem;
        pStack[0] = new MStack<ValType>(stackInd[0], TmpSize);
        for (int i = 1; i < stackCount - 1; i++)
        {
            stackInd[i] = stackInd[i - 1] + TmpSize;
            pStack[i] = new MStack<ValType>(stackInd[i], TmpSize);
        }
        stackInd[stackCount - 1] = stackInd[stackCount - 2] + TmpSize;
        pStack[stackCount - 1] = new MStack<ValType>(stackInd[stackCount - 1], TmpSize + memSize % stackCount);
        for (int i = 0; i < memSize; i++)
            stackMem[i] = ms.stackMem[i];
    }
    return *this;
}

template<class ValType>
void TMultiStack<ValType>::Put(int ns, const ValType & Val)
{
    if (GetFreeMemSize() == 0)
        throw TExeption(DataNoMem);
    if (pStack[ns]->IsFull())
        StackRelocation(ns);
    pStack[ns]->Put(Val);
    stackTops[ns]++;
    currentCount++;
}

template<class ValType>
ValType TMultiStack<ValType>::Get(int ns)
{
    stackTops[ns]--;
    currentCount--;
    return pStack[ns]->Get();
}
#endif

