#include <TChartLine.h>

TChartLine::TChartLine(TChartPoint * pA, TChartPoint * pB)
{
  a = pA;
  b = pB;
}


TChartLine::TChartLine(TChartLine & cp)
{
  a = cp.a;
  b = cp.b;
}

void TChartLine::Show()
{
  cout << "a : ";
  a->Show();
  cout << endl << "b : ";
  b->Show();
}

void TChartLine::SetA(TChartPoint* p)
{
  a = p;
}

void TChartLine::SetB(TChartPoint* p)
{
  b = p;
}

TChartPoint * TChartLine::GetA()
{
  return a;
}

TChartPoint * TChartLine::GetB()
{
  return b;
}
