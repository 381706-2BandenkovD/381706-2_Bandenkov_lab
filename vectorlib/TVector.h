#ifndef __VECTOR_H__
#define __VECTOR_H__

#include <iostream>

using namespace std;

template <class ValType>
class TVector
{
protected:
  ValType * pVector;
  int size; // размер вектора
  int startIndex; // индекс первого элемента вектора
public:
  TVector();
  TVector(int s, int si = 0);
  TVector(const TVector &v); // конструктор копирования 
  ~TVector();
  int GetSize() { return size; } // размер вектора
  int GetStartIndex() { return startIndex; } // индекс первого элемента
  ValType & GetValue(int pos); // доступ с контролем индекса
  ValType & operator[] (int pos); // доступ
  int operator==(const TVector &v); // сравнение
  TVector & operator= (const TVector &v); // присванивание
                                          // скалярные операции
  TVector operator* (const ValType &val); // умножить на скаляр
                                          // векторные операции
  TVector operator+ (const ValType &val);
  TVector operator- (const ValType &val);
  TVector operator+ (const TVector &v); // сложение 
  TVector operator- (const TVector &v); // вычитание
  ValType operator* (const TVector &v); // скалярное произведение
  friend istream & operator>>(istream &in, TVector<ValType> &v) // ввод-вывод
  {
    for (int i = 0; i < v.size; i++)
      in >> v.pVector[i];
    return in;
  }
  friend ostream & operator<<(ostream &out, const TVector<ValType> &v) 
  {
    for (int i = 0; i < v.size; i++)
      out << v.pVector[i] << ' ';
    return out;
  }
};

template<class ValType>
TVector<ValType>::TVector()
{
  pVector = NULL;
  size = 0;
  startIndex = 0;
}

template<class ValType>
TVector<ValType>::TVector(int s, int si)
{
  if ((s < 0) || (si < 0))
    throw 1;
  if (s == 0)
  {
    pVector = NULL;
    size = 0;
    startIndex = 0;
  }
  else
  {
    pVector = new ValType[s];
    for (int i = 0; i < s; i++)
      pVector[i] = 0;
  }
  size = s;
  startIndex = si;
}

template<class ValType>
TVector<ValType>::TVector(const TVector & v)
{
    size = v.size;
    startIndex = v.startIndex;
    pVector = new ValType[size];
    for (int i = 0; i < size; i++)
      pVector[i] = v.pVector[i];
}


template<class ValType>
TVector<ValType>::~TVector()
{
  delete[]pVector;
}


template<class ValType>
ValType & TVector<ValType>::GetValue(int pos)
{
  if ((pos < 0) || (pos >= size))
    throw 1;
  return pVector[pos - startIndex];
}

template<class ValType>
ValType & TVector<ValType>::operator[](int pos)
{
  return pVector[pos - startIndex];
}

template<class ValType>
int TVector<ValType>::operator==(const TVector & v)
{
  if (v.size == size)
  {
    int res = 0;
    for (int i = 0; i < size; i++)
      res |= (pVector[i] ^ v.pVector[i]);
    return (res == 0);
  }
  return 0;
}

template<class ValType>
TVector<ValType> & TVector<ValType>::operator=(const TVector &v)
{
  if (v.pVector != pVector)
  {
    size = v.size;
    startIndex = v.startIndex;
    if (pVector)
      delete[]pVector;
    pVector = new ValType[size];
    for (int i = 0; i < size; i++)
      pVector[i] = v.pVector[i];
  }
  return *this;
}

template<class ValType>
TVector<ValType> TVector<ValType>::operator*(const ValType & val)
{
  TVector<ValType> res(size, startIndex);
  for (int i = 0; i < size; i++)
    res[i] = pVector[i]*val;
  return res;
}
template<class ValType>
TVector<ValType> TVector<ValType>::operator+(const ValType & val)
{
  TVector<ValType> res(size, startIndex);
  for (int i = 0; i < size; i++)
    res[i] += val;
  return res;
}
template<class ValType>
TVector<ValType> TVector<ValType>::operator-(const ValType & val)
{
  TVector<ValType> res(size, startIndex);
  for (int i = 0; i < size; i++)
    res[i] -= val;
  return res;
}
template<class ValType>
TVector<ValType> TVector<ValType>::operator+(const TVector & v)
{
  TVector<ValType> res(size, startIndex);
  for (int i = 0; i < size; i++)
    res.pVector[i] = v.pVector[i] + pVector[i];
  return res;
}
template<class ValType>
TVector<ValType> TVector<ValType>::operator-(const TVector & v)
{
  TVector<ValType> res(size, startIndex);
  for (int i = 0; i < size; i++)
    res.pVector[i] = pVector[i] - v.pVector[i];
  return res;
}

template<class ValType>
ValType TVector<ValType>::operator*(const TVector & v)
{
  ValType res = 0;
  for (int i = 0; i < size; i++)
    res += v.pVector[i] * pVector[i];
  return res;
}
#endif