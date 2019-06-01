#include <gtest.h>
#include <THashTable.h>


TEST(THashTable, can_create_hash_table)
{
  ASSERT_NO_THROW(THashTable<int> l);
}

TEST(THashTable, can_add_record_to_hash_table)
{
  THashTable<int> l;
  int v = 3;
  TTabRecord<int>* rec = new TTabRecord<int>("k", &v);
  ASSERT_NO_THROW(l.Add(rec));
}

TEST(THashTable, can_delete_record_in_hash_table)
{
  THashTable<int> l;
  int v = 3;
  TTabRecord<int>* rec = new TTabRecord<int>("k", &v);
  l.Add(rec);
  ASSERT_NO_THROW(l.Delete("k"));
}

TEST(THashTable, can_search_record_in_hash_table)
{
  THashTable<int> l;
  int v = 3;
  TTabRecord<int>* rec = new TTabRecord<int>("k", &v);
  l.Add(rec);
  EXPECT_EQ(l.Search("k"), rec);
}

TEST(THashTable, can_appeal_record_in_hash_table)
{
  THashTable<int> l;
  int v = 3;
  TTabRecord<int>* rec = new TTabRecord<int>("k", &v);
  l.Add(rec);
  EXPECT_EQ(l["k"], &v);
}