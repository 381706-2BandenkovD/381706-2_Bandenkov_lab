#include "TChartPlex.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

#define COUNT 5

using namespace std;

int main()
{
  TChartPlex pl;
  TChartPoint p[COUNT];
  TChartLine l;
  cout << "Enter " << COUNT <<" Points" << endl;
  for (int i = 0; i < COUNT; i++)
  {
    int buff;
    cout << "X" << i + 1 << " = " << endl;
    cin >> buff;
    p[i].SetX(buff);
    cout << "Y" << i + 1 << " = " << endl;
    cin >> buff;
    p[i].SetY(buff);
  }
  for (int i = 0; i < COUNT - 1; i++)
  {
    l.SetA(p + i);
    l.SetB(p + i + 1);
    pl += l;
  }
  pl.Show();
  return 0;
}