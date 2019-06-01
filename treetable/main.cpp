#include "TArrList.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <TTreeTable.h>

using namespace std;

int main()
{
  TTreeTable<int> table;
  bool flag = true;
  TKey k;
  int cmd = 0;
  int * val;
  std::cout << "Press Enter to Start";
  while (flag)
  {
    char buff[256];
    std::cout << endl;
    std::cout << "0 - exit" << endl;
    std::cout << "1 - add record" << endl;
    std::cout << "2 - delete record" << endl;
    std::cout << "3 - find record" << endl;
    cin >> cmd;
    switch (cmd)
    {
    case 0:
      flag = false;
      break;
    case 1:
      val = new int;
      cin >> *val;
      cin >> buff;
      table.Add(new TTreeNode<int>(buff, val));
      break;
    case 2:
      cin >> buff;
      k = buff;
      table.Delete(k);
      break;
    case 3:
      cin >> buff;
      k = buff;
      table.Search(k);
      break;
    }
    table.Print();
  }

  return 0;
}