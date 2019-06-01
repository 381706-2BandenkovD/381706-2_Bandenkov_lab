#include <gtest.h>
#include <TListHash.h>


TEST(TListHash, can_create_list_hash_table)
{
  ASSERT_NO_THROW(TListHash<int> l);
}

TEST(TListHash, can_add_record_to_list_hash_table)
{
  TListHash<int> l;
  int v = 3;
  TTabRecord<int>* rec = new TTabRecord<int>("k", &v);
  ASSERT_NO_THROW(l.Add(rec));
}

TEST(TListHash, can_delete_record_in_list_hash_table)
{
  TListHash<int> l;
  int v = 3;
  TTabRecord<int>* rec = new TTabRecord<int>("k", &v);
  l.Add(rec);
  ASSERT_NO_THROW(l.Delete("k"));
}

TEST(TListHash, can_search_record_in_list_hash_table)
{
  TListHash<int> l;
  int v = 3;
  TTabRecord<int>* rec = new TTabRecord<int>("k", &v);
  l.Add(rec);
  EXPECT_EQ(l.Search("k"), rec);
}

TEST(TListHash, can_appeal_record_in_list_hash_table)
{
  TListHash<int> l;
  int v = 3;
  TTabRecord<int>* rec = new TTabRecord<int>("k", &v);
  l.Add(rec);
  EXPECT_EQ(l["k"], &v);
}