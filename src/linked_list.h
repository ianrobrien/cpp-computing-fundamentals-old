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
#ifndef COMPUTING_FUNDAMENTALS_LINKED_LIST_H
#define COMPUTING_FUNDAMENTALS_LINKED_LIST_H

#include <stdexcept>
#include "src/list.h"

namespace iro {
namespace utils {
/** @brief A node in a list collection that contains an element of type T
 *
 * This class provides a node in a LinkedList of type T*/
template <class T>
class linked_list : public list<T> {
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
  T set(int index, T element);

  T *to_array();

 private:
  struct list_node {
    list_node(T element);
    T value;
    list_node *next = nullptr;
  };
  list_node *head_;
  void range_check(int index);
  void range_check_for_add(int index);
};

template <class T>
linked_list<T>::list_node::list_node(T element) {
  this->next = nullptr;
  this->value = element;
}

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
T linked_list<T>::get(int index) {
  this->range_check(index);
  list_node *node = this->head_;
  for (int i = 0; i < index; i++) {
    node = node->next;
  }
  return node->value;
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
      if (current->value == element) {
        return index;
      }
      current = current->next;
      index++;
    }
  }
  return -1;
};

template <class T>
int linked_list<T>::last_index_of(T element) {
  if (!this->head_) {
    return -1;
  }

  int lastIndex = -1;
  int index = 0;

  auto current = this->head_;
  while (current) {
    if (current->value == element) {
      lastIndex = index;
    }
    current = current->next;
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
  auto adding = new list_node(element);

  if (index == 0) {
    if (head_) {
      adding->next = head_;
    }
    this->head_ = adding;
  } else {
    auto next = this->head_;
    for (int i = 0; i < index - 1; i++) {
      next = next->next;
    }
    adding->next = (next->next);
    next->next = (adding);
  }

  return ++this->size_ == currentSize + 1;
}

template <class T>
void linked_list<T>::clear() {
  auto current = this->head_;
  while (current != nullptr) {
    auto next = current->next;
    delete current;
    current = next;
  }
  this->size_ = 0;
  this->head_ = nullptr;
}

template <class T>
bool linked_list<T>::remove(T element) {
  if (this->head_->value == element) {
    this->head_->next = (this->head_->next);
    this->size_--;
    return true;
  } else {
    auto current = this->head_->next;
    auto previous = this->head_;
    while (current) {
      if (current->value == element) {
        previous->next = (current->next);
        this->size_--;
        return true;
      }
      previous = current;
      current = current->next;
    }
  }
  return false;
}

template <class T>
bool linked_list<T>::remove_at(int index) {
  this->range_check(index);
  int beforeSize = this->size_;
  if (index == 0) {
    this->head_ = this->head_->next;
    this->size_--;
  } else {
    auto current = this->head_;
    for (int i = 0; i < index - 1; i++) {
      current = current->next;
    }
    current->next = (current->next->next);
    this->size_--;
  }
  return this->size_ == beforeSize - 1;
}

template <class T>
T linked_list<T>::set(int index, T element) {
  range_check(index);
  auto current = this->head_;
  for (int i = 0; i < index; i++) {
    current = current->next;
  }
  T previous = current->value;
  current->value = element;
  return previous;
}

template <class T>
T *linked_list<T>::to_array() {
  auto result = new T[this->size_];
  if (this->head_ != nullptr) {
    int i = 0;
    auto next = this->head_;
    while (next != nullptr) {
      result[i++] = next->value;
      next = next->next;
    }
  }
  return result;
}

}  // namespace utils
}  // namespace iro

#endif  // COMPUTING_FUNDAMENTALS_LINKED_LIST_H
