//
// Created by ianrobrien on 2/28/17.
//

#ifndef SORTERS_H
#define SORTERS_H

namespace iro {
namespace algorithms {
template <class T>
class Sorters {
 public:
  static void InsertionSort(T values[], int size);
  static void BubbleSort(T values[], int size);
  static void ExchangeSort(T values[], int size);
  static void SelectionSort(T values[], int size);
  static void ShellSort(T values[], int size);
  static void QuickSort(T values[], int size);
  static void MergeSort(T values[], int size);
};

template <class T>
void Sorters<T>::InsertionSort(T values[], int size) {}

template <class T>
void Sorters<T>::BubbleSort(T values[], int size) {
  for (int i = 0; i < size; i++) {
    bool swapped = false;
    for (int j = 1; j < size - i; j++) {      
      if (values[j - 1] > values[j]) {
        int temp = values[j - 1];
        values[j - 1] = values[j];
        values[j] = temp;
        swapped = true;
      }
    }
    if (!swapped) {
      return;
    }
  }
}

template <class T>
void Sorters<T>::ExchangeSort(T values[], int size) {}

template <class T>
void Sorters<T>::SelectionSort(T values[], int size) {
  auto result = new T[size]();
  for (int i = 0; i < size; i++) {
    // Get smallest element
    int smallestIndex = i;
    for (int j = i; j < size; j++) {
      if (values[j] <= values[smallestIndex]) {
        smallestIndex = j;
      }
    }
    // Swap the next element with the smallest element
    auto temp = values[i];
    auto smallest = values[smallestIndex];
    values[i] = values[smallestIndex];
    values[smallestIndex] = temp;
  }
}

template <class T>
void Sorters<T>::ShellSort(T values[], int size) {}

template <class T>
void Sorters<T>::QuickSort(T values[], int size) {}

template <class T>
void Sorters<T>::MergeSort(T values[], int size) {}
}  // namespace algorithms
}  // namespace iro
#endif  // SORTERS_H
