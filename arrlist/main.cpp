#include "TArrList.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{
  setlocale(LC_ALL, "");
  srand(time(0));
  TArrList<int> st(10);
  int pVal;
  int temp;
  cout << "Testing the list on an array" << endl;
  for (int i = 0; i<10; i++)
  {
    pVal = rand() % 100;
    st.InsLast(pVal);
    cout << "Listed value " << pVal << endl;
  }
  // печать списка
  for (int i = 0; i < st.GetListLength(); i++)
  {
      pVal = st.GetDatValue(i);
      cout << "Taken from the list value "
        << pVal << endl;
  }
  return 0;
}