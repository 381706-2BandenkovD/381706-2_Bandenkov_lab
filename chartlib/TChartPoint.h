#ifndef __CHART_H
#define __CHART_H
#include <TExeption.h>
#include <TListStack.h>
#include <iostream>

using namespace std;

class TChartPoint
{
protected:
  double x, y;
public:
  TChartPoint(double coordx = 0, double coordy = 0);
  TChartPoint(TChartPoint& cp);
  virtual void Show();
  void SetX(double coordx);
  void SetY(double coordy);
  int operator== (const TChartPoint&);
  int operator!= (const TChartPoint&);
  double GetX();
  double GetY();
};
#endif