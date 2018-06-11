//
// Created by ianrobrien on 2/28/17.
//

#ifndef COMPUTING_FUNDAMENTALS_LIST_NODE_H
#define COMPUTING_FUNDAMENTALS_LIST_NODE_H

namespace iro {
template <class T>
class list_node {
 private:
  T value_;
  list_node<T> *next_;

 public:
  list_node<T>(T value);
  list_node<T> *next();
  void setNext(list_node<T> *next);
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
