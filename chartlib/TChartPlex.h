#ifndef __CHARTPLEX_H
#define __CHARTPLEX_H
#include <TExeption.h>
#include <TChartPoint.h>
#include <TChartLine.h>
#include <TListStack.h>
#include <iostream>

using namespace std;

class TChartPlex : public TChartPoint
{
protected:
  TChartPoint * left;
  TChartPoint* right;
  virtual TChartPoint* Show(TChartPlex* p);
public:
  TChartPlex();
  TChartPlex(TChartPlex& cp);
  TChartPlex(TChartPoint* l, TChartPoint* r);
  TChartPlex& operator +=(TChartLine &l);
  TChartPoint* GetLeft();
  TChartPoint* GetRight();
  void SetLeft(TChartPoint*);
  void SetRight(TChartPoint*);
  virtual void Show();
};
#endif