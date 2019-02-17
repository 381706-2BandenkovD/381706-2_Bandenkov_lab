#ifndef __DATLINK_H
#define __DATLINK_H
#include <iostream>

template<class ValType>
class TDatLink {
protected:
  ValType value; // значение
  TDatLink* pNext; // указатель на следующее звено
public:
  TDatLink(ValType Val = 0, TDatLink* next = NULL);
  void SetDatValue(ValType Val);
  ValType& GetDatValue();
  void SetNextLink(TDatLink* pLink);
  TDatLink* GetNextLink();
};
#endif

template<class ValType>
TDatLink<ValType>::TDatLink(ValType Val, TDatLink* next)
{
  value = Val;
  pNext = next;
}

template<class ValType>
void TDatLink<ValType>::SetDatValue(ValType Val)
{
  value = Val;
}

template<class ValType>
ValType& TDatLink<ValType>::GetDatValue()
{
  return value;
}

template<class ValType>
void TDatLink<ValType>::SetNextLink(TDatLink * pLink)
{
  pNext = pLink;
}

template<class ValType>
TDatLink<ValType> * TDatLink<ValType>::GetNextLink()
{
  return pNext;
}
