#include <gtest.h>
#include <TChartLine.h>

TEST(TChartLine, can_create_line)
{
  ASSERT_NO_THROW(TChartLine l);
}

TEST(TChartLine, can_set_a)
{
  TChartLine l;
  TChartPoint a(0, 1);
  ASSERT_NO_THROW(l.SetA(&a));
}

TEST(TChartLine, can_set_b)
{
  TChartLine l;
  TChartPoint a(0, 1);
  ASSERT_NO_THROW(l.SetB(&a));
}

TEST(TChartLine, can_get_a)
{
  TChartLine l;
  TChartPoint a(0, 1);
  l.SetA(&a);
  EXPECT_EQ(*l.GetA() == a, 1);
}

TEST(TChartLine, can_get_b)
{
 
  TChartLine l;
  TChartPoint b(0, 1);
  l.SetB(&b);
  EXPECT_EQ(*l.GetB() == b, 1);
}