#ifndef __TTABRECORD_H__
#define __TTABRECORD_H__

#include <iostream>
#include <TExeption.h>
#include <TKey.h>
#include <string.h>

template <class ValType> class TScanTable;
template <class ValType> class TSortTable;
template <class ValType> class THashTable;
template <class ValType> class TListHash;

template<class ValType>
class TTabRecord
{
protected:
  TKey key;
  ValType* value;
  bool toDel;//  нужно ли удалить *value после удаления записи
public:
  TTabRecord(TKey k = "", ValType* val = NULL, bool del = true);
  TTabRecord(char*, ValType* val = NULL, bool del = false);
  TTabRecord(TTabRecord<ValType> &tr);
  void SetToDel(bool del);
  ~TTabRecord();
  void SetKey(TKey k);
  void SetValue(ValType* val);
  TKey GetKey();
  ValType* GetVal();
  bool operator == (const TTabRecord& tr);
  bool operator > (const TTabRecord& tr);
  bool operator < (const TTabRecord& tr);
  TTabRecord& operator = (const TTabRecord& tr);
  friend class TScanTable<ValType>;
  friend class TSortTable<ValType>;
  friend class THashTable<ValType>;
  friend class TListHash<ValType>;
};

template<class ValType>
TTabRecord<ValType>::TTabRecord(TKey k, ValType* val, bool del)
{
  key = k;
  value = val;
  toDel = del;
}

template<class ValType>
TTabRecord<ValType>::TTabRecord(char * ch, ValType * val, bool del)
{
  key = ch;
  value = val;
  toDel = del;
}

template<class ValType>
TTabRecord<ValType>::TTabRecord(TTabRecord<ValType>& tr)
{
  toDel = 1;
  key = tr.key;
  if (tr.value != NULL)
  {
    value = new ValType();
    *value = *tr.value;
  }
  else
    value = NULL;
}

template<class ValType>
void TTabRecord<ValType>::SetToDel(bool del)
{
  toDel = del;
}

template<class ValType>
TTabRecord<ValType>::~TTabRecord()
{
  if (toDel)
    delete value;
}

template<class ValType>
void TTabRecord<ValType>::SetKey(TKey k)
{
  key = k;
}

template<class ValType>
void TTabRecord<ValType>::SetValue(ValType * val)
{
  value = val;
}

template<class ValType>
TKey TTabRecord<ValType>::GetKey()
{
  return key;
}

template<class ValType>
ValType * TTabRecord<ValType>::GetVal()
{
  return value;
}

template<class ValType>
bool TTabRecord<ValType>::operator==(const TTabRecord & tr)
{
  return(key == tr.key);
}

template<class ValType>
bool TTabRecord<ValType>::operator>(const TTabRecord & tr)
{
  return (key > tr.key);
}

template<class ValType>
bool TTabRecord<ValType>::operator<(const TTabRecord & tr)
{
  return (key < tr.key);
}

template<class ValType>
TTabRecord<ValType>& TTabRecord<ValType>::operator =(const TTabRecord & tr)
{
  key = tr.key;
  value = tr.value;
  return *this;
}
#endif
