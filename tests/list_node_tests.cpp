//
// Created by ianrobrien on 2/28/17.
//

#include "../src/list_node.h"
#include "gtest/gtest.h"

TEST(ListNodeTest, DefaultConstructor) {
    int *test_value = nullptr;
    ListNode<int> *listNode = new ListNode<int>(test_value);
    ASSERT_EQ(listNode->GetData(), test_value);
    delete listNode;
}
