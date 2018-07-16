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

#include "src/sorters.h"
#include <random>
#include <string>
#include "gtest/gtest.h"

class SortersTest : public ::testing::Test {
 protected:
  virtual void SetUp() {}

  int TEST_SIZE = 256;

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

  bool sequence_correct(const int sequence[], int size) {
    for (int i = 0; i < size; i++) {
      if (i != sequence[i]) {
        return false;
      }
    }
    return true;
  }

  // virtual void TearDown() {}
};

TEST_F(SortersTest, SequentialList) {
  auto sequence = get_sequential_list(TEST_SIZE);
  EXPECT_TRUE(sequence_correct(sequence, TEST_SIZE));
  delete[] sequence;
}

TEST_F(SortersTest, InsertionSort) {
  auto random = get_randomized_list(TEST_SIZE);
  iro::algorithms::sorters<int>::insertion_sort(random, TEST_SIZE);

  for (int i = 0; i < TEST_SIZE; i++) {
    EXPECT_EQ(i++, random[i]);
  }

  delete[] random;
}

TEST_F(SortersTest, SelectionSort) {
  auto random = get_randomized_list(TEST_SIZE);
  iro::algorithms::sorters<int>::selection_sort(random, TEST_SIZE);

  for (int i = 0; i < TEST_SIZE; i++) {
    EXPECT_EQ(i++, random[i]);
  }

  delete[] random;
}

TEST_F(SortersTest, BubbleSort) {
  auto random = get_randomized_list(TEST_SIZE);
  iro::algorithms::sorters<int>::bubble_sort(random, TEST_SIZE);

  for (int i = 0; i < TEST_SIZE; i++) {
    EXPECT_EQ(i, random[i]);
  }

  delete[] random;
}

TEST_F(SortersTest, MergeSort) {
  auto random = get_randomized_list(TEST_SIZE);
  iro::algorithms::sorters<int>::merge_sort(random, TEST_SIZE);

  for (int i = 0; i < TEST_SIZE; i++) {
    EXPECT_EQ(i, random[i]);
  }

  delete[] random;
}
