#include <gtest.h>
#include <TStack.h>
#include <TExeption.h>
#include <iostream>


TEST(TStack, can_create_stack_with_positive_size)
{
	ASSERT_NO_THROW(TStack<int> s(3));
}


TEST(TStack, can_create_stack_with_zero_size)
{
	ASSERT_NO_THROW(TStack<int> s(0));
}

TEST(TStack, throw_when_negative_size)
{
	ASSERT_ANY_THROW(TStack<int> s(-3));
}

TEST(TStack, can_get_size)
{
	TStack<int> MyStack(100);

	EXPECT_EQ(100, MyStack.GetSize());
}

TEST(TStack, empty_stack_is_empty)
{
	TStack<int> MyStack(10);

	EXPECT_EQ(1, MyStack.IsEmpty());
}

TEST(TStack, full_stack_is_full)
{
	const int Size = 5;
	TStack<int> MyStack(Size);
	for(int i =0; i < Size; i++)
		MyStack.Put(7);
	EXPECT_EQ(1, MyStack.IsFull());
}

TEST(TStack, throw_when_put_into_full_stack)
{
	const int Size = 5;
	TStack<int> MyStack(Size);
	for (int i = 0; i < Size; i++)
		MyStack.Put(7);
	ASSERT_ANY_THROW(MyStack.Put(3));
}

TEST(TStack, can_put_value)
{
	TStack<int> MyStack(10);

	ASSERT_NO_THROW(MyStack.Put(5));
}


TEST(TStack, can_get_value)
{
	TStack<int> MyStack(10);
	MyStack.Put(5);

	EXPECT_EQ(5, MyStack.Get());
}

TEST(TStack, can_put_multy_value)
{
	TStack<int> MyStack(10);
	MyStack.Put(3);
	MyStack.Put(1);
	MyStack.Put(4);
	MyStack.Put(1);
	MyStack.Put(5);
	EXPECT_EQ(5, MyStack.Get());
}

TEST(TStack, throw_when_get_from_empty_stack)
{
	const int Size = 5;
	TStack<int> MyStack(Size);
	ASSERT_ANY_THROW(MyStack.Get());
}