#include <gtest.h>
#include <TTabRecord.h>

TEST(TTabRecord, can_create_record)
{
  ASSERT_NO_THROW(TTabRecord<int> r);
}

TEST(TTabRecord, can_set_key)
{
  TTabRecord<int> r;
  ASSERT_NO_THROW(r.SetKey(TKey("mk")));
}

TEST(TTabRecord, can_get_key)
{
  TTabRecord<int> r;
  r.SetKey(TKey("mk"));
  EXPECT_EQ(r.GetKey() == TKey("mk"), 1);
}

TEST(TTabRecord, can_set_value)
{
  TTabRecord<int> r;
  r.SetToDel(false);
  int v = 3;
  ASSERT_NO_THROW(r.SetValue(&v));
}

TEST(TTabRecord, can_get_value)
{
  TTabRecord<int> r;
  int v = 3;
  r.SetValue(&v);
  r.SetToDel(false);
  EXPECT_EQ(*r.GetVal(), 3);
}

TEST(TTabRecord, can_compare_records_using_equal)
{
  TKey k1("key");
  TKey k2("key");
  TTabRecord<int> r1, r2;
  r1.SetKey(k1);
  r2.SetKey(k2);
  EXPECT_EQ(r1 == r2, 1);
}

TEST(TTabRecord, can_compare_records_using_more)
{
  TKey k1("key");
  TKey k2("less");
  TTabRecord<int> r1, r2;
  r1.SetKey(k1);
  r2.SetKey(k2);
  EXPECT_EQ(r1 > r2, 1);
}

TEST(TTabRecord, can_compare_records_using_less)
{
  TKey k1("key");
  TKey k2("less");
  TTabRecord<int> r1, r2;
  r1.SetKey(k1);
  r2.SetKey(k2);
  EXPECT_EQ(r1 < r2, 0);
}