#include "InfixToPolish.h"
#include <iostream>

using namespace std;

int main()
{
  setlocale(LC_ALL, ""); 
  TInfixToPolish ExpConvertor;
  char Expression[80], *PolishExpression;
  cout << "Translation of arithmetic expression from infix to postfix notation" << endl;
  cout << "Enter expression" << endl;
  cin >> Expression;
  PolishExpression = ExpConvertor.ConvertToPolish(Expression, strlen(Expression));
  cout << "ÂInfix expression - " << Expression << endl;
  cout << "Expression in reverse polish notation - " << PolishExpression << endl;
  cout << "Result - " << ExpConvertor.Calculate(PolishExpression, strlen(Expression)) << endl;
  delete PolishExpression;
}