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
char* TInfixToPolish::ConvertToPolish(char * InfixExp, int len)
{
  TListStack<char> operationStack, polishStack;
  int pos = 0;// индекс текущего символа в выражении
  char t;
  while (pos < len)
  {
    if (!IsOperation(InfixExp[pos]))
    {
      while (!IsOperation(InfixExp[pos]))
      {
        polishStack.Put(InfixExp[pos++]);
      }
      pos--;
      polishStack.Put(' ');
    }
    else if (InfixExp[pos] == '(')
      operationStack.Put('(');
    else if (InfixExp[pos] == ')')
    {
      while (1)// перепись операций из стека операций до откр. скобки
      {
        char k = operationStack.Get();
        if (k == '(')
          break;
        polishStack.Put(k);
      }
    }
    else
    {// операции с меньшим приоритетом
      while (!operationStack.IsEmpty())// в стек результатов
      {
        t = operationStack.Get();
        if (GetOperationPrt(InfixExp[pos]) <= GetOperationPrt(t))
          polishStack.Put(t);
        else
        {
          operationStack.Put(t);
          break;
        }
      }
      operationStack.Put(InfixExp[pos]);
    }
    if (InfixExp[pos] == '=')
      break;
    pos++;
  }
  int position = polishStack.GetLen() + operationStack.GetLen();
  char * ns = new char[position + 1];
  ns[position] = '\0';
  ns[--position] = '=';
  // извлечение выражения из стека - порядок обратный
  while (!polishStack.IsEmpty()) ns[--position] = polishStack.Get();
  return ns;
}


