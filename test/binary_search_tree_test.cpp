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

#include "src/binary_search_tree.h"
#include <random>
#include "gtest/gtest.h"

using namespace iro;

class binary_search_tree_test : public ::testing::Test {
 protected:
  virtual void SetUp() {}

  int TEST_SIZE = 1000;

  int* get_sequential_list(int size) {
    auto values = new int[size];
    for (int i = 0; i < size; i++) {
      values[i] = i;
    }
    return values;
  }

  int* get_randomized_list(int size) {
    auto unsortedList = get_sequential_list(size);
    for (int i = 0; i < size; i++) {
      int tempIndex = get_random_number(TEST_SIZE - 1);
      int tempValue = unsortedList[i];
      unsortedList[i] = unsortedList[tempIndex];
      unsortedList[tempIndex] = tempValue;
    }
    return unsortedList;
  }

  int get_random_number(int range) {
    std::mt19937 rng;
    rng.seed(std::random_device()());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(
        0, static_cast<unsigned long>(range));
    return static_cast<int>(dist6(rng));
  }

  // virtual void TearDown() {}
};

TEST_F(binary_search_tree_test, TestAdd) {
  auto test_data = get_randomized_list(TEST_SIZE);

  utils::binary_search_tree<int> bst;
  for (int i = 0; i < TEST_SIZE; i++) {
    bst.add(test_data[i]);
  }
  EXPECT_EQ(TEST_SIZE, bst.size());

  delete test_data;
}

TEST_F(binary_search_tree_test, TestContains) {
  auto test_data = get_randomized_list(TEST_SIZE);
  auto results = get_sequential_list(TEST_SIZE);

  utils::binary_search_tree<int> bst;
  for (int i = 0; i < TEST_SIZE; i++) {
    bst.add(test_data[i]);
  }
  EXPECT_EQ(TEST_SIZE, bst.size());
  for (int i = 0; i < TEST_SIZE; i++) {
    EXPECT_TRUE(bst.contains(i));
  }

  delete test_data;
  delete results;
}

TEST_F(binary_search_tree_test, InOrderTraversal) {
  auto results = get_sequential_list(TEST_SIZE);

  utils::binary_search_tree<int> bst;
  for (int i = 0; i < TEST_SIZE; i++) {
    bst.add(results[i]);
  }

  EXPECT_EQ(TEST_SIZE, bst.size());
  auto actual = bst.in_order_traversal();
  for (int i = 0; i < TEST_SIZE; i++) {
    EXPECT_EQ(i, actual->get(i));
  }

  delete results;
}