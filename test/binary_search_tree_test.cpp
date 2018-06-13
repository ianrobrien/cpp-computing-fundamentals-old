#include "src/binary_search_tree.h"
#include "gtest/gtest.h"

using namespace iro;

TEST(BinarySearchTreeTest, TestInfo) {
  util::binary_search_tree<int> bst;
  EXPECT_EQ(0, bst.size());
  bst.add(30);
  EXPECT_EQ(1, bst.size());
}
