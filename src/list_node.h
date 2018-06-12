//
// Created by ianrobrien on 2/28/17.
//

#ifndef COMPUTING_FUNDAMENTALS_LIST_NODE_H
#define COMPUTING_FUNDAMENTALS_LIST_NODE_H

namespace iro {

/**
 * @brief A node in a list collection that contains an element of type T
 * and a pointer to the next node
 */
template <class T>
class list_node {
 private:
  T value_;
  list_node<T> *next_;

 public:
  /**
   * @brief Parameterized constructor
   * @param value T
   * 
   * @details Creates an instance of %list_node and sets the value of the node
   * to the specified value
   */
  list_node<T>(T value);
  /**
   * @brief Returns the next node in the %linked_list
   * @return A pointer to the next %list_node
   */
  list_node<T> *next();
  /**
   * @brief Sets the next %list_node in the %linked_list
   * @param next a pointer to a %list_node
   * */
  void setNext(list_node<T> *next);
  /**
   * @brief Gets the value of the node
   * @return the value of the node
   */
  T value();
};

template <class T>
list_node<T>::list_node(T value) {
  this->value_ = value;
  this->next_ = nullptr;
}

template <class T>
void list_node<T>::setNext(list_node<T> *next) {
  this->next_ = next;
}

template <class T>
list_node<T> *list_node<T>::next() {
  return this->next_;
}

template <class T>
T list_node<T>::value() {
  return this->value_;
}
}  // namespace iro

#endif  // COMPUTING_FUNDAMENTALS_LIST_NODE_H
