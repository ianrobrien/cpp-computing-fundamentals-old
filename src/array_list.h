#ifndef COMPUTING_FUNDAMENTALS_CPP_ARRAY_LIST_H
#define COMPUTING_FUNDAMENTALS_CPP_ARRAY_LIST_H

#include <stdexcept>
#include "src/array_utils.h"
#include "src/list.h"

namespace iro {
namespace utils {
template <class T>
class array_list : public list<T> {
 public:
  array_list();
  bool contains(T element);
  T get(int index);
  int index_of(T element);
  int last_index_of(T element);
  bool add(T element);
  bool add(int index, T element);
  void clear();
  bool remove(T element);
  bool remove_at(int index);
  T set(int index, T element);

 private:
  T* data_;
  int DEFAULT_CAPACITY = 1024;
  int capacity_;
  int next_ = 0;
  void range_check(int index);
  void range_check_for_add(int index);
};

template <class T>
array_list<T>::array_list() {
  this->capacity_ = DEFAULT_CAPACITY;
  this->data_ = new T[this->capacity_];
}

template <class T>
bool array_list<T>::contains(T element) {
  for (int i = 0; i < this->size_; i++) {
    if (data_[i] == element) {
      return true;
    }
  }
  return false;
}

template <class T>
T array_list<T>::get(int index) {
  return data_[index];
}

template <class T>
int array_list<T>::index_of(T element) {
  for (int i = 0; i < this->size_; i++) {
    if (this->data_[i] == element) {
      return i;
    }
  }
  return -1;
}

template <class T>
int array_list<T>::last_index_of(T element) {
  int last_index = -1;
  for (int i = 0; i < this->size_; i++) {
    if (this->data_[i] == element) {
      last_index = i;
    }
  }
  return last_index;
}

template <class T>
bool array_list<T>::add(T element) {
  this->add(this->next_, element);
}

template <class T>
bool array_list<T>::add(int index, T element) {
  range_check_for_add(index);
  if (this->size_ == this->capacity_) {
    auto temp = this->data_;
    auto capacity = this->capacity_ * 2;
    this->data_ = new T[capacity];
    array_utils<T>::copy(temp, this->data_, 0, this->size_ - 1);
    delete temp;
    this->capacity_ = capacity;
  }
  if (index < this->size_) {
    array_utils<T>::shift_right(this->data_, index, this->size_ - 1);
  }
  this->data_[index] = element;
  this->size_++;
  this->next_++;
}

template <class T>
void array_list<T>::clear() {
  delete this->data_;
  this->data_ = new T[DEFAULT_CAPACITY];
  this->size_ = 0;
  this->next_ = 0;
}

template <class T>
bool array_list<T>::remove(T element) {
  this->remove_at(this->index_of(element));
}

template <class T>
bool array_list<T>::remove_at(int index) {
  range_check(index);
  array_utils<T>::shift_left(this->data_, index + 1, this->size_ - 1);
  this->size_--;
}

template <class T>
T array_list<T>::set(int index, T element) {
  range_check(index);
  T temp = this->data_[index];
  this->data_[index] = element;
  return temp;
}

template <class T>
void array_list<T>::range_check(int index) {
  if (index < 0 || index >= this->size_) {
    throw std::invalid_argument("Index: " + std::to_string(index) +
                                ", Size: " + std::to_string(this->size_));
  }
}

template <class T>
void array_list<T>::range_check_for_add(int index) {
  if (index < 0 || index > this->size_) {
    throw std::invalid_argument("Index: " + std::to_string(index) +
                                ", Size: " + std::to_string(this->size_));
  }
}

}  // namespace utils
}  // namespace iro
#endif