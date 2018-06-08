//
// Created by ianrobrien on 2/28/17.
//

#include <string>
#include "gtest/gtest.h"
#include "src/linked_list.h"

class LinkedListTest : public ::testing::Test {
 protected:
  virtual void SetUp() {}

  int TEST_SIZE = 100;

  LinkedList<int>* GetSequentialList(int size) {
    auto ll = new LinkedList<int>();
    for (int i = 0; i < size; i++) {
      ll->Add(i);
    }
    return ll;
  }

  // virtual void TearDown() {}
};

TEST_F(LinkedListTest, DeletesAllNodes) {
  auto ll = GetSequentialList(TEST_SIZE);
  delete ll;

  ll = GetSequentialList(TEST_SIZE);
  ll->Clear();
  EXPECT_EQ(0, ll->size());
}

TEST_F(LinkedListTest, IsInitiallyEmpty) {
  auto ll = LinkedList<int>();
  EXPECT_EQ(0, ll.size());
  EXPECT_TRUE(ll.IsEmpty());
}

TEST_F(LinkedListTest, AddsToTail) {
  auto ll = GetSequentialList(TEST_SIZE);
  EXPECT_EQ(TEST_SIZE, ll->size());

  for (int i = 0; i < TEST_SIZE; i++) {
    EXPECT_EQ(i, ll->Get(i));
  }

  delete ll;
}

TEST_F(LinkedListTest, AddsAtFront) {
  auto TEST_SIZE = 10;
  auto ll = LinkedList<int>();
  for (int i = TEST_SIZE - 1; i >= 0; i--) {
    ll.Add(0, i);
  }
  EXPECT_EQ(TEST_SIZE, ll.size());

  for (int i = 0; i < TEST_SIZE; i++) {
    EXPECT_EQ(i, ll.Get(i));
  }
}

TEST_F(LinkedListTest, AddsAtMiddle) {
  auto TEST_SIZE = 10;
  auto ll = LinkedList<int>();
  ll.Add(0);
  ll.Add(1);
  ll.Add(2);
  ll.Add(4);
  ll.Add(5);
  ll.Add(3, 3);
  for (int i = 0; i < 6; i++) {
    EXPECT_EQ(i, ll.Get(i));
  }
}

TEST_F(LinkedListTest, FindsIndex) {
  auto ll = GetSequentialList(TEST_SIZE);
  EXPECT_EQ(50, ll->IndexOf(50));
  EXPECT_EQ(0, ll->IndexOf(0));
  EXPECT_EQ(99, ll->IndexOf(99));
  EXPECT_EQ(-1, ll->IndexOf(100));

  EXPECT_FALSE(ll->Contains(-1));
  EXPECT_FALSE(ll->Contains(100));

  ll = new LinkedList<int>();
  ll->Add(5);
  ll->Add(1);
  ll->Add(3);
  ll->Add(5);
  ll->Add(2);
  EXPECT_EQ(0, ll->IndexOf(5));
  EXPECT_EQ(3, ll->LastIndexOf(5));
}

TEST_F(LinkedListTest, RemovesElement) {
  auto TEST_SIZE = 10;
  auto ll = LinkedList<int>();
  // Remove from Front
  for (int i = 0; i < TEST_SIZE; i++) {
    ll.Add(0, i);
  }
  for (int i = 0; i < TEST_SIZE; i++) {
    ll.Remove(i);
    EXPECT_EQ(TEST_SIZE - 1 - i, ll.size());
  }

  // Remove from Back
  for (int i = 0; i < TEST_SIZE; i++) {
    ll.Add(0, i);
  }
  for (int i = TEST_SIZE - 1; i >= 0; i--) {
    ll.Remove(i);
    EXPECT_EQ(i, ll.size());
  }

  // Remove from Middle
  ll.Add(0);
  ll.Add(1);
  ll.Add(99);
  ll.Add(2);
  ll.Add(3);
  ll.Remove(99);
  for (int i = 0; i < ll.size(); i++) {
    EXPECT_EQ(i, ll.Get(i));
  }
}

TEST_F(LinkedListTest, RemovesAtIndex) {
  auto ll = new LinkedList<int>();

  ll = new LinkedList<int>();
  ll->Add(0);
  ll->Add(1);
  ll->Add(2);
  ll->RemoveAt(0);
  EXPECT_EQ(2, ll->size());
  EXPECT_EQ(1, ll->Get(0));
  EXPECT_EQ(2, ll->Get(1));
  delete ll;

  ll = new LinkedList<int>();
  ll->Add(0);
  ll->Add(1);
  ll->Add(2);
  ll->RemoveAt(1);
  EXPECT_EQ(2, ll->size());
  EXPECT_EQ(0, ll->Get(0));
  EXPECT_EQ(2, ll->Get(1));
  delete ll;

  ll = new LinkedList<int>();
  ll->Add(0);
  ll->Add(1);
  ll->Add(2);
  ll->RemoveAt(2);
  EXPECT_EQ(2, ll->size());
  EXPECT_EQ(0, ll->Get(0));
  EXPECT_EQ(1, ll->Get(1));
}

TEST_F(LinkedListTest, ThrowsExpectedExecptions) {
  auto ll = LinkedList<int>();
  try {
    ll.Add(10, 10);
  } catch (std::invalid_argument const& err) {
    auto test = err.what();
    EXPECT_EQ(err.what(), std::string("Index: 10, Size: 0"));
  }
}