#ifndef __DATLIST_H
#define __DATLIST_H
#include <TExeption.h>
#include <TDatLink.h>

template<class ValType>
class TDatList
{
protected:
  TDatLink<ValType>* pFirst; // первое звено
  TDatLink<ValType>* pLast; // последнее звено
  int listLen; // количество звеньев в списке
protected: // методы
  TDatLink<ValType>* GetLink(ValType Val = NULL, TDatLink<ValType>* pLink = NULL);
  void DelLink(TDatLink<ValType>* pLink); // удаление звена
public:
  TDatList();
  TDatList(const TDatList& dl);
  ~TDatList() { DelList(); }
  // доступ
  ValType& GetDatValue(int num) const; // значение
  int IsEmpty() const { return pFirst == NULL; } // список пуст ?
  int GetListLength() const { return listLen; } // к-во звеньев
                                                // вставка звеньев
  void InsFirst(const ValType &Val); // вставить перед первым
  void InsLast(const ValType &Val); // вставить последним
  void InsTo(int num, const ValType& Val); // вставить на позицию
                                    // удаление звеньев
  void DelFirst(); // удалить первое звено 
  void Del(int num); // произвольное звено
  void DelList(); // удалить весь список
};

template<class ValType>
TDatLink<ValType>* TDatList<ValType>::GetLink(ValType Val, TDatLink<ValType>* pLink)
{
  TDatLink<ValType>* tmp = new TDatLink<ValType>(Val, pLink);
  return tmp;
}

template<class ValType>
void TDatList<ValType>::DelLink(TDatLink<ValType>* pLink)
{
  if (pLink)
    delete pLink;
}

template<class ValType>
TDatList<ValType>::TDatList()
{
  pFirst = NULL;
  pLast = NULL;
  listLen = 0;
}

template<class ValType>
TDatList<ValType>::TDatList(const TDatList & dl)
{
  listLen = dl.listLen;
  TDatLink<ValType>* pTemp = dl.pFirst;
  pFirst = new TDatLink<ValType>(pTemp->GetDatValue(), NULL);
  TDatLink<ValType>* TmpLast = pFirst;
  TDatLink<ValType>* TmpCurr;
  for (int i = 1; i < dl.listLen; i++)
  {
    pTemp = pTemp->GetNextLink();
    TmpCurr = new TDatLink<ValType>(pTemp->GetDatValue(), NULL);
    TmpLast->SetNextLink(TmpCurr);
    TmpLast = TmpCurr;
  }
  pLast = TmpCurr;
}

template<class ValType>
ValType& TDatList<ValType>::GetDatValue(int num) const
{
  if ((num < 0) || (num >(listLen - 1)))
    throw TExeption(DataErr);
  TDatLink<ValType>* pTemp = pFirst;
  for (int i = 0; i < num; i++)
    pTemp = pTemp->GetNextLink();
  return pTemp->GetDatValue();
}
template<class ValType>
void TDatList<ValType>::InsFirst(const ValType &Val)
{
  TDatLink<ValType>* tmp = new TDatLink<ValType>(Val, pFirst);
  pFirst = tmp;
  if (listLen == 0)
    pLast = tmp;
  listLen++;
}

template<class ValType>
void TDatList<ValType>::InsLast(const ValType& Val)
{
  TDatLink<ValType>* tmp = new TDatLink<ValType>(Val, NULL);
  if (listLen == 0)
    pFirst = tmp;
  else
    pLast->SetNextLink(tmp);
  pLast = tmp;
  listLen++;
}
template<class ValType>
void TDatList<ValType>::InsTo(int num,const ValType& Val)
{
  if ((num < 0) || (num >(listLen - 1)))
    throw TExeption(DataErr);
  if (num == 0)
    InsFirst(Val);
  else
  {
    TDatLink<ValType>* pTemp = pFirst;
    for (int i = 0; i < (num - 1); i++)
      pTemp = pTemp->GetNextLink();
    TDatLink<ValType>* tmp = new TDatLink<ValType>(Val, pTemp->GetNextLink());
    pTemp->SetNextLink(tmp);
  }
  listLen++;
}
template<class ValType>
void TDatList<ValType>::DelFirst()
{
  if (listLen)
  {
    TDatLink<ValType>* tmp = pFirst;
    pFirst = pFirst->GetNextLink();
    DelLink(tmp);
    listLen--;
  }
}

template<class ValType>
void TDatList<ValType>::Del(int num)
{
  if ((num < 0) || (num >(listLen - 1)))
    throw TExeption(DataErr);
  if (num == 0)
    DelFirst();
  else
  {
    TDatLink<ValType>* pTemp = pFirst;
    TDatLink<ValType>* pTempPrev;
    for (int i = 0; i < (num - 1); i++)
    {
      pTempPrev = pTemp;
      pTemp = pTemp->GetNextLink();
    }
    pTempPrev->SetNextLink(pTemp->GetNextLink());
    DelLink(pTemp);
  }
  listLen--;
}


template<class ValType>
void TDatList<ValType>::DelList()
{
  while (!IsEmpty())
    DelFirst();
}
#endif