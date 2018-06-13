#ifndef COMPUTING_FUNDAMENTALS_CPP_BINARY_SEARCH_TREE_H
#define COMPUTING_FUNDAMENTALS_CPP_BINARY_SEARCH_TREE_H

namespace iro {
namespace util {

template <class T>
class binary_search_tree {
 private:
  struct node {
    node(T value);
    T value;
    node* left;
    node* right;
    bool add(T element);
  };
  int size_ = 0;
  node* root_ = nullptr;

 public:
  /**
   * @brief constructs a default instance of a binary search tree
   */
  binary_search_tree();
  /**
   * @param elemement the element to add to the %binary_search_tree
   */
  void add(T element);
  /**
   * @return the number of elemements in the tree
   */
  int size();
};

template <class T>
binary_search_tree<T>::node::node(T value) {
  this->value = value;
}

template <class T>
bool binary_search_tree<T>::node::add(T value) {
  if (value < this->value) {
    if (this->left == nullptr) {
      this->left = new node(value);
      return true;
    } else {
      this->left->add(value);
    }
  } else {
    if (this->right == nullptr) {
      this->right = new node(value);
      return true;
    } else {
      this->right->add(value);
    }
  }
  return false;
}

template <class T>
binary_search_tree<T>::binary_search_tree() {
  this->size_ = 0;
  this->root_ = nullptr;
}

template <class T>
void binary_search_tree<T>::add(T element) {
  if (this->root_ == nullptr) {
    this->root_ = new node(element);
    this->size_++;
  } else if (this->root_->add(element)) {
    this->size_++;
  }
}  // namespace util

template <class T>
int binary_search_tree<T>::size() {
  return this->size_;
}

}  // namespace util
}  // namespace iro

#endif