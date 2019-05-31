#include <gtest.h>
#include <TQueue.h>
#include <TExeption.h>
#include <iostream>


TEST(TQueue, can_create_stack_with_positive_size)
{
  ASSERT_NO_THROW(TQueue<int> s(3));
}


TEST(TQueue, can_create_stack_with_zero_size)
{
  ASSERT_NO_THROW(TQueue<int> s(0));
}

TEST(TQueue, throw_when_negative_size)
{
  ASSERT_ANY_THROW(TQueue<int> s(-3));
}

TEST(TQueue, can_get_size)
{
  TQueue<int> MyQueue(100);

  EXPECT_EQ(100, MyQueue.GetSize());
}

TEST(TQueue, empty_stack_is_empty)
{
  TQueue<int> MyQueue(10);

  EXPECT_EQ(1, MyQueue.IsEmpty());
}

TEST(TQueue, full_stack_is_full)
{
  const int Size = 5;
  TQueue<int> MyQueue(Size);
  for (int i = 0; i < Size; i++)
    MyQueue.Put(7);
  EXPECT_EQ(1, MyQueue.IsFull());
}

TEST(TQueue, throw_when_put_into_full_stack)
{
  const int Size = 5;
  TQueue<int> MyQueue(Size);
  for (int i = 0; i < Size; i++)
    MyQueue.Put(7);
  ASSERT_ANY_THROW(MyQueue.Put(3));
}

TEST(TQueue, can_put_value)
{
  TQueue<int> MyQueue(10);

  ASSERT_NO_THROW(MyQueue.Put(5));
}


TEST(TQueue, can_get_value)
{
  TQueue<int> MyQueue(10);
  MyQueue.Put(5);

  EXPECT_EQ(5, MyQueue.Get());
}

TEST(TQueue, can_put_multy_value)
{
  TQueue<int> MyQueue(10);
  MyQueue.Put(3);
  MyQueue.Put(1);
  MyQueue.Put(4);
  MyQueue.Put(1);
  MyQueue.Put(5);
  EXPECT_EQ(3, MyQueue.Get());
}

TEST(TQueue, throw_when_get_from_empty_stack)
{
  const int Size = 5;
  TQueue<int> MyQueue(Size);
  ASSERT_ANY_THROW(MyQueue.Get());
}