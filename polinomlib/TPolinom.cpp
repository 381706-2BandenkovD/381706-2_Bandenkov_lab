#include "TPolinom.h"

TPolinom::TPolinom() : TDatList<TMonom>()
{
}

TPolinom::TPolinom(const TPolinom & q) : TDatList<TMonom>(q)
{
}

TPolinom::TPolinom(const TDatList<TMonom>& q) : TDatList<TMonom>(q)
{
}

TPolinom TPolinom::operator+(const TPolinom & q)
{
  if (this->listLen != q.listLen)
    throw TExeption(DataErr);
  TDatLink<TMonom>* tmp1 = this->pFirst;
  TDatLink<TMonom>* tmp2 = q.pFirst;
  TPolinom res;
  while (tmp1 && tmp2)
    if (tmp1->GetDatValue() == tmp2->GetDatValue())
    {
      res.InsLast(tmp1->GetDatValue() + tmp2->GetDatValue());
      tmp1 = tmp1->GetNextLink();
      tmp2 = tmp2->GetNextLink();
    }
    else if (tmp1->GetDatValue() > tmp2->GetDatValue())
    {
      res.InsLast(tmp1->GetDatValue());
      tmp1 = tmp1->GetNextLink();
    }
    else
    {
      res.InsLast(tmp2->GetDatValue());
      tmp2 = tmp2->GetNextLink();
    }
  if (!tmp1)
    tmp1 = tmp2;
  while (tmp1)
  {
    res.InsLast(tmp1->GetDatValue());
    tmp1 = tmp1->GetNextLink();
  }
  return res;
}

TPolinom TPolinom::operator-(TPolinom & q)
{
  if (this->listLen != q.listLen)
    throw TExeption(DataErr);
  TDatLink<TMonom>* tmp1 = pFirst;
  TDatLink<TMonom>* tmp2 = q.pFirst;
  TPolinom res;
  while (tmp1 && tmp2)
    if (tmp1 == tmp2)
    {
      res.InsLast(tmp1->GetDatValue() - tmp2->GetDatValue());
      tmp1 = tmp1->GetNextLink();
      tmp2 = tmp2->GetNextLink();
    }
    else if (tmp1 > tmp2)
    {
      res.InsLast(tmp1->GetDatValue());
      tmp1 = tmp1->GetNextLink();
    }
    else
    {
      res.InsLast(tmp2->GetDatValue());
      tmp2 = tmp2->GetNextLink();
    }
  if (!tmp1)
    tmp1 = tmp2;
  while (tmp1)
  {
    res.InsLast(tmp1->GetDatValue());
    tmp1 = tmp1->GetNextLink();
  }
  return res;
}

TPolinom TPolinom::operator*(TPolinom & q)
{
  TPolinom res;
  TDatLink<TMonom>* tmp1 = pFirst;
  TDatLink<TMonom>* tmp2 = q.pFirst;
  for (int i = 0; i < this->listLen; i++)
  {
    for (int i = 0; i < q.listLen; i++)
    {
      res.InsLast(tmp1->GetDatValue() * tmp2->GetDatValue());
      tmp1 = tmp1->GetNextLink();
    }
    tmp2 = tmp2->GetNextLink();
  }
  return res;
}

TPolinom & TPolinom::operator+=(TMonom & m)
{
  for (int i = 0; i < listLen; i++)
  {
    TMonom tmp = GetDatValue(i);
    if (tmp == m)
    {
      Del(i);
      InsTo(i, m + tmp);
      return *this;
    }
    else if (tmp < m)
    {
      InsTo(i, m);
      return *this;
    }
  }
  InsLast(m);
  return *this;
}

TPolinom & TPolinom::operator=(TPolinom & q)
{
  if (this != &q)
  {
    this->listLen = q.listLen;
    TDatLink<TMonom>* pTemp = q.pFirst;
    pFirst = new TDatLink<TMonom>(pTemp->GetDatValue(), NULL);
    TDatLink<TMonom>* TmpLast = pFirst;
    TDatLink<TMonom>* TmpCurr;
    for (int i = 1; i < q.listLen; i++)
    {
      pTemp = pTemp->GetNextLink();
      TmpCurr = new TDatLink<TMonom>(pTemp->GetDatValue(), NULL);
      TmpLast->SetNextLink(TmpCurr);
      TmpLast = TmpCurr;
    }
    this->pLast = TmpCurr;
  }
  return *this;
}

ostream & operator<<(ostream & os, TPolinom & q)
{
  TDatLink<TMonom>* tmp = q.pFirst;
  for (int i = 0; i < q.listLen - 1; i++)
  {
    os << q.GetDatValue(i) << '+';
    tmp = tmp->GetNextLink();
  }
  os << q.GetDatValue(q.listLen - 1) << endl;
  return os;
}
