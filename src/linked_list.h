//
// Created by ianrobrien on 2/28/17.
//

#ifndef COMPUTING_FUNDAMENTALS_LINKED_LIST_H
#define COMPUTING_FUNDAMENTALS_LINKED_LIST_H

#include <stdexcept>
#include "list_node.h"

namespace iro {
/** @brief A node in a list collection that contains an element of type T
 *
 * This class provides a node in a LinkedList of type T*/
template <class T>
class linked_list {
 private:
  list_node<T> *head_;
  int size_;
  void range_check(int index);
  void range_check_for_add(int index);

 public:
  /**
   * @brief Constructs an instance of %linked_ist
   * */
  linked_list<T>();
  /**
   * @brief Default destructor
   * @details removes all nodes and frees all associated memory
   */
  ~linked_list<T>();
  /**
   * @brief The number of nodes in the list
   * @return The number of nodes in the list
   */
  int size() const;
  /**
   * @brief Searches the list to see whether or not it contains the specified
   * element
   * @param element The element for which the search is executed
   * @return true if the element is in the list or false otherwise
   */
  bool contains(T element);
  /**
   * @brief Gets the element at the specified index
   * @param index The index of the element to retrieve, starting at 0
   */
  T get(int index);
  /**
   * @brief Gets the index of the specified element
   * @param element The element whose index is desired
   * @return The element's index if it is in the list, -1 if it is not
   */
  int index_of(T element);
  /**
   * @return Whether or not the list has any elements
   */
  bool empty();
  /**
   * @brief The index of the specified element furthest from the head
   * @param element The element whose last index is desired
   * @return The element's index if it is in the list, -1 if it is not
   *
   * If the element appears in the list more than once, then the index of the
   * element furthest from the head (nearest the tail) is returned
   */
  int last_index_of(T element);
  /**
   * @brief Adds the specified element to the list
   * @param element The element to add to the list
   * @return Whether or not the element has been successfully added
   */
  bool add(T element);
  /**
   * @brief Adds the specified element to the list at the specified index
   * @param index Specifies where the element should be added into the list
   * @param element The element to add to the list
   * @return Whether or not the element has been successfully added
   *
   * Adds the specified element at the specified index. If the index is out of
   * range then an exception is thrown. All elements after the specified index
   * will be appended to the added element
   */
  bool add(int index, T element);
  /**
   * @brief Removes all elements from the list
   */
  void clear();
  /**
   * @brief Removes the specified element from the list
   * @param element The element to remove from the list
   * @return True if the element has been removed from the list, false otherwise
   *
   * If the element is removed, then the indexes of all elements after the
   * removed element are decremented by 1
   */
  bool remove(T element);
  /**
   * @brief Removes the element at the specified index from the list
   * @param element The index of the element to remove from the list
   * @return True if the element has been removed from the list, false otherwise
   *
   * If the element is removed, then the indexes of all elements after the
   * removed element are decremented by 1
   */
  bool remove_at(int index);
  /**
   * @brief Sets the element at the specified index to the specified value
   * @param index The index of the element to set
   * @param element The element to set at the specified index
   * @return The element that was replaced at the specified index
   */
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
