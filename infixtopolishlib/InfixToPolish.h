#ifndef __POLISH_H
#define __POLISH_H
#include <TExeption.h>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<TListStack.h>
#include<TStack.h>

using namespace std;

class TInfixToPolish {
protected:
  int GetOperationPrt(char op); // получить приоритет операции
  int IsOperation(char op); // проверка на знак операции
public:
  char* ConvertToPolish(char * InfixExp, int len); // проебразование к польской записи
  double Calculate(char* mem, int len);
};
#endif
