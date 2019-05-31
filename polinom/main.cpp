#include "TPolinom.h"
#include <iostream>
#include <cstdlib>

int main() 
{
  setlocale(LC_ALL, "");
  cout << "Polynomial Testing" << endl;
  TPolinom p;
  for (int i = 0; i < 5; i++)
  {
    int ms[] = { i+1, i+2, i+3 };
    TMonom m(i*2, 3, ms);
    p += m;
  }
  cout << "First polynomial" << endl << p;
  TPolinom q;
  for (int i = 0; i < 5; i++)
  {
    int ms[] = { i + 1, i + 2, i + 3 };
    TMonom m(i+ 5, 3, ms);
    q += m;
  }
  cout << "Second polynomial" << endl << q;
  TPolinom r = p + q;
  cout << "Polynomial result" << endl << r;
  return 0;
}