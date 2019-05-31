#include <TKey.h>

TKey::TKey(char * k)
{
  len = strlen(k);
  key = new char[len + 1];
  strcpy(key, k);
}

TKey::TKey(const TKey & k)
{
  len = strlen(k.key);
  key = new char[k.len + 1];
  strcpy(key, k.key);
}

void TKey::SetKey(char * k)
{
  len = strlen(k);
  key = new char[len + 1];
  strcpy(key, k);
}

int TKey::GetLen()
{
  return len;
}

char * TKey::GetKey()
{
  return key;
}

TKey& TKey::operator=(const TKey & tr)
{
    len = strlen(tr.key);
    key = new char[len + 1];
    strcpy(key, tr.key);
  return *this;
}

TKey& TKey::operator=(const char * str)
{
  if(len != 0)
    delete key;
  len = strlen(str);
  key = new char[len + 1];
  strcpy(key, str);
  return *this;
}

bool TKey::operator==(const TKey & tr)
{
  if (len != tr.len)
    return false;
  for (int i = 0; i < len; i++)
  {
    if (key[i] != tr.key[i])
      return false;
  }
  return true;
}

bool TKey::operator>(const TKey & tr)
{
  int clamp = len;
  if (tr.len < len)
    clamp = tr.len;
  for (int i = 0; i < clamp; i++)
  {
    if (key[i] < tr.key[i])
      return true;
    else if (key[i] > tr.key[i])
      return false;
  }
  if (len < tr.len)
    return true;
  return false;
}

bool TKey::operator<(const TKey & tr)
{
  int clamp = len;
  if (tr.len < len)
    clamp = tr.len;
  for (int i = 0; i < clamp; i++)
  {
    if (key[i] > tr.key[i])
      return true;
    else if (key[i] < tr.key[i])
      return false;
  }
  if (len > tr.len)
    return true;
  return false;
}

char TKey::operator[](const int pos)
{
  if((pos < len) && (pos > 0))
    return key[pos];
  return -1;
}

TKey::~TKey()
{
  if (len != 0)
    delete key;
}

ostream & operator<<(ostream & os, const TKey & q)
{
  os << q.key;
  return os;
}
