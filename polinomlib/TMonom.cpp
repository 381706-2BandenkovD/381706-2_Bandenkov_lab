#include "TMonom.h"

TMonom::TMonom(int coeffval, int countval, int * powerarr)
{
  if (countval < 0)
    throw TExeption(DataErr);
  count = countval;
  coeff = coeffval;
  if(count)
    power = new int[count];
  if (powerarr)
    for (int i = 0; i < count; i++)
      power[i] = powerarr[i];
  else
    for (int i = 0; i < count; i++)
      power[i] = 0;
}

TMonom::TMonom(const TMonom & monom)
{
  count = monom.count;
  coeff = monom.coeff;
  power = new int[count];
  for (int i = 0; i < count; i++)
    power[i] = monom.power[i];
}

TMonom::~TMonom()
{
  if (power)
    delete[]power;
}

int TMonom::GetPower(int pos)
{
  if ((pos > count - 1) || (pos < 0))
    throw TExeption(DataErr);
  return power[pos];
}

void TMonom::SetPower(int val, int pos)
{
  if ((pos > count - 1) || (pos < 0))
    throw TExeption(DataErr);
  power[pos] = val;
}

void TMonom::SetCount(int countval)
{
  if (countval <= 0)
    throw TExeption(DataErr);
  unsigned* tmp = new unsigned int[count];
  for (int i = 0; i < count; i++)
    tmp[i] = power[i];
  delete[] power;
  power = new int[countval];
  for (int i = 0; i < (count > countval ? countval : count); i++)
    power[i] = tmp[i];
  delete[] tmp;
}

TMonom & TMonom::operator=(const TMonom & monom)
{
  if (this != &monom)
  {
    if (count != monom.count && count)
    {
      delete[] power;
      power = new int[count];
    }
    count = monom.count;
    coeff = monom.coeff;
    power = new int[count];
    for (int i = 0; i < count; i++)
      power[i] = monom.power[i];
  }
  return *this;
}

TMonom TMonom::operator+(const TMonom & monom)
{
  if (count != monom.count)
    throw TExeption(DataErr);
  TMonom tmp(monom);
  if (*this == monom)
    tmp.coeff = coeff + monom.coeff;
  else
    throw TExeption(DataErr);
  return tmp;
}


 TMonom TMonom::operator-(const TMonom & monom)
{
  if (count != monom.count)
    throw TExeption(DataErr);
  TMonom tmp(monom);
  if (*this == monom)
    tmp.coeff = coeff - monom.coeff;
  else
    throw TExeption(DataErr);
  return tmp;
}

TMonom TMonom::operator*(const TMonom & monom)
{
  if (count != monom.count)
    throw TExeption(DataErr);
  TMonom tmp(monom);
  tmp.coeff = coeff * monom.coeff;
  for (int i = 0; i < count; i++)
    tmp.power[i] = power[i] + monom.power[i];
  return tmp;
}

bool TMonom::operator>(const TMonom & monom)
{
  if (count != monom.count)
    throw TExeption(DataErr);
  for (int i = 0; i < count; i++)
    if (power[i] > monom.power[i])
      return true;
    else if (power[i] < monom.power[i])
      return false;
  return false;
}

bool TMonom::operator<(const TMonom & monom)
{
  if (count != monom.count)
    throw TExeption(DataErr);
  for (int i = 0; i < count; i++)
    if (power[i] > monom.power[i])
      return true;
    else if (power[i] < monom.power[i])
      return false;
  return false;
}

bool TMonom::operator==(const TMonom&  monom)
{
  if (count != monom.count)
    throw TExeption(DataErr);
  for (int i = 0; i < count; i++)
    if (power[i] != monom.power[i])
      return false;
  return true;
}

ostream & operator<<(ostream & os, TMonom & tm)
{
  os << tm.coeff << '*';
  for (int i = 0; i < tm.count -1; i++)
    os << "x" << i << "^" << tm.power[i] << '*';
  os << "x" << tm.count - 1 << "^" << tm.power[tm.count - 1];
  return os;
}
