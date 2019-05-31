#include <gtest.h>
#include <TScanTable.h>


TEST(TScanTable, can_create_scan_table)
{
  ASSERT_NO_THROW(TScanTable<int> l);
}

TEST(TScanTable, can_add_record_to_scan_table)
{
  TScanTable<int> l;
  int v = 3;
  TTabRecord<int>* rec = new TTabRecord<int>("k", &v);
  ASSERT_NO_THROW(l.Add(rec));
}

TEST(TScanTable, can_delete_record_in_scan_table)
{
  TScanTable<int> l;
  int v = 3;
  TTabRecord<int>* rec = new TTabRecord<int>("k", &v);
  l.Add(rec);
  ASSERT_NO_THROW(l.Delete("k"));
}

TEST(TScanTable, can_search_record_in_scan_table)
{
  TScanTable<int> l;
  int v = 3;
  TTabRecord<int>* rec = new TTabRecord<int>("k", &v);
  l.Add(rec);
  EXPECT_EQ(l.Search("k"), rec);
}

TEST(TScanTable, can_appeal_record_in_scan_table)
{
  TScanTable<int> l;
  int v = 3;
  TTabRecord<int>* rec = new TTabRecord<int>("k", &v);
  l.Add(rec);
  EXPECT_EQ(l["k"], &v);
}