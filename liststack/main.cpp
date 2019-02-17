#include <iostream>
#include <TListStack.h>
#include <ctime>
#include <cstdlib>

int main()
{
  setlocale(LC_ALL, "");
  srand(time(NULL));
  TListStack<int> mst;
  int code, temp, val = 0;
  cout << "Testing stack support system (lists)" << endl;
  cout << "Press any key" << endl;
  while (val < 100)
  {
    val++;
    code = rand() % 4;
    if (code<2)
      mst.Put(val);
    else if (!mst.IsEmpty())
      temp = mst.Get();
  }
  cout << "Stack Stamp" << endl;
  mst.Print();
  return 0;
}