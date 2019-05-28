#ifndef __TMONOM_H
#define __TMONOM_H
#include <iostream>
#include "TExeption.h"

using namespace std;

class TMonom 
{
protected:
  int coeff; // коэффициент монома
  int count; // число членов монома
  int* power; // массив степеней

public:
  TMonom(int cval = 1, int ival = 0, int* powerarr = NULL);
  TMonom(const TMonom& monom);
  ~TMonom();

  void SetCoeff(int cval) {coeff = cval;}
  int GetCoeff() {return coeff;}
  int GetPower(int pos);
  void SetPower(int val, int pos);
  void SetCount(int countval);
  int GetCount() {return count;}

  TMonom& operator = (const TMonom& monom);
  TMonom operator + (const TMonom& monom);
  TMonom operator - (const TMonom& monom);
  TMonom operator * (const TMonom& monom);
  bool operator > (const TMonom& monom);
  bool operator < (const TMonom& monom);
  bool operator == (const TMonom& monom);
  friend ostream& operator<<(ostream &os, TMonom &tm);
  friend class TPolinom;
};
#endif
