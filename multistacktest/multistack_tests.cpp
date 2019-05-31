#include <gtest.h>
#include <TMultiStack.h>
#include <iostream>


TEST(TMultiStack, can_create_multistack_with_positive_size)
{
	ASSERT_NO_THROW(TMultiStack<int> v(9, 3));
}

TEST(TMultiStack, throw_when_negative_size)
{
	ASSERT_ANY_THROW(TMultiStack<int> v(-3, 1));
}

TEST(TMultiStack, throw_when_negative_count)
{
	ASSERT_ANY_THROW(TMultiStack<int> v(-3, -1));
}


TEST(TMultiStack, empty_stack_is_empty)
{
	TMultiStack<int> MyMultiStack(10, 2);

	EXPECT_EQ(1, MyMultiStack.IsEmpty(0));
}

TEST(TMultiStack, full_stack_is_full)
{
	const int Size = 10;
	TMultiStack<int> MyMultiStack(Size, 2);
	for (int i = 0; i < Size/2; i++)
		MyMultiStack.Put(0, 7);
	EXPECT_EQ(1, MyMultiStack.IsFull(0));
}

TEST(TMultiStack, relocation_not_change_stack)
{
	const int Size = 4;
	const int Count = 2;
	TMultiStack<int> MyMultiStack(Size, Count), MyMultiStack1(Size, Count);
	for (int i = 0; i < 2; i++)
		MyMultiStack.Put(0, 7);
	MyMultiStack1 = MyMultiStack;
	MyMultiStack.Put(0, 3);
	MyMultiStack.Get(0);
	EXPECT_EQ(1, MyMultiStack == MyMultiStack1);
}

TEST(TMultiStack, can_put_value)
{
	TMultiStack<int> MyMultiStack(10, 2);

	ASSERT_NO_THROW(MyMultiStack.Put(1, 5));
}


TEST(TMultiStack, can_get_value)
{
	TMultiStack<int> MyMultiStack(10, 2);
	MyMultiStack.Put(1,5);

	EXPECT_EQ(5, MyMultiStack.Get(1));
}

TEST(TMultiStack, can_put_multy_value)
{
	TMultiStack<int> MyMultiStack(10, 2);
	MyMultiStack.Put(0,3);
	MyMultiStack.Put(0,1);
	MyMultiStack.Put(0,4);
	MyMultiStack.Put(0,1);
	MyMultiStack.Put(0,5);
	MyMultiStack.Put(1, 2);
	MyMultiStack.Put(1, 7);
	MyMultiStack.Put(1, 1);
	MyMultiStack.Put(1, 8);
	MyMultiStack.Put(1, 2);
	EXPECT_EQ(5, MyMultiStack.Get(0));
}

TEST(TMultiStack, throw_when_get_from_empty_stack)
{
	const int Size = 5;
	TMultiStack<int> MyMultiStack(Size, 2);
	ASSERT_ANY_THROW(MyMultiStack.Get(0));
}
