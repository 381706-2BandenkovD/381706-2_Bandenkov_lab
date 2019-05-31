#ifndef __TSCANTABLE_H__
#define __TSCANTABLE_H__

#include <iostream>
#include <TTabRecord.h>
#include <TExeption.h>

template <class ValType> class TSortTable;

using namespace std;

template<class ValType>
class TScanTable
{
protected:
  int dataCount;
  int tabSize;
  TTabRecord<ValType>** pRecs;
public:
  TScanTable(int size = 2);
  TScanTable(TScanTable<ValType> &st);
  ~TScanTable();
  int Add(TTabRecord<ValType> *tr);
  void Delete(TKey k);
  int GetTabSize();
  int GetDataCount();
  TTabRecord<ValType>* Search(TKey k);
  ValType* operator[] (TKey k);
  friend ostream& operator<<(ostream &os, const TScanTable &q)
  {
    if (q.dataCount == 0)
      return os;
    for (int i = 0; i < q.dataCount - 1; i++)
    {
      os << "Key :" << q.pRecs[i]->GetKey();
      os << " val :" << *q.pRecs[i]->GetVal();
      os << endl;
    }
    os << "Key :" << q.pRecs[q.dataCount - 1]->GetKey();
    os << " val :" << *q.pRecs[q.dataCount - 1]->GetVal();
    return os;
  }
  friend class TSortTable<ValType>;
};

template<class ValType>
TScanTable<ValType>::TScanTable(int size)
{
  tabSize = size;
  dataCount = 0;
  if (size < 1)
    throw TExeption(DataErr);
  pRecs = new TTabRecord<ValType>*[size];
  for (int i = 0; i < size; i++)
  {
    pRecs[i] = NULL;
  }
}

template<class ValType>
TScanTable<ValType>::TScanTable(TScanTable<ValType> &st)
{
  dataCount = st.dataCount;
  tabSize = st.tabSize;
  pRecs = new TTabRecord<ValType>*[tabSize];
  for (int i = 0; i < dataCount; i++)
    pRecs[i] = new TTabRecord<ValType>(*pRecs[i]);
}

template<class ValType>
TScanTable<ValType>::~TScanTable()
{
  if (pRecs != NULL)
  {
    for (int i = 0; i < dataCount; i++)
      delete pRecs[i];
    delete[]pRecs;
  }
}

template<class ValType>
int TScanTable<ValType>::Add(TTabRecord<ValType>* tr)
{
  if (tabSize == dataCount - 1)
    throw TExeption(DataNoMem);
  pRecs[dataCount] = tr;
  return dataCount++;
}

template<class ValType>
void TScanTable<ValType>::Delete(TKey k)
{
  if (dataCount == 0)
    throw TExeption(DataEmpty);
  for (int i = 0; i < dataCount; i++) {
    if (pRecs[i]->key == k)
    {
      delete pRecs[i];
      pRecs[i] = NULL;
      for (int j = i; j < dataCount - 1; j++)
        pRecs[j] = pRecs[j + 1];
    }
    dataCount--;
  }
}

template<class ValType>
int TScanTable<ValType>::GetTabSize()
{
  return tabSize;
}

template<class ValType>
int TScanTable<ValType>::GetDataCount()
{
  return dataCount;
}

template<class ValType>
TTabRecord<ValType> * TScanTable<ValType>::Search(TKey k)
{
  for (int i = 0; i < dataCount; i++)
  {
    if (pRecs[i]->key == k)
      return pRecs[i];
  }
  return NULL;
}

template<class ValType>
ValType* TScanTable<ValType>::operator[](TKey k)
{
  TTabRecord<ValType>* res = Search(k);
  if (res == NULL) 
  {
    TTabRecord<ValType> *n = new TTabRecord<ValType>(k, NULL, true);
    Add(n);
    res = pRecs[dataCount - 1];
  }
  return res->value;
}
#endif