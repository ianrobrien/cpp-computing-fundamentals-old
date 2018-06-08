//
// Created by ianrobrien on 2/28/17.
//

#include "gtest/gtest.h"
#include "src/list_node.h"

TEST(ListNodeTest, DefaultConstructor) {
  auto listNode = ListNode<std::string>("testValue");
  ASSERT_EQ(listNode.value(), "testValue");
}
