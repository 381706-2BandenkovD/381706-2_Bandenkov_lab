#include "InfixToPolish.h"

int TInfixToPolish::GetOperationPrt(char op) { // �������� ��������� ��������
  int Prt;
  switch (op) {
  case '*':
  case '/': Prt = 3; break;
  case '+':
  case '-': Prt = 2; break;
  case '(': Prt = 1; break;
  case '=': Prt = 0; break;
  default: Prt = -1;
  }
  return Prt;
}

int TInfixToPolish::IsOperation(char op)
{
  if (op == ')' || op == '(' || op == '+' || op == '-' || op == '*' || op == '/' || op == '=') return 1;
  else return 0;
}

double TInfixToPolish::Calculate(char* mem, int len)
{
  TStack<int> st;
  int res;
  int i = 0;
  int j;
  while (mem[i] != '=')
  {
    if (!IsOperation(mem[i]))
    {
      j = 0;
      char* buff = new char[len];
      while (mem[i] != ' ')
        buff[j++] = mem[i++];
      buff[j] = '\n';
      st.Put(atoi(buff));
      delete[] buff;
    }
    else
    {
      double x, y;
      y = st.Get();
      x = st.Get();
      double z;
      switch (mem[i])
      {
      case '*': z = x * y;
        break;
      case '/': z = x / y;
        break;
      case '+': z = x + y;
        break;
      case '-': z = x - y;
        break;
      default: throw(TExeption(DataErr));
      }
      st.Put(z);
    }
    i++;
  }
  res = st.Get();
  return res;
}

// �������������� ��������� �� ��������� ����� � �������� ������
// ��������� ����������, ��� ��������, ������������� ������ '='

char * TInfixToPolish::ConvertToPolish(char * InfixExp, int len) {
  char ch, t, *PolishExp = new char[strlen(InfixExp) + 1];
  int pos = 0; // ������ �������� ������� � ���������
  TListStack<char> PolishStack, OperationStack;
  bool key;
  do {
    ch = InfixExp[pos++];
    if (isalpha(ch)) PolishStack.Put(ch); // �������
    else if (ch == '(') OperationStack.Put(ch);
    else if (ch == ')') {
      while (1) { // �������� �������� �� ����� �������� �� ����. ������
        t = OperationStack.Get();
        if (t == '(') break;
        PolishStack.Put(t);
      }
    }
    else if (IsOperation(ch)) { // �������� � ������� �����������
      while (!OperationStack.IsEmpty()) { // � ���� �����������
        t = OperationStack.Get();
        if (GetOperationPrt(ch) <= GetOperationPrt(t)) PolishStack.Put(t);
        else { OperationStack.Put(t); break; }
      }
      OperationStack.Put(ch);
    } // '=' � ����� ��������
  } while ((ch != '=') && (pos < len));
    pos = 0;// ����� ��������� � �������� ������
    for (int i = 0; i < len; i++) {
      if ((InfixExp[i] != '(') && (InfixExp[i] != ')'))
        pos++;
    }
    PolishExp[pos] = '\0';
    PolishExp[--pos] = '=';
    // ���������� ��������� �� ����� - ������� ��������
    while (!PolishStack.IsEmpty()) PolishExp[--pos] = PolishStack.Get();
    return PolishExp;
  
}

