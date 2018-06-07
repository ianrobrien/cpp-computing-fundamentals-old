//
// Created by ianrobrien on 2/28/17.
//

#include "../src/linked_list.h"
#include "gtest/gtest.h"

TEST(LinkedListTest, DefaultConstructor) {
    LinkedList<int> linkedList;
    ASSERT_EQ(linkedList.size(), 0);
    ASSERT_TRUE(linkedList.IsEmpty());
}

TEST(LinkedListTest, AddAndCountSize) {
    LinkedList<int> linkedList;
    linkedList.Add(new int32_t(0));
    ASSERT_EQ(linkedList.size(), 1);
    
    linkedList.Add(new int32_t(1));
    ASSERT_EQ(linkedList.size(), 2);
}


