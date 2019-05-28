#include <gtest.h>
#include <TPolinom.h>
#include <iostream>


TEST(TPolinom, can_create_polinom_with_positive_size)
{
	ASSERT_NO_THROW(TPolinom p());
}


