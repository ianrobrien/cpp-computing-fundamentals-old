//
// Created by ianrobrien on 2/28/17.
//

#ifndef SORTERS_H
#define SORTERS_H

namespace iro {
  namespace algorithms{
template <class T>
class Sorters {
 public:
  static void BubbleSort(T *values[]);
  static void ExchangeSort();
  static void SelectionSort();
  static void ShellSort();
  static void QuickSort();
  static void MergeSort();
};

template <class T>
void Sorters<T>::BubbleSort(T *values[]) {
  for (int i = 0; i < values.length; i++) {
  }
}
}  // namespace iro
}
#endif  // SORTERS_H
