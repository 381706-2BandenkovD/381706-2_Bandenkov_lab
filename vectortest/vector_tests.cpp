#include <gtest.h>
#include <TVector.h>
#include <iostream>


TEST(TVector, can_create_vector_with_positive_size)
{
  ASSERT_NO_THROW(TVector<int> v(3, 0));
}

TEST(TVector, throw_when_negative_size)
{
  ASSERT_ANY_THROW(TVector<int> v(-3, 0));
}

TEST(TVector, throw_when_negative_start_position)
{
  ASSERT_ANY_THROW(TVector<int> v(3, -1));
}

TEST(TVector, can_get_start_index)
{
  TVector<int> MyVector(3, 0);

  EXPECT_EQ(3, MyVector.GetSize());
}

TEST(TVector, can_put_value)
{
  TVector<int> MyVector(3, 0);
  MyVector[0] = 5;

  EXPECT_EQ(5, MyVector[0]);
}

TEST(TVector, throw_when_negative_index)
{
  TVector<int> MyVector(3, 0);
  ASSERT_ANY_THROW(MyVector.GetValue(-1));
}

TEST(TVector, throw_when_too_lage_index)
{
  TVector<int> MyVector(3, 0);
  ASSERT_ANY_THROW(MyVector.GetValue(3));
}

TEST(TVector, can_assign_vectors_of_equal_size)
{
  TVector<int> MyV1(2, 0), MyV2(2, 0);
  for (int i = 0; i < MyV2.GetSize(); i++)
  {
    MyV2[i] = i;
  }
  MyV1 = MyV2;

  EXPECT_EQ(1, MyV1[1]);
}

TEST(TVector, can_assign_vectors_of_non_equal_size)
{
  TVector<int> MyV1(2, 0), MyV2(5, 0);
  for (int i = 0; i < MyV2.GetSize(); i++)
  {
    MyV2[i] = i;
  }
  MyV1 = MyV2;

  EXPECT_EQ(4, MyV1[4]);
}

TEST(TVector, compare_equal_vectors)
{
  TVector<int> MyV1(2, 0), MyV2(5, 0);
  for (int i = 0; i < MyV2.GetSize(); i++)
  {
    MyV2[i] = i;
  }
  MyV1 = MyV2;

  EXPECT_EQ(1, MyV1 == MyV2);
}

TEST(TVector, compare_non_equal_vectors)
{
  TVector<int> MyV1(2, 0), MyV2(5, 0);
  for (int i = 0; i < MyV2.GetSize(); i++)
  {
    MyV2[i] = i;
  }
  MyV1 = MyV2;
  MyV1[0] = 3;

  EXPECT_NE(1, MyV1 == MyV2);
}

TEST(TVector, can_add_vectors)
{
  const int size = 2;
  TVector<int> MyV1(size, 0), MyV2(size, 0), MyV3(size, 0);
  for (int i = 0; i < size; i++)
  {
    MyV1[i] = 1;
    MyV2[i] = 2;
    MyV3[i] = 3;
  }

  EXPECT_EQ(1, MyV3 == (MyV1 + MyV2));
}

TEST(TVector, can_subtract_vectors)
{
  const int size = 2;
  TVector<int> MyV1(size, 0), MyV2(size, 0), MyV3(size, 0);
  for (int i = 0; i < size; i++)
  {
    MyV1[i] = 1;
    MyV2[i] = 2;
    MyV3[i] = -1;
  }

  EXPECT_EQ(1, MyV3 == (MyV1 - MyV2));
}

TEST(TVector, can_multiply_vectors)
{
  const int size = 2;
  int res = 0;
  TVector<int> MyV1(size, 0), MyV2(size, 0);
  for (int i = 0; i < size; i++)
  {
    MyV1[i] = 3;
    MyV2[i] = 2;
    res += MyV1[i] * MyV2[i];
  }

  EXPECT_EQ(res, (MyV1 * MyV2));
}

TEST(TVector, can_multiply_vector_and_number)
{
  const int size = 2;
  TVector<int> MyV1(size, 0), MyV2(size, 0);
  for (int i = 0; i < size; i++)
  {
    MyV1[i] = 3;
    MyV2[i] = 6;
  }

  EXPECT_EQ(1, MyV2 == (MyV1 * 2));
}
