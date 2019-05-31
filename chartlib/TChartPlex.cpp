#include <TChartPlex.h>

TChartPoint * TChartPlex::Show(TChartPlex * p)
{
  TChartPlex* lp = dynamic_cast<TChartPlex*>(p->left);
  TChartPlex* rp = dynamic_cast<TChartPlex* > (p->right);
  TChartPoint* tmp_l;
  TChartPoint* tmp_r;
  if (lp == NULL)
    tmp_l = p->left;
  else
    tmp_l = Show(lp);
  if (rp == NULL)
    tmp_r = p->right;
  else
    tmp_r = Show(rp);
  cout << "Line: ";
  tmp_l->Show();
  cout << " - ";
  tmp_r->Show();
  cout << endl;
  return tmp_r;
}

TChartPlex::TChartPlex()
{
  left = NULL;
  right = NULL;
}

TChartPlex::TChartPlex(TChartPlex & cp)
{
  TChartPlex* lBuff = dynamic_cast<TChartPlex*>(cp.left);
  TChartPlex* rBuff = dynamic_cast<TChartPlex*>(cp.right);
  if (lBuff != NULL)
    left = new TChartPlex(*lBuff);
  else
    left = new TChartPoint(*cp.left);
  if (rBuff != NULL)
    right = new TChartPlex(*rBuff);
  else
    right = new TChartPoint(*cp.right);
}

TChartPlex::TChartPlex(TChartPoint * l, TChartPoint * r)
{
  TChartPlex* lBuff = dynamic_cast<TChartPlex*>(l);
  TChartPlex* rBuff = dynamic_cast<TChartPlex*>(r);
  if (lBuff != NULL)
    left = new TChartPlex(*lBuff);
  else
    left = new TChartPoint(*l);
  if (rBuff != NULL)
    right = new TChartPlex(*rBuff);
  else
    right = new TChartPoint(*r);
}

TChartPlex & TChartPlex::operator+=(TChartLine & l)
{
  if (left == NULL && right == NULL)
  {
    left = l.GetA();
    right = l.GetB();
  }
  else
  {
    TListStack<TChartPoint*> st;
    TListStack<TChartPlex*> parentSt;
    st.Put(left);
    st.Put(right);
    parentSt.Put(this);
    parentSt.Put(this);
    bool flag = true;
    while (flag)
    {
      TChartPoint* buff = st.Get();
      TChartPlex* parentBuff = parentSt.Get();
      if (*buff != *l.GetA() && *buff != *l.GetB())
      {
        TChartPlex* pl = dynamic_cast<TChartPlex*>(buff);
        if (pl != 0)
        {
          st.Put(pl->GetLeft());
          st.Put(pl->GetRight());
          parentSt.Put(pl);
          parentSt.Put(pl);
        }
      }
      else if (*buff == *l.GetA())
      {
        flag = false;
        if (*buff == *parentBuff->left)
        {
          parentBuff->left = new TChartPlex(l.GetB(), l.GetA());
        }
        else
        {
          parentBuff->right = new TChartPlex(l.GetB(), l.GetA());
        }
      }
      else
      {
        flag = false;
        if (*buff == *parentBuff->left)
        {
          parentBuff->left = new TChartPlex(l.GetA(), l.GetB());
        }
        else
        {
          parentBuff->right = new TChartPlex(l.GetA(), l.GetB());
        }
      }
    }
  }
  return *this;
}

TChartPoint * TChartPlex::GetLeft()
{
  return left;
}

TChartPoint * TChartPlex::GetRight()
{
  return right;
}

void TChartPlex::SetLeft(TChartPoint * l)
{
  left = l;
}

void TChartPlex::SetRight(TChartPoint *r)
{
  right = r;
}

void TChartPlex::Show()
{
  Show(this);
}

