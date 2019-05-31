#ifndef __CHARTLINE_H
#define __CHARTLINE_H
#include <TExeption.h>
#include<TChartPoint.h>
#include <TListStack.h>
#include <iostream>

using namespace std;

class TChartLine
{
protected:
  TChartPoint * a;
  TChartPoint* b;
public:
  TChartLine(TChartPoint * pA = NULL, TChartPoint * pB = NULL);
  TChartLine(TChartLine& cp);
  virtual void Show();
  void SetA(TChartPoint*);
  void SetB(TChartPoint*);
  TChartPoint* GetA();
  TChartPoint* GetB();
};
#endif