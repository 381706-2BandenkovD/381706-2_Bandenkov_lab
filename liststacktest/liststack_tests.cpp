#include <gtest.h>
#include <TDatList.h>


TEST(TDatList, can_create_list)
{
  ASSERT_NO_THROW(TDatList<int> l);
}

TEST(TDatList, can_put_value)
{
  TDatList<int> MyDatList;
  MyDatList.InsFirst(3);

  EXPECT_EQ(3, MyDatList.GetDatValue(0));
}

TEST(TDatList, throws_when_get_negative_position)
{
  TDatList<int> MyDatList;
  MyDatList.InsFirst(3);

  ASSERT_ANY_THROW(MyDatList.GetDatValue(-1));
}

TEST(TDatList, throws_when_put_to_negative_position)
{
  TDatList<int> MyDatList;

  ASSERT_ANY_THROW(MyDatList.InsTo(-1, 4));
}

TEST(TDatList, throws_when_put_too_large__position)
{
  TDatList<int> MyDatList;

  ASSERT_ANY_THROW(MyDatList.InsTo(4, 4));
}

TEST(TDatList, throws_when_get_too_large_position)
{
  TDatList<int> MyDatList;
  MyDatList.InsFirst(3);

  ASSERT_ANY_THROW(MyDatList.GetDatValue(1));
}

TEST(TDatList, can_put_first_value)
{
  TDatList<int> MyDatList;
  MyDatList.InsFirst(1);
  MyDatList.InsFirst(2);
  MyDatList.InsFirst(3);

  EXPECT_EQ(1, MyDatList.GetDatValue(2));
}

TEST(TDatList, can_put_in_middle_value)
{
  TDatList<int> MyDatList;
  MyDatList.InsFirst(1);
  MyDatList.InsFirst(2);
  MyDatList.InsFirst(3);
  MyDatList.InsTo(1, 4);

  EXPECT_EQ(4, MyDatList.GetDatValue(1));
}

TEST(TDatList, can_put_in_end_value)
{
  TDatList<int> MyDatList;
  MyDatList.InsFirst(1);
  MyDatList.InsFirst(2);
  MyDatList.InsFirst(3);
  MyDatList.InsLast(4);

  EXPECT_EQ(4, MyDatList.GetDatValue(3));
}

TEST(TDatList, can_delete_first_value)
{
  TDatList<int> MyDatList;
  MyDatList.InsFirst(1);
  MyDatList.InsFirst(2);
  MyDatList.InsFirst(3);
  MyDatList.DelFirst();

  EXPECT_EQ(2, MyDatList.GetDatValue(0));
}

TEST(TDatList, can_get_leight)
{
  TDatList<int> MyDatList;
  MyDatList.InsFirst(1);
  MyDatList.InsFirst(2);
  MyDatList.InsFirst(3);

  EXPECT_EQ(3, MyDatList.GetListLength());
}
