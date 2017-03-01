//
// Created by ianrobrien on 2/28/17.
//

#include "../src/linked_list.h"
#include "gtest/gtest.h"

TEST(LinkedListTest, AddAndCountSize) {
    LinkedList<int> linkedList;
    ASSERT_EQ(linkedList.Size(), 0);
    linkedList.Add(0);
    ASSERT_EQ(linkedList.Size(), 1);
}