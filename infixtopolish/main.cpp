#include "InfixToPolish.h"
#include <iostream>

using namespace std;

int main()
{
  setlocale(LC_ALL, ""); 
  TInfixToPolish ExpConvertor;
  char Expression[80], *PolishExpression;
  cout << "Перевод арифм. выражения из инфиксной в постфиксную запись" << endl;
  cout << "Введите выражение" << endl;
  cin >> Expression;
  PolishExpression = ExpConvertor.ConvertToPolish(Expression, strlen(Expression));
  cout << "Выражение в инфиксной записи - " << Expression << endl;
  cout << "Выражение в обратной польской записи - " << PolishExpression << endl;
  cout << "Результат - " << ExpConvertor.Calculate(PolishExpression, strlen(Expression)) << endl;
  delete PolishExpression;
}