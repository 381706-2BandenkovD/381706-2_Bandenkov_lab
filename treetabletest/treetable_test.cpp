#include <gtest.h>
#include <TTreeTable.h>


TEST(TTreeTable, can_create_tree_table)
{
  ASSERT_NO_THROW(TTreeTable<int> l);
}

TEST(TTreeTable, can_add_record_to_tree_table)
{
  TTreeTable<int> l;
  int v = 3;
  TTreeNode<int>* rec = new TTreeNode<int>("k", &v);
  ASSERT_NO_THROW(l.Add(rec));
}

TEST(TTreeTable, can_add_multy_records_to_tree_table)
{
  TTreeTable<int> l;
  int v1 = 3;
  TTreeNode<int>* rec1 = new TTreeNode<int>("m", &v1);
  int v2 = 3;
  TTreeNode<int>* rec2 = new TTreeNode<int>("k", &v2);
  int v3 = 3;
  TTreeNode<int>* rec3 = new TTreeNode<int>("l", &v3);
  l.Add(rec1);
  l.Add(rec2);
  ASSERT_NO_THROW(l.Add(rec3));
}

TEST(TTreeTable, can_delete_record_in_tree_table)
{
  TTreeTable<int> l;
  int v = 3;
  TTreeNode<int>* rec = new TTreeNode<int>("k", &v);
  l.Add(rec);
  ASSERT_NO_THROW(l.Delete("k"));
}

TEST(TTreeTable, can_delete_record_in_full_tree_table)
{
  TTreeTable<int> l;
  int v = 3;
  l["d"];
  l["c"];
  l["f"];
  l["e"];
  l["h"];
  l["ga"];
  l["g"];
  l["gb"];
  l["j"];
  ASSERT_NO_THROW(l.Delete("h"));
}

TEST(TTreeTable, can_search_record_in_tree_table)
{
  TTreeTable<int> l;
  int v = 3;
  TTreeNode<int>* rec = new TTreeNode<int>("k", &v);
  l.Add(rec);
  EXPECT_EQ(l.Search("k"), rec);
}

TEST(TTreeTable, can_appeal_record_in_tree_table)
{
  TTreeTable<int> l;
  int v = 3;
  TTreeNode<int>* rec = new TTreeNode<int>("k", &v);
  l.Add(rec);
  EXPECT_EQ(l["k"], &v);
}