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

#ifndef COMPUTING_FUNDAMENTALS_CPP_MAX_HEAP_H
#define COMPUTING_FUNDAMENTALS_CPP_MAX_HEAP_H

#include "src/array_utils.h"
#include "src/binary_search_tree.h"
#include "src/heap.h"

namespace iro {
namespace utils {

template <class T>
class max_heap : public heap<T> {
 public:
  max_heap();
  ~max_heap();
  T peek();
  T pop();
  void push(T element);
  void remove();
  void replace();

  void heapify();
  void merge(heap<T>* other);
  void meld(heap<T>* other);

 protected:
  void update_key();
  void sift();

 private:
  T* data_ = nullptr;
  int next_ = 0;
  int DEFAULT_CAPACITY = 256;
  int capacity_ = 0;
};

template <class T>
max_heap<T>::max_heap() {
  this->data_ = new T[DEFAULT_CAPACITY];
  this->capacity_ = DEFAULT_CAPACITY;
}

template <class T>
max_heap<T>::~max_heap() {}

template <class T>
T max_heap<T>::peek() {
  return this->data_[0];
}

template <class T>
T max_heap<T>::pop() {}

template <class T>
void max_heap<T>::push(T element) {
  if (this->next_ == this->capacity_) {
    auto temp = this->data_;
    this->data_ = new T[this->capacity_ * 2];
    array_utils<T>::copy(temp, this->data_, 0, this->capacity_ - 1);
    delete temp;
    this->capacity_ = this->capacity_ * 2;
  }
  this->data_[this->next_] = element;
  auto parent_index = (this->next_ - 1) / 2;
  auto current_index = this->next_;
  while (element > this->data_[parent_index]) {
    array_utils<T>::swap(this->data_, current_index, parent_index);
    current_index = parent_index;
    parent_index = (parent_index - 1) / 2;
  }
  this->size_++;
  this->next_++;
}

template <class T>
void max_heap<T>::remove() {}

template <class T>
void max_heap<T>::replace() {}

template <class T>
void max_heap<T>::heapify() {}

template <class T>
void max_heap<T>::merge(heap<T>* other) {}

template <class T>
void max_heap<T>::meld(heap<T>* other) {}

template <class T>
void max_heap<T>::update_key() {}

template <class T>
void max_heap<T>::sift() {}

}  // namespace utils
}  // namespace iro

#endif