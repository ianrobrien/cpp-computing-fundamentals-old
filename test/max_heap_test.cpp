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

#include "src/max_heap.h"
#include <random>
#include "gtest/gtest.h"

using namespace iro;

class max_heap_test : public ::testing::Test {
 protected:
  virtual void SetUp() {}

  int TEST_SIZE = 100;

  int* get_sequential_list(int size) {
    auto* values = new int[size];
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

TEST_F(max_heap_test, TestAdd) {
  auto mh = new iro::utils::max_heap<int>();
  EXPECT_EQ(0, mh->size());
  mh->push(10);
  EXPECT_EQ(1, mh->size());
  mh->push(5);
  mh->push(4);
  mh->push(99);
  EXPECT_EQ(4, mh->size());
  delete mh;
}

TEST_F(max_heap_test, TestMaxness) {
  auto random_numbers = get_randomized_list(1000);

  utils::max_heap<int> mh;
  for (int i = 0; i < 1000; i++) {
    mh.push(i);
  }
  EXPECT_EQ(1000, mh.size());
  EXPECT_EQ(999, mh.peek());

  delete random_numbers;
}

TEST_F(max_heap_test, TestContains) {}

TEST_F(max_heap_test, InOrderTraversal) {}