//
// Created by ianrobrien on 6/11/17.
//

#include "src/sorters.h"
#include <random>
#include <string>
#include "gtest/gtest.h"

class SortersTest : public ::testing::Test {
 protected:
  virtual void SetUp() {}

  int TEST_SIZE = 1000;

  int* get_sequential_list(int size) {
    int* values = new int[size];
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
    std::uniform_int_distribution<std::mt19937::result_type> dist6(0, range);
    return dist6(rng);
  }

  bool sequence_correct(int sequence[], int size) {
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