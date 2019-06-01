#ifndef __TTREETABLE_H__
#define __TTREETABLE_H__

#include <iostream>
#include <TTreeNode.h>
#include <TExeption.h>
#include <TListStack.h>

using namespace std;


template<class ValType>
class TTreeTable
{
private:
  TTreeNode<ValType>* pRoot;
  TTreeNode<ValType>** ppRef;
  int dataCount;
public:
  TTreeTable();
  ~TTreeTable();
  void Add(TTreeNode<ValType> *tr);
  void Delete(TKey k);
  int GetDataCount();
  TTreeNode<ValType>* Search(TKey k);
  ValType* operator[] (TKey k);
  void Print();
  void Print(TTreeNode<ValType>* t);
};

template<class ValType>
TTreeTable<ValType>::TTreeTable()
{
  dataCount = 0;
  pRoot = NULL;
}

template<class ValType>
TTreeTable<ValType>::~TTreeTable()
{
  TListStack<TTreeNode<ValType>*> st;
  if (pRoot == NULL)
    return;
  TTreeNode<ValType> *pDel = pRoot;
  st.Put(pDel);
  while (!st.IsEmpty())
  {
    pDel = st.Get();
    if (pDel->pLeft)
      st.Put(pDel->pLeft);
    if(pDel->pRight)
      st.Put(pDel->pRight);
    delete pDel;
  }
}

template<class ValType>
void TTreeTable<ValType>::Add(TTreeNode<ValType>* tr)
{
  if (Search(tr->key))
    throw TExeption(DataErr);
  *ppRef = tr;
}

template<class ValType>
void TTreeTable<ValType>::Delete(TKey k)
{
  if (!Search(k))
    throw TExeption(DataErr);
  TTreeNode<ValType>* tmp = *ppRef;
  TTreeNode<ValType>** buff = ppRef;
  if (tmp->pLeft != NULL)
  {
    TTreeNode<ValType>* tmp3 = (*ppRef)->pRight;
    TTreeNode<ValType>* tmp4;
    TTreeNode<ValType>* buff = tmp->pLeft;
    delete *ppRef;
    *ppRef = buff;
    tmp = *ppRef;
    while ((tmp != NULL))
    {
      tmp4 = tmp->pRight;
      tmp->pRight = tmp3;
      tmp3 = tmp4;
      tmp = tmp->pLeft;
    }
  }
  else if (tmp->pRight != NULL)
  {
    **ppRef = *tmp->pRight;
    delete *ppRef;
  }
  else
  {
    delete *ppRef;
    *ppRef = NULL;
  }
}

template<class ValType>
int TTreeTable<ValType>::GetDataCount()
{
  return dataCount;
}

template<class ValType>
TTreeNode<ValType>* TTreeTable<ValType>::Search(TKey k)
{
  TTreeNode<ValType>* pTemp = pRoot;
  ppRef = &pRoot;
  while (pTemp != NULL)
  {
    if (pTemp->key == k)
      return pTemp;
    if (pTemp->key > k)
      ppRef = &(pTemp->pRight);
    else
      ppRef = &(pTemp->pLeft);
    pTemp = *ppRef;
  }
  return NULL;
}

template<class ValType>
ValType * TTreeTable<ValType>::operator[](TKey k)
{
  TTreeNode<ValType>* res = Search(k);
  if (res == NULL)
  {
    TTreeNode<ValType>* n = new TTreeNode<ValType>(k, NULL);
    Add(n);
    return n->value;
  }
  return res->value;;
  return NULL;
}

template<class ValType>
void TTreeTable<ValType>::Print()
{
  Print(pRoot);
}

template<class ValType>
void TTreeTable<ValType>::Print(TTreeNode<ValType>* t)
{
  if (t != NULL)
  {
    Print(t->pLeft);
    std::cout << "Key :" << t->GetKey();
    std::cout << " val :" << *t->GetVal();
    Print(t->pRight);
  }
}

#endif