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
  int GetOperationPrt(char op); // �������� ��������� ��������
  int IsOperation(char op); // �������� �� ���� ��������
public:
  char* ConvertToPolish(char * InfixExp, int len); // �������������� � �������� ������
  double Calculate(char* mem, int len);
};
#endif
