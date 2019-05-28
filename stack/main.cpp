#include <TStack.h>
#include <iostream>
#include <cstdlib>

using namespace std;


int main(int argc, char* argv[])
{
  setlocale(LC_ALL, "");
  TStack<int> st(100);
  int temp;
  cout << "Тестирование структуры типа стек" << endl;
  for (int i = 0; i<13; i++) {
    st.Put(i);
    cout << "В стек положили значение " << i << endl;
  }
  int k;
  while (!st.IsEmpty()) {
    temp = st.Get();
    cout << "Из стека взяли значение " << temp << endl;
  }
  return 0;
}