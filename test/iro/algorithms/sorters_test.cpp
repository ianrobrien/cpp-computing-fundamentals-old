//
// Created by ianrobrien on 2/28/17.
//

#include "src/iro/algorithms/sorters.h"
#include <string>
#include "gtest/gtest.h"

class SortersTest : public ::testing::Test {
 protected:
  virtual void SetUp() {}

  int TEST_SIZE = 100;

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
      int tempIndex = 100 % size;
      int tempValue = unsortedList[i];
      unsortedList[i] = unsortedList[tempIndex];
      unsortedList[tempIndex] = tempValue;
    }
  }

  // virtual void TearDown() {}
};

TEST_F(SortersTest, BubbleSort) {
  int* values = GetSequentialList(TEST_SIZE);
  iro::algorithms::Sorters<int>::BubbleSort(values);
}