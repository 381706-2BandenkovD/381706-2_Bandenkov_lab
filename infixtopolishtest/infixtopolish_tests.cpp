#include <gtest.h>
#include <InfixToPolish.h>


TEST(TInfixToPolish, can_convert_simple_array_char)
{
    char* exp = (char*)"2+2=";
    char* expect = (char*)"2 2 +=";
    char* res = TInfixToPolish().ConvertToPolish(exp, strlen(exp));
    bool flag = 1;
    for (int i = 0; i < strlen(expect); i++)
    {
        flag *= (res[i] == expect[i]);
    }
    delete res;

    ASSERT_EQ(1, flag);
}

TEST(TInfixToPolish, can_calculate_simple_array_char)
{
    char* exp = (char*)"2+2=";
    char* str = TInfixToPolish().ConvertToPolish(exp, strlen(exp));
    int res = TInfixToPolish().Calculate(str, strlen(str));
    ASSERT_EQ(4, res);
}

TEST(TInfixToPolish, can_convert_tree_digit_numbers_array_char)
{
    char* exp = (char*)"365-221=";
    char* expect = (char*)"365 221 -=";
    char* res = TInfixToPolish().ConvertToPolish(exp, strlen(exp));
    bool flag = 1;
    for (int i = 0; i < strlen(expect); i++)
    {
        flag *= (res[i] == expect[i]);
    }
    delete res;

    ASSERT_EQ(1, flag);
}

TEST(TInfixToPolish, can_calculate_tree_digit_numbers_array_char)
{
    char* exp = (char*)"365-221=";
    char* str = TInfixToPolish().ConvertToPolish(exp, strlen(exp));
    int res = TInfixToPolish().Calculate(str, strlen(str));
    ASSERT_EQ(144, res);
}

TEST(TInfixToPolish, can_convert_many_operators_array_char)
{
    char* exp = (char*)"1+2*3=";
    char* expect = (char*)"1 2 3 *+=";
    char* res = TInfixToPolish().ConvertToPolish(exp, strlen(exp));
    bool flag = 1;
    for (int i = 0; i < strlen(expect); i++)
    {
        flag *= (res[i] == expect[i]);
    }
    delete res;

    ASSERT_EQ(1, flag);
}

TEST(TInfixToPolish, can_calculate_many_operators_array_char)
{
    char* exp = (char*)"1+2*3=";
    char* str = TInfixToPolish().ConvertToPolish(exp, strlen(exp));
    int res = TInfixToPolish().Calculate(str, strlen(str));
    ASSERT_EQ(7, res);
}

TEST(TInfixToPolish, can_convert_array_char_with_brackets)
{
    char* exp = (char*)"(1+2)*3=";
    char* expect = (char*)"1 2 +3 *=";
    char* res = TInfixToPolish().ConvertToPolish(exp, strlen(exp));
    bool flag = 1;
    for (int i = 0; i < strlen(expect); i++)
    {
        flag *= (res[i] == expect[i]);
    }
    delete res;

    ASSERT_EQ(1, flag);
}

TEST(TInfixToPolish, can_calculate_array_char_with_brackets)
{
    char* exp = (char*)"(1+2)*3=";
    char* str = TInfixToPolish().ConvertToPolish(exp, strlen(exp));
    int res = TInfixToPolish().Calculate(str, strlen(str));
    ASSERT_EQ(9, res);
}