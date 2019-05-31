#include <gtest.h>
#include <TChartPlex.h>


TEST(TChartPlex, can_create_plex)
{
  ASSERT_NO_THROW(TChartPlex pl);
}

TEST(TChartPlex, can_set_left)
{
  TChartPlex pl;
  TChartPoint a(0, 0);
  ASSERT_NO_THROW(pl.SetLeft(&a));
}

TEST(TChartPlex, can_set_right)
{
  TChartPlex pl;
  TChartPoint a(0, 0);
  ASSERT_NO_THROW(pl.SetRight(&a));
}

TEST(TChartPlex, can_get_left)
{
  TChartPlex pl;
  TChartPoint a(0, 0);
  pl.SetLeft(&a);
  EXPECT_EQ(*pl.GetLeft() == a, 1);
}

TEST(TChartPlex, can_get_right)
{
  TChartPlex pl;
  TChartPoint a(0, 0);
  pl.SetRight(&a);
  EXPECT_EQ(*pl.GetRight() == a, 1);
}

TEST(TChartPlex, can_add_line)
{
  TChartPlex pl;
  TChartPoint a(0, 0), b(1, 1), c(2, 1);
  TChartLine l1(&a, &b), l2(&c, &b);
  ASSERT_NO_THROW(pl += l1;);
}

TEST(TChartPlex, can_add_line_right_to_right)
{
  TChartPlex pl;
  TChartPoint a(0, 0), b(1, 1), c(2, 1);
  TChartLine l1(&a, &b), l2(&c, &b);
  pl += l1;
  pl += l2;
  EXPECT_EQ(*pl.GetLeft() == a, 1);
  EXPECT_EQ(*((dynamic_cast<TChartPlex*>(pl.GetRight())->GetRight())) == b, 1);
  EXPECT_EQ(*((dynamic_cast<TChartPlex*>(pl.GetRight())->GetLeft())) == c, 1);
}

TEST(TChartPlex, can_add_line_right_to_left)
{
  TChartPlex pl;
  TChartPoint a(0, 0), b(1, 1), c(2, 1);
  TChartLine l1(&a, &b), l2(&b, &c);
  pl += l1;
  pl += l2;
  EXPECT_EQ(*pl.GetLeft() == a, 1);
  EXPECT_EQ(*((dynamic_cast<TChartPlex*>(pl.GetRight())->GetRight())) == b, 1);
  EXPECT_EQ(*((dynamic_cast<TChartPlex*>(pl.GetRight())->GetLeft())) == c, 1);
}

TEST(TChartPlex, can_add_line_left_to_right)
{
  TChartPlex pl;
  TChartPoint a(0, 0), b(1, 1), c(2, 1);
  TChartLine l1(&b, &a), l2(&c, &b);
  pl += l1;
  pl += l2;
  EXPECT_EQ(*pl.GetRight() == a, 1);
  EXPECT_EQ(*((dynamic_cast<TChartPlex*>(pl.GetLeft())->GetRight())) == b, 1);
  EXPECT_EQ(*((dynamic_cast<TChartPlex*>(pl.GetLeft())->GetLeft())) == c, 1);
}

TEST(TChartPlex, can_add_line_left_to_left)
{
  TChartPlex pl;
  TChartPoint a(0, 0), b(1, 1), c(2, 1);
  TChartLine l1(&b, &a), l2(&b, &c);
  pl += l1;
  pl += l2;
  EXPECT_EQ(*pl.GetRight() == a, 1);
  EXPECT_EQ(*((dynamic_cast<TChartPlex*>(pl.GetLeft())->GetRight())) == b, 1);
  EXPECT_EQ(*((dynamic_cast<TChartPlex*>(pl.GetLeft())->GetLeft())) == c, 1);
}