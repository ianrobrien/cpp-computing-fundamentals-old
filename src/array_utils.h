//
// Created by ianrobrien on 6/11/17.
//

#ifndef COMPUTING_FUNDAMENTALS_CPP_ARRAY_UTILS_H
#define COMPUTING_FUNDAMENTALS_CPP_ARRAY_UTILS_H

namespace iro {
namespace utils {

/**
 * @brief Implementation of various sorting algorithms
 */
template <class T>
class array_utils {
 public:
  /**
   * @brief swaps the elements at the specified indicies of the specified array
   * @param values[] the array of which to swap elements
   * @param index_a the index of the swapping element
   * @param index_b the index of the swapee element
   */
  static void swap(T values[], int index_a, int index_b);
  /**
   * @param values[] the source array
   * @param start_index the index of the first element to copy from the source
   * array
   * @param end_index the index of the last element to copy from the source
   * array
   * @return a pointer to the copied array
   */
  static T* copy(T values[], int start_index, int end_index);
};

template <class T>
void array_utils<T>::swap(T values[], int index_a, int index_b) {
  auto a = values[index_a];
  values[index_a] = values[index_b];
  values[index_b] = a;
}

template <class T>
T* array_utils<T>::copy(T values[], int start_index, int end_index) {
  auto result = new T[end_index - start_index + 1];
  auto result_index = 0;
  for (int i = 0; i <= end_index; i++) {
    if (i >= start_index) {
      result[result_index] = values[i];
      result_index++;
    }
  }
  return result;
}

}  // namespace utils
}  // namespace iro

#endif
