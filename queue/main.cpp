#include <TQueue.h>
#include <iostream>
#include <cstdlib>

using namespace std;


int main(int argc, char* argv[])
{
  setlocale(LC_ALL, "");
  TQueue<int> st(100);
  int temp;
  cout << "Тестирование структуры типа очереди" << endl;
  for (int i = 0; i<13; i++) {
    st.Put(i);
    cout << "В очередь поступило значение " << i << endl;
  }
  int k;
  while (!st.IsEmpty()) {
    temp = st.Get();
    cout << "Из очереди взяли значение " << temp << endl;
  }
  return 0;
}