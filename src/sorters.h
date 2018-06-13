//
// Created by ianrobrien on 6/11/17.
//

#include "src/array_utils.h"

#ifndef COMPUTING_FUNDAMENTALS_CPP_SORTERS_H
#define COMPUTING_FUNDAMENTALS_CPP_SORTERS_H

using namespace iro::utils;

namespace iro {
namespace algorithms {

/**
 * @brief Implementation of various sorting algorithms
 */
template <class T>
class sorters {
 private:
  static void merge_sort_sort(T values[], int left, int right);
  static void merge_sort_merge(T values[], int left, int middle, int right);

 public:
  /**
   * @brief In-place insertion sort
   * @param values[] an array of type T to sort
   * @param size The size oof the array
   */
  static void insertion_sort(T values[], int size);
  /**
   * @brief In-place bubble sort
   * @param values[] an array of type T to sort
   * @param size The size oof the array
   */
  static void bubble_sort(T values[], int size);
  /**
   * @brief In-place selection sort
   * @param values[] an array of type T to sort
   * @param size The size oof the array
   */
  static void selection_sort(T values[], int size);
  /**
   * @param values[] an array of type T to sort
   * @param size The size oof the array
   */
  static void shell_sort(T values[], int size);
  /**
   * @param values[] an array of type T to sort
   * @param size The size oof the array
   */
  static void quick_sort(T values[], int size);
  /**
   * @param values[] an array of type T to sort
   * @param size The size oof the array
   */
  static void merge_sort(T values[], int size);
  /**
   * @param values[] an array of type T to sort
   * @param size The size oof the array
   */
  static void heap_sort(T values[], int size);
};

template <class T>
void sorters<T>::insertion_sort(T values[], int size) {
  int i = 1;
  while (i < size) {
    int j = i;
    while (j > 0 && values[j - 1] > values[j]) {
      array_utils<T>::swap(values, j, j - 1);
      j--;
    }
    i++;
  }
}

template <class T>
void sorters<T>::bubble_sort(T values[], int size) {
  for (int i = 0; i < size; i++) {
    bool swapped = false;
    for (int j = 1; j < size - i; j++) {
      if (values[j - 1] > values[j]) {
        array_utils<T>::swap(values, j, j - 1);
        swapped = true;
      }
    }
    if (!swapped) {
      return;
    }
  }
}

template <class T>
void sorters<T>::selection_sort(T values[], int size) {
  for (int i = 0; i < size; i++) {
    int index_smallest = i;
    for (int j = i; j < size; j++) {
      if (values[j] <= values[index_smallest]) {
        index_smallest = j;
      }
    }
    array_utils<T>::swap(values, i, index_smallest);
  }
}

template <class T>
void sorters<T>::shell_sort(T values[], int size) {}

template <class T>
void sorters<T>::quick_sort(T values[], int size) {}

template <class T>
void sorters<T>::merge_sort(T values[], int size) {
  merge_sort_sort(values, 0, size - 1);
}

template <class T>
void sorters<T>::merge_sort_sort(T values[], int start, int end) {
  if (start < end) {
    int middle = (start + end) / 2;
    merge_sort_sort(values, start, middle);
    merge_sort_sort(values, middle + 1, end);
    merge_sort_merge(values, start, middle, end);
  }
}

template <class T>
void sorters<T>::merge_sort_merge(T values[], int start, int middle, int end) {
  auto left = array_utils<T>::copy(values, start, middle);
  auto right = array_utils<T>::copy(values, middle + 1, end);

  int number_left = middle - start + 1;
  int number_right = end - middle;

  int i = 0;
  int j = 0;
  int k = start;
  while (i < number_left && j < number_right) {
    if (left[i] <= right[j]) {
      values[k] = left[i];
      i++;
    } else {
      values[k] = right[j];
      j++;
    }
    k++;
  }

  while (i < number_left) {
    values[k] = left[i];
    i++;
    k++;
  }
  while (j < number_right) {
    values[k] = right[j];
    j++;
    k++;
  }
}

template <class T>
void sorters<T>::heap_sort(T values[], int size) {}
}  // namespace algorithms
}  // namespace iro
#endif  // COMPUTING_FUNDAMENTALS_CPP_SORTERS_H
