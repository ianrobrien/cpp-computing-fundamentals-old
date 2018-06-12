//
// Created by ianrobrien on 2/28/17.
//

#include "gtest/gtest.h"
#include "src/array_utils.h"
#include "src/list_node.h"

using namespace iro;

TEST(ArrayUtilsTest, Swap) {
  int TEST_SIZE = 100;
  int* test_array = new int[TEST_SIZE];
  for (int i = 0; i < TEST_SIZE; i++) {
    test_array[i] = i;
  }

  for (int i = 0; i < TEST_SIZE / 2; i++) {
    utils::array_utils<int>::swap(test_array, i, TEST_SIZE - 1 - i);
  }

  for (int i = 0; i < TEST_SIZE; i++) {
    EXPECT_EQ(TEST_SIZE - 1 - i, test_array[i]);
  }

  delete test_array;
}

TEST(ArrayUtilsTest, Copy) {
  int TEST_SIZE = 100;

  int* test_array = new int[TEST_SIZE];
  for (int i = 0; i < TEST_SIZE; i++) {
    test_array[i] = i;
  }

  // elements with values 9 through 49
  auto copy = utils::array_utils<int>::copy(test_array, 10, 50);

  for (int i = 10; i < 50; i++) {
    EXPECT_EQ(i, copy[i - 10]);
  }

  delete test_array;
  delete copy;
}
