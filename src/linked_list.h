//
// Created by ianrobrien on 2/28/17.
//

#ifndef COMPUTING_FUNDAMENTALS_LINKED_LIST_H
#define COMPUTING_FUNDAMENTALS_LINKED_LIST_H

#include <stdexcept>
#include "list_node.h"

namespace iro {
template <class T>
class linked_list {
 private:
  list_node<T> *head_;
  int size_;
  void range_check(int index);
  void range_check_for_add(int index);

 public:
  linked_list<T>();
  ~linked_list<T>();
  int size() const;
  bool contains(T element);
  T get(int index);
  int index_of(T element);
  bool empty();
  int last_index_of(T element);
  bool add(T element);
  bool add(int index, T element);
  void clear();
  bool remove(T element);
  bool remove_at(int index);
  T Set(int index, T element);
};

template <class T>
void linked_list<T>::range_check(int index) {
  if (index < 0 || index >= this->size_) {
    throw std::invalid_argument("Index: " + std::to_string(index) +
                                ", Size: " + std::to_string(this->size_));
  }
}

template <class T>
void linked_list<T>::range_check_for_add(int index) {
  if (index < 0 || index > this->size_) {
    throw std::invalid_argument("Index: " + std::to_string(index) +
                                ", Size: " + std::to_string(this->size_));
  }
}

template <class T>
linked_list<T>::linked_list() {
  this->size_ = 0;
  this->head_ = nullptr;
}

template <class T>
linked_list<T>::~linked_list() {
  this->clear();
}

template <class T>
int linked_list<T>::size() const {
  return this->size_;
}

template <class T>
T linked_list<T>::get(int index) {
  this->range_check(index);
  list_node<T> *node = this->head_;
  for (int i = 0; i < index; i++) {
    node = node->next();
  }
  return node->value();
}

template <class T>
bool linked_list<T>::contains(T element) {
  return this->index_of(element) >= 0;
};

template <class T>
int linked_list<T>::index_of(T element) {
  if (!this->head_) {
    return -1;
  } else {
    auto current = this->head_;
    int index = 0;
    while (current) {
      if (current->value() == element) {
        return index;
      }
      current = current->next();
      index++;
    }
  }
  return -1;
};

template <class T>
bool linked_list<T>::empty() {
  return this->size_ == 0;
}

template <class T>
int linked_list<T>::last_index_of(T element) {
  if (!this->head_) {
    return -1;
  }

  int lastIndex = -1;
  int index = 0;

  auto current = this->head_;
  while (current) {
    if (current->value() == element) {
      lastIndex = index;
    }
    current = current->next();
    index++;
  }

  return lastIndex;
};

template <class T>
bool linked_list<T>::add(T element) {
  return this->add(this->size_, element);
}

template <class T>
bool linked_list<T>::add(int index, T element) {
  this->range_check_for_add(index);
  auto currentSize = this->size_;
  auto adding = new list_node<T>(element);

  if (index == 0) {
    if (head_) {
      adding->setNext(head_);
    }
    this->head_ = adding;
  } else {
    auto next = this->head_;
    for (int i = 0; i < index - 1; i++) {
      next = next->next();
    }
    adding->setNext(next->next());
    next->setNext(adding);
  }

  return ++this->size_ == currentSize + 1;
}

template <class T>
void linked_list<T>::clear() {
  auto current = this->head_;
  while (current != nullptr) {
    auto next = current->next();
    delete current;
    current = next;
    this->size_--;
  }
  this->head_ = nullptr;
}

template <class T>
bool linked_list<T>::remove(T element) {
  if (this->head_->value() == element) {
    this->head_->setNext(this->head_->next());
    this->size_--;
    return true;
  } else {
    auto current = this->head_->next();
    auto previous = this->head_;
    while (current) {
      if (current->value() == element) {
        previous->setNext(current->next());
        this->size_--;
        return true;
      }
      previous = current;
      current = current->next();
    }
  }
  return false;
}

template <class T>
bool linked_list<T>::remove_at(int index) {
  this->range_check(index);
  int beforeSize = this->size_;
  if (index == 0) {
    this->head_ = this->head_->next();
    this->size_--;
  } else {
    auto current = this->head_;
    for (int i = 0; i < index - 1; i++) {
      current = current->next();
    }
    current->setNext(current->next()->next());
    this->size_--;
  }
  return this->size_ = beforeSize - 1;
}
}  // namespace iro

#endif  // COMPUTING_FUNDAMENTALS_LINKED_LIST_H
