#ifndef __TSORTTABLE_H__
#define __TSORTTABLE_H__

#include <iostream>
#include <TExeption.h>
#include <TScanTable.h>


enum SortType
{QUICK, MERGE, INSERT};

template<class ValType>
class TSortTable
{
protected:
  int dataCount;
  int tabSize;
  SortType type;
  TTabRecord<ValType>** pRecs;
  void MergeSort(TTabRecord<ValType>** nRecs, int dC);
  void MergeSorter(TTabRecord<ValType>** &pData, TTabRecord<ValType>** &pBuff, int size);
  void MergeData(TTabRecord<ValType>** &pData, TTabRecord<ValType>** &pBuff, int n1, int n2);
  void InsertSort(TTabRecord<ValType>** nRecs, int dC);
  void QuickSort(TTabRecord<ValType>** nRecs, int dC);
  void QuickSplit(TTabRecord<ValType>** pData, int size, int &pivot);
public:
  TSortTable(int size = 2);
  TSortTable(TScanTable<ValType> &st);
  ~TSortTable();
  void SetSortType(SortType t);
  void SortData();
  TSortTable& operator = (const TScanTable<ValType> &st);
  int Add(TTabRecord<ValType> *tr);
  void Delete(TKey k);
  TTabRecord<ValType>* Search(TKey);
  ValType * operator[] (TKey);

  friend ostream& operator<<(ostream &os, const TSortTable &q)
  {
    for (int i = 0; i < q.dataCount; i++)
    {
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
    return os;
  }
};


template<class ValType>
void TSortTable<ValType>::MergeSort(TTabRecord<ValType>** nRecs, int dC)
{
  TTabRecord<ValType>** pData = nRecs;
  TTabRecord<ValType>** pBuff = new TTabRecord<ValType>*[dC];
  TTabRecord<ValType>** pTemp = pBuff;
  MergeSorter(pData, pBuff, dC);
  if (pData == pTemp)
    for (int i = 0; i < dC; i++)
      pBuff[i] = pData[i];
  delete pTemp;
}

template<class ValType>
void TSortTable<ValType>::MergeSorter(TTabRecord<ValType>** &pData, TTabRecord<ValType>** &pBuff, int size)
{
  int n1 = (size + 1) / 2;
  int n2 = size - n1;
  if (size > 2)
  {
    TTabRecord<ValType>** pDat2 = pData + n1;
    TTabRecord<ValType>** pBuff2 = pBuff + n1;
    MergeSorter(pData, pBuff, n1);
    MergeSorter(pDat2, pBuff2, n2);
  }
  MergeData(pData, pBuff, n1, n2);
}

template<class ValType>
void TSortTable<ValType>::MergeData(TTabRecord<ValType>**& pData, TTabRecord<ValType>**& pBuff, int n1, int n2)
{
  TTabRecord<ValType>** pDat2 = pData + n1;
  int i = 0, j = 0, k = 0;
  while((i < n1) && (j < n2))
  {
    if (*pData[i] > *pDat2[j])
    {
      pBuff[k] = pData[i];
      k++;
      i++;
    }
    else
    {
      pBuff[k] = pDat2[j];
      k++;
      j++;
    }
  }
  if(i < n1)
    for (; i < n1; i++)
    {
      pBuff[k] = pData[i];
      k++;
    }
  else if (j < n2)
  {
    for (; j < n1; j++)
    {
      pBuff[k] = pData[i];
      k++;
    }
  }
  TTabRecord<ValType>** pTemp = pData;
  pData = pBuff;
  pBuff = pTemp;
}

template<class ValType>
void TSortTable<ValType>::InsertSort(TTabRecord<ValType>** nRecs, int dC)
{
  TTabRecord<ValType>* pR;
  for (int i = 1, j; i < dC; i++)
  {
    pR = nRecs[i];
    for (j = i - 1; j > -1; j--)
    {
      if (*nRecs[i] > *pR)
        nRecs[j + 1] = nRecs[j];
      else
        break;
    }
    nRecs[j + 1] = pR;
  }
}

template<class ValType>
void TSortTable<ValType>::QuickSort(TTabRecord<ValType>** nRecs, int dC)
{
  int pivot;
  int n1, n2;
  if (dC > 1)
  {
    QuickSplit(nRecs, dC, pivot);
    n1 = pivot + 1;
    n2 = dC - n1;
    QuickSort(nRecs, n1 - 1);
    QuickSort(nRecs + n1, n2);
  }
}

template<class ValType>
void TSortTable<ValType>::QuickSplit(TTabRecord<ValType>** pData, int size, int & pivot)
{
  TTabRecord<ValType>* pPivot = pData[0];
  TTabRecord<ValType>* pTemp;
  int i1 = 1;
  int i2 = size - 1;
  while (i1 <= i2)
  {
    while ((i1 < size) && !(pData[i1]->key < pPivot->key))
      i1++;
    while (pData[i2]->key < pPivot->key)
      i2--;
    if (i1 < i2)
    {
      pTemp = pData[i1];
      pData[i1] = pData[i2];
      pData[i2] = pTemp;
    }
  }
  pData[0] = pData[i2];
  pData[i2] = pPivot;
  pivot = i2;  
}

template<class ValType>
TSortTable<ValType>::TSortTable(int size)
{
  type = QUICK;
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
TSortTable<ValType>::TSortTable(TScanTable<ValType> & st)
{
  type = QUICK;
  *this = st;
}

template<class ValType>
TSortTable<ValType>::~TSortTable()
{
  if (pRecs != NULL)
  {
    for (int i = 0; i < dataCount; i++)
      delete pRecs[i];
    delete[]pRecs;
  }
}

template<class ValType>
void TSortTable<ValType>::SetSortType(SortType t)
{
  type = t;
}

template<class ValType>
void TSortTable<ValType>::SortData()
{
  switch (type)
  {
  case QUICK:
      QuickSort(pRecs, dataCount);
      break;
  case MERGE:
    MergeSort(pRecs, dataCount);
    break;
  case INSERT:
    InsertSort(pRecs, dataCount);
    break;
  }
}

template<class ValType>
TSortTable<ValType> & TSortTable<ValType>::operator=(const TScanTable<ValType> & st)
{
  if (pRecs != NULL)
  {
    for (int i = 0; i < dataCount; i++)
      delete pRecs[i];
    delete[]pRecs;
  }
  tabSize = st.tabSize;
  dataCount = st.dataCount;
  pRecs = new TTabRecord<ValType>*[tabSize];
  for (int i = 0; i < dataCount; i++)
    pRecs[i] = new TTabRecord<ValType>(*st.pRecs[i]);
  for (int i = dataCount; i < tabSize; i++)
    pRecs[i] = NULL;
  SortData();
  return *this;
}
template<class ValType>
int TSortTable<ValType>::Add(TTabRecord<ValType> * tr)
{
  if (dataCount == tabSize)
    throw TExeption(DataNoMem);
  if (dataCount == 0)
  {
    pRecs[0] = tr;
    return dataCount++;;
  }
  int left = 0;
  int right = dataCount;
  int curr = (left + right) / 2;
  while (right - left != 1)
  {
    if (pRecs[curr]->key == tr->key)
      throw TExeption(DataErr);
    if (tr->key < pRecs[curr]->key)
      left = curr;
    else
      right = curr;
    curr = (left + right) / 2;
  }
  if(tr->key < pRecs[curr]->key)
    curr++;
  for (int i = dataCount; i > curr; i--)
    pRecs[i] = pRecs[i - 1];
  pRecs[curr] = tr;
  dataCount++;
  return curr;
}

template<class ValType>
void TSortTable<ValType>::Delete(TKey k)
{
  if (dataCount == 0)
    return;
  int left = 0;
  int right = dataCount;
  int curr = (left + right) / 2;
  while (right - left != 1)
  {
    if (pRecs[curr]->key == k)
    {
      for (int i = curr; i < dataCount - 1; i++)
        pRecs[i] = pRecs[i + 1];
      dataCount--;
    }
    if (k < pRecs[curr]->key)
      left = curr;
    else
      right = curr;
    curr = (left + right) / 2;
  }
}

template<class ValType>
TTabRecord<ValType> * TSortTable<ValType>::Search(TKey k)
{
  int left = 0;
  int right = dataCount;
  int curr = (left + right) / 2;
  while (right - left != 0)
  {
    if (pRecs[curr]->key == k)
      return pRecs[curr];
    if (k < pRecs[curr]->key)
      left = curr;
    else
      right = curr;
    curr = (left + right) / 2;
  }
  return NULL;
}

template<class ValType>
ValType * TSortTable<ValType>::operator[](TKey k)
{
  TTabRecord<ValType>* res = Search(k);
  if (res == NULL)
  {
    TTabRecord<ValType>* n = new TTabRecord<ValType>(k, NULL, true);
    Add(n);
    return n->value;
  }
  return res->value;
}
#endif