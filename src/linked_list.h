//
// Created by ianrobrien on 2/28/17.
//

#ifndef COMPUTING_FUNDAMENTALS_LINKED_LIST_H
#define COMPUTING_FUNDAMENTALS_LINKED_LIST_H

#include <stdexcept>
#include "list_node.h"

template <class T>
class LinkedList {
 private:
  ListNode<T> *head_;
  int size_;
  void RangeCheck(int index);
  void RangeCheckForAdd(int index);
  void DeleteRecursive(ListNode<T> *node);

 public:
  LinkedList<T>();
  ~LinkedList<T>();
  int size() const;
  bool Contains(T element);
  T Get(int index);
  int IndexOf(T element);
  bool IsEmpty();
  int LastIndexOf(T element);
  bool Add(T element);
  bool Add(int index, T element);
  void Clear();
  bool Remove(T element);
  bool RemoveAt(int index, T element);
  T Set(int index, T element);
};

template <class T>
void LinkedList<T>::RangeCheck(int index) {
  if (index < 0 || index >= this->size_) {
    throw std::invalid_argument("Index: " + std::to_string(index) +
                                ", Size: " + std::to_string(this->size_));
  }
}

template <class T>
void LinkedList<T>::RangeCheckForAdd(int index) {
  if (index < 0 || index > this->size_) {
    throw std::invalid_argument("Index: " + std::to_string(index) +
                                ", Size: " + std::to_string(this->size_));
  }
}

template <class T>
LinkedList<T>::LinkedList() {
  this->size_ = 0;
  this->head_ = nullptr;
}

template <class T>
LinkedList<T>::~LinkedList() {
  this->Clear();
}

template <class T>
int LinkedList<T>::size() const {
  return this->size_;
}

template <class T>
T LinkedList<T>::Get(int index) {
  this->RangeCheck(index);
  ListNode<T> *node = this->head_;
  for (int i = 0; i < index; i++) {
    node = node->next();
  }
  return node->value();
}

template <class T>
bool LinkedList<T>::Contains(T element) {
  return true;
};

template <class T>
int LinkedList<T>::IndexOf(T element) {
  return -1;
};

template <class T>
bool LinkedList<T>::IsEmpty() {
  return this->size_ == 0;
}

template <class T>
int LinkedList<T>::LastIndexOf(T element) {
  return -1;
};

template <class T>
bool LinkedList<T>::Add(T element) {
  return this->Add(this->size_, element);
}

template <class T>
bool LinkedList<T>::Add(int index, T element) {
  this->RangeCheckForAdd(index);
  auto currentSize = this->size_;
  auto adding = new ListNode<T>(element);

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
void LinkedList<T>::Clear() {
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
bool LinkedList<T>::Remove(T element) {
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
bool LinkedList<T>::RemoveAt(int index, T element) {
  return false;
}

#endif  // COMPUTING_FUNDAMENTALS_LINKED_LIST_H
