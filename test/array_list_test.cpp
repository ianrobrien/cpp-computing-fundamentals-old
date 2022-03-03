/****************************************************************************
 * Copyright (c) 2018-present, Ian R. O'Brien                               *
 *                                                                          *
 * Licensed under the MIT License (the "License");                          *
 *  you may not use this file except in compliance with the License.        *
 * You may obtain a copy of the License at                                  *
 *                                                                          *
 *     https://opensource.org/licenses/MIT                                  *
 *                                                                          *
 * Unless required by applicable law or agreed to in writing, software      *
 * distributed under the License is distributed on an "AS IS" BASIS,        *
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. *
 * See the License for the specific language governing permissions and      *
 * limitations under the License.                                           *
 ***************************************************************************/

#include "src/array_list.h"
#include <string>
#include "gtest/gtest.h"

using namespace iro::utils;

class array_list_test : public ::testing::Test {
 protected:
  virtual void SetUp() {}

  int TEST_SIZE = 100;

  array_list<int>* get_sequential_list(int size) {
    auto ll = new array_list<int>();
    for (int i = 0; i < size; i++) {
      ll->add(i);
    }
    return ll;
  }

  // virtual void TearDown() {}
};

TEST_F(array_list_test, DeletesAllNodes) {
  auto ll = get_sequential_list(TEST_SIZE);
  delete ll;

  ll = get_sequential_list(TEST_SIZE);
  ll->clear();
  EXPECT_EQ(0, ll->size());
}

TEST_F(array_list_test, IsInitiallyEmpty) {
  auto ll = array_list<int>();
  EXPECT_EQ(0, ll.size());
  EXPECT_TRUE(ll.empty());
}

TEST_F(array_list_test, addsToTail) {
  auto ll = get_sequential_list(TEST_SIZE);
  EXPECT_EQ(TEST_SIZE, ll->size());

  for (int i = 0; i < TEST_SIZE; i++) {
    EXPECT_EQ(i, ll->get(i));
  }

  delete ll;
}

TEST_F(array_list_test, addsAtFront) {
  auto TEST_SIZE = 10;
  auto ll = array_list<int>();
  for (int i = TEST_SIZE - 1; i >= 0; i--) {
    ll.add(0, i);
  }
  EXPECT_EQ(TEST_SIZE, ll.size());

  for (int i = 0; i < TEST_SIZE; i++) {
    EXPECT_EQ(i, ll.get(i));
  }
}

TEST_F(array_list_test, addsAtMiddle) {
  auto TEST_SIZE = 10;
  auto ll = array_list<int>();
  ll.add(0);
  ll.add(1);
  ll.add(2);
  ll.add(4);
  ll.add(5);
  ll.add(3, 3);
  for (int i = 0; i < 6; i++) {
    EXPECT_EQ(i, ll.get(i));
  }
}

TEST_F(array_list_test, FindsIndex) {
  auto ll = get_sequential_list(TEST_SIZE);
  EXPECT_EQ(50, ll->index_of(50));
  EXPECT_EQ(0, ll->index_of(0));
  EXPECT_EQ(99, ll->index_of(99));
  EXPECT_EQ(-1, ll->index_of(100));

  EXPECT_FALSE(ll->contains(-1));
  EXPECT_FALSE(ll->contains(100));

  ll = new array_list<int>();
  ll->add(5);
  ll->add(1);
  ll->add(3);
  ll->add(5);
  ll->add(2);
  EXPECT_EQ(0, ll->index_of(5));
  EXPECT_EQ(3, ll->last_index_of(5));
}

TEST_F(array_list_test, removesElement) {
  auto TEST_SIZE = 10;
  auto ll = array_list<int>();
  // remove from Front
  for (int i = 0; i < TEST_SIZE; i++) {
    ll.add(0, i);
  }
  for (int i = 0; i < TEST_SIZE; i++) {
    ll.remove(i);
    EXPECT_EQ(TEST_SIZE - 1 - i, ll.size());
  }

  // remove from Back
  for (int i = 0; i < TEST_SIZE; i++) {
    ll.add(0, i);
  }
  for (int i = TEST_SIZE - 1; i >= 0; i--) {
    ll.remove(i);
    EXPECT_EQ(i, ll.size());
  }

  // remove from Middle
  ll.clear();
  ll.add(0);
  ll.add(1);
  ll.add(99);
  ll.add(2);
  ll.add(3);
  ll.remove(99);
  for (int i = 0; i < ll.size(); i++) {
    EXPECT_EQ(i, ll.get(i));
  }
}

TEST_F(array_list_test, removesAtIndex) {
  auto ll = new array_list<int>();

  ll = new array_list<int>();
  ll->add(0);
  ll->add(1);
  ll->add(2);
  ll->remove_at(0);
  EXPECT_EQ(2, ll->size());
  EXPECT_EQ(1, ll->get(0));
  EXPECT_EQ(2, ll->get(1));
  delete ll;

  ll = new array_list<int>();
  ll->add(0);
  ll->add(1);
  ll->add(2);
  ll->remove_at(1);
  EXPECT_EQ(2, ll->size());
  EXPECT_EQ(0, ll->get(0));
  EXPECT_EQ(2, ll->get(1));
  delete ll;

  ll = new array_list<int>();
  ll->add(0);
  ll->add(1);
  ll->add(2);
  ll->remove_at(2);
  EXPECT_EQ(2, ll->size());
  EXPECT_EQ(0, ll->get(0));
  EXPECT_EQ(1, ll->get(1));
}

TEST_F(array_list_test, ThrowsExpectedExecptions) {
  auto ll = array_list<int>();
  try {
    ll.add(10, 10);
  } catch (std::invalid_argument const& err) {
    auto test = err.what();
    EXPECT_EQ(err.what(), std::string("Index: 10, Size: 0"));
  }
}
