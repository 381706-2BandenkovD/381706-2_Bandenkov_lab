#include <gtest.h>
#include <TArrList.h>


TEST(TArrList, can_create_list)
{
  ASSERT_NO_THROW(TArrList<int> l);
}

TEST(TArrList, empty_list_is_empty)
{
  TArrList<int> MyArrList(5);
  EXPECT_EQ(1, MyArrList.IsEmpty());
}

TEST(TArrList, full_list_is_full)
{
  TArrList<int> MyArrList(5);
  MyArrList.InsFirst(3);
  MyArrList.InsFirst(1);
  MyArrList.InsFirst(4);
  MyArrList.InsFirst(1);
  MyArrList.InsFirst(5);

  EXPECT_EQ(1, MyArrList.IsFull());
}

TEST(TArrList, can_get_first_value)
{
  TArrList<int> MyArrList(10);
  MyArrList.InsFirst(3);

  EXPECT_EQ(3, MyArrList.GetFirst());
}

TEST(TArrList, throws_when_get_negative_position)
{
  TArrList<int> MyArrList(10);
  MyArrList.InsFirst(3);

  ASSERT_ANY_THROW(MyArrList.GetDatValue(-1));
}


TEST(TArrList, throws_when_get_too_large_position)
{
  TArrList<int> MyArrList(10);
  MyArrList.InsFirst(3);

  ASSERT_ANY_THROW(MyArrList.GetDatValue(1));
}

TEST(TArrList, can_get_first)
{
  TArrList<int> MyArrList(10);
  MyArrList.InsFirst(1);
  MyArrList.InsFirst(2);
  MyArrList.InsFirst(3);

  EXPECT_EQ(1, MyArrList.GetDatValue(2));
}


TEST(TArrList, can_get_last_value)
{
  TArrList<int> MyArrList(10);
  MyArrList.InsFirst(1);
  MyArrList.InsFirst(2);
  MyArrList.InsFirst(3);
  MyArrList.InsLast(4);

  EXPECT_EQ(4, MyArrList.GetLast());
}

TEST(TArrList, can_get_value_from_middle)
{
  TArrList<int> MyArrList(10);
  MyArrList.InsFirst(1);
  MyArrList.InsFirst(2);
  MyArrList.InsFirst(3);
  MyArrList.InsLast(4);

  EXPECT_EQ(1, MyArrList.GetDatValue(2));
}

TEST(TArrList, can_delete_first_link)
{
  TArrList<int> MyArrList(10);
  MyArrList.InsFirst(1);
  MyArrList.InsFirst(2);
  MyArrList.InsFirst(3);
  MyArrList.DelFirst();

  EXPECT_EQ(2, MyArrList.GetFirst());
}