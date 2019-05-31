#include <gtest.h>
#include <TChartPoint.h>

TEST(TChartPoint, can_create_point)
{
  ASSERT_NO_THROW(TChartPoint p);
}

TEST(TChartPoint, can_set_x)
{
  TChartPoint a(0, 1);
  ASSERT_NO_THROW(a.SetX(1));
}

TEST(TChartPoint, can_set_y)
{
  TChartPoint a(0, 1);
  ASSERT_NO_THROW(a.SetY(1));
}

TEST(TChartPoint, can_get_x)
{
  TChartPoint a(0, 1);
  a.SetX(1);
  EXPECT_EQ(a.GetX(), 1);
}

TEST(TChartPoint, can_get_y)
{
  TChartPoint a(0, 1);
  a.SetY(2);
  EXPECT_EQ(a.GetY(), 2);
}

TEST(TChartPoint, can_compare_equal_points)
{
  TChartPoint a(256, 256);
  TChartPoint b(256, 256);
  EXPECT_EQ(a == b, 1);
}

TEST(TChartPoint, can_compare_equal_points_with_unequality)
{
  TChartPoint a(256, 256);
  TChartPoint b(256, 256);
  EXPECT_EQ(a != b, 0);
}

TEST(TChartPoint, can_compare_non_equal_points)
{
  TChartPoint a(256, 256);
  TChartPoint b(256, 256.5);
  EXPECT_EQ(a == b, 0);
}

TEST(TChartPoint, can_compare_non_equal_points_with_unequality)
{
  TChartPoint a(256, 256);
  TChartPoint b(256, 256.5);
  EXPECT_EQ(a != b, 1);
}
