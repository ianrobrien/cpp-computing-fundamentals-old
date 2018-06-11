//
// Created by ianrobrien on 2/28/17.
//

#include "gtest/gtest.h"
#include "src/list_node.h"

using namespace iro;

TEST(ListNodeTest, DefaultConstructor) {
  auto listNode = list_node<std::string>("testValue");
  ASSERT_EQ(listNode.value(), "testValue");
}
