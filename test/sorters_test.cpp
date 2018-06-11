//
// Created by ianrobrien on 2/28/17.
//

#include "src/sorters.h"
#include <random>
#include <string>
#include "gtest/gtest.h"

class SortersTest : public ::testing::Test {
 protected:
  virtual void SetUp() {}

  int TEST_SIZE = 1000;

  int* GetSequentialList(int size) {
    int* values = new int[size];
    for (int i = 0; i < size; i++) {
      values[i] = i;
    }
    return values;
  }

  int* GetRandomizedList(int size) {
    auto unsortedList = GetSequentialList(size);
    for (int i = 0; i < size; i++) {
      int tempIndex = GetRandomNumber(TEST_SIZE - 1);
      int tempValue = unsortedList[i];
      unsortedList[i] = unsortedList[tempIndex];
      unsortedList[tempIndex] = tempValue;
    }
    return unsortedList;
  }

  int GetRandomNumber(int range) {
    std::mt19937 rng;
    rng.seed(std::random_device()());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(0, range);
    return dist6(rng);
  }

  bool SequenceCorrect(int sequence[], int size) {
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
  auto sequence = GetSequentialList(TEST_SIZE);
  EXPECT_TRUE(SequenceCorrect(sequence, TEST_SIZE));
  delete[] sequence;
}

TEST_F(SortersTest, SelectionSort) {
  auto random = GetRandomizedList(TEST_SIZE);
  iro::algorithms::Sorters<int>::SelectionSort(random, TEST_SIZE);

  for (int i = 0; i < TEST_SIZE; i++) {
    EXPECT_EQ(i++, random[i]);
  }

  delete[] random;
}

TEST_F(SortersTest, BubbleSort) {
  auto random = GetRandomizedList(TEST_SIZE);
  iro::algorithms::Sorters<int>::BubbleSort(random, TEST_SIZE);

  for (int i = 0; i < TEST_SIZE; i++) {
    EXPECT_EQ(i, random[i]);    
  }

  delete[] random;
}