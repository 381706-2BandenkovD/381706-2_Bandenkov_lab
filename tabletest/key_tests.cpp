#include <gtest.h>
#include <TKey.h>


TEST(TKey, can_create_key)
{
  ASSERT_NO_THROW(TKey k);
}

TEST(TKey, can_init_key)
{
  ASSERT_NO_THROW(TKey k("key"));
}

TEST(TKey, can_set_key)
{
  TKey k("key");
  TKey tk;
  tk.SetKey("key");
  EXPECT_EQ(tk == k, 1);
}

TEST(TKey, can_get_key)
{
  TKey k("key");
  char * res = k.GetKey();
  char* str = "key";
  bool flag = 1;
  for (int i = 0; i < strlen(str); i++)
  {
    if (res[i] != str[i])
      flag = 0;
  }
  EXPECT_EQ(flag, 1);
}

TEST(TKey, can_compare_keys_using_equal)
{
  TKey k1("key");
  TKey k2("key");
  EXPECT_EQ(k1 == k2, 1);
}

TEST(TKey, can_compare_keys_using_more)
{
  TKey k1("key");
  TKey k2("less");
  EXPECT_EQ(k1 > k2, 1);
}

TEST(TKey, can_compare_keys_using_less)
{
  TKey k1("key");
  TKey k2("less");
  EXPECT_EQ(k1 < k2, 0);
}

TEST(TKey, shorter_words_more)
{
  TKey k1("key");
  TKey k2("keya");
  EXPECT_EQ(k1 > k2, 1);
}