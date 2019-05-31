#include "TChartPoint.h"

TChartPoint::TChartPoint(double coordx, double coordy)
{
  x = coordx;
  y = coordy;
}

TChartPoint::TChartPoint(TChartPoint & cp)
{
  x = cp.x;
  y = cp.y;
}

void TChartPoint::Show()
{
  cout << "x = " << x;
  cout << " y = " << y;
}

void TChartPoint::SetX(double coordx)
{
  x = coordx;
}

void TChartPoint::SetY(double coordy)
{
  y = coordy;
}

int TChartPoint::operator==(const TChartPoint &p)
{
  if (x == p.x && y == p.y)
    return 1;
  return 0;
}

int TChartPoint::operator!=(const TChartPoint &p)
{
  return !(*this == p);
}

double TChartPoint::GetX()
{
  return x;
}

double TChartPoint::GetY()
{
  return y;
}