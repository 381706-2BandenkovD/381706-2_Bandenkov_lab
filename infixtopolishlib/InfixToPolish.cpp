#include "InfixToPolish.h"

int TInfixToPolish::GetOperationPrt(char op) { // получить приоритет операции
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

// проебразование выражения от инфиксной формы к польской записи
// выражение правильное, без пробелов, заканчивается знаком '='

char * TInfixToPolish::ConvertToPolish(char * InfixExp, int len) {
    TListStack<char> operation, polish;
    int i = 0;
    char t;
    while (i < len)
    {
        if (!IsOperation(InfixExp[i]))
        {
            while (!IsOperation(InfixExp[i]))
            {
                polish.Put(InfixExp[i++]);
            }
            i--;
            polish.Put(' ');
        }
        else if (InfixExp[i] == '(')
            operation.Put('(');
        else if (InfixExp[i] == ')')
        {
            while (1)
            {
                char k = operation.Get();
                if (k == '(')
                    break;
                polish.Put(k);
            }
        }
        else
        {
            while (!operation.IsEmpty())
            {
                t = operation.Get();
                if (GetOperationPrt(InfixExp[i]) <= GetOperationPrt(t))
                    polish.Put(t);
                else
                {
                    operation.Put(t);
                    break;
                }
            }
            operation.Put(InfixExp[i]);
        }
        if (InfixExp[i] == '=')
            break;
        i++;
    }
    int pos = polish.GetLen() + operation.GetLen();
    char * mem = new char[pos + 1];
    mem[pos] = '\0';
    mem[--pos] = '=';
    while (!polish.IsEmpty())
        mem[--pos] = polish.Get();
    return mem;
}

