#include "TDatList.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{
  setlocale(LC_ALL, "");
  srand(time(0));
  TDatList<int> st;
  int pVal;
  int temp;
  cout << "Testing the list" << endl;
  for (int i = 0; i<10; i++)
  {
    pVal = rand() % 100;
    st.InsLast(pVal);
    cout << "Listed value " << pVal << endl;
  }
  // печать списка
  for (int i = 0; i < st.GetListLength(); i++) {
    pVal = st.GetDatValue(i);
    cout << "Taken from the list value "
      << pVal << endl;
  }
  st.DelList();
  return 0;
}