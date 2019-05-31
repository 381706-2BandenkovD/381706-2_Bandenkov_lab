#include <gtest.h>
#include <TSortTable.h>


TEST(TSortTable, can_create_sort_table)
{
  ASSERT_NO_THROW(TSortTable<int> l);
}

TEST(TSortTable, can_add_record_to_sort_table)
{
  TSortTable<int> l;
  int v = 3;
  TTabRecord<int>* rec = new TTabRecord<int>("k", &v);
  ASSERT_NO_THROW(l.Add(rec));
}

TEST(TSortTable, can_add_multy_records_to_sort_table)
{
  TSortTable<int> l(4);
  int v1 = 3;
  TTabRecord<int>* rec1 = new TTabRecord<int>("k", &v1);
  int v2 = 3;
  TTabRecord<int>* rec2 = new TTabRecord<int>("l", &v2);
  int v3 = 3;
  TTabRecord<int>* rec3 = new TTabRecord<int>("m", &v3);
  l.Add(rec1);
  l.Add(rec2);
  ASSERT_NO_THROW(l.Add(rec3));
}

TEST(TSortTable, can_delete_record_in_sort_table)
{
  TSortTable<int> l;
  int v = 3;
  TTabRecord<int>* rec = new TTabRecord<int>("k", &v);
  l.Add(rec);
  ASSERT_NO_THROW(l.Delete("k"));
}

TEST(TSortTable, can_search_record_in_sort_table)
{
  TSortTable<int> l;
  int v = 3;
  TTabRecord<int>* rec = new TTabRecord<int>("k", &v);
  l.Add(rec);
  EXPECT_EQ(l.Search("k"), rec);
}

TEST(TSortTable, can_appeal_record_in_sort_table)
{
  TSortTable<int> l;
  int v = 3;
  TTabRecord<int>* rec = new TTabRecord<int>("k", &v);
  l.Add(rec);
  EXPECT_EQ(l["k"], &v);
}


TEST(TSortTable, can_convert_from_scan_to_sort_with_quicksort)
{
  TScanTable<int> l(4);
  int v1 = 3;
  TTabRecord<int>* rec1 = new TTabRecord<int>("k", &v1);
  int v2 = 3;
  TTabRecord<int>* rec2 = new TTabRecord<int>("l", &v2);
  int v3 = 3;
  TTabRecord<int>* rec3 = new TTabRecord<int>("m", &v3);
  l.Add(rec1);
  l.Add(rec2);
  l.Add(rec3);
  TSortTable<int> t(4);
  t.SetSortType(QUICK);
  ASSERT_NO_THROW(t = l);
}

TEST(TSortTable, can_convert_from_scan_to_sort_with_mergesort)
{
  TScanTable<int> l(4);
  int v1 = 3;
  TTabRecord<int>* rec1 = new TTabRecord<int>("k", &v1);
  int v2 = 3;
  TTabRecord<int>* rec2 = new TTabRecord<int>("l", &v2);
  int v3 = 3;
  TTabRecord<int>* rec3 = new TTabRecord<int>("m", &v3);
  l.Add(rec1);
  l.Add(rec2);
  l.Add(rec3);
  TSortTable<int> t(4);
  t.SetSortType(MERGE);
  ASSERT_NO_THROW(t = l);
}

TEST(TSortTable, can_convert_from_scan_to_sort_with_insertsort)
{
  TScanTable<int> l(4);
  int v1 = 3;
  TTabRecord<int>* rec1 = new TTabRecord<int>("k", &v1);
  int v2 = 3;
  TTabRecord<int>* rec2 = new TTabRecord<int>("l", &v2);
  int v3 = 3;
  TTabRecord<int>* rec3 = new TTabRecord<int>("m", &v3);
  l.Add(rec1);
  l.Add(rec2);
  l.Add(rec3);
  TSortTable<int> t(4);
  t.SetSortType(INSERT);
  ASSERT_NO_THROW(t = l);
}