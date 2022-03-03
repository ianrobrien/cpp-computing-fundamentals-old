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
#ifndef COMPUTING_FUNDAMENTALS_CPP_BINARY_SEARCH_TREE_H
#define COMPUTING_FUNDAMENTALS_CPP_BINARY_SEARCH_TREE_H

#include "src/linked_list.h"
#include "src/tree.h"

namespace iro {
namespace utils {

template <class T>
class binary_search_tree : public tree<T> {
 public:
  /**
   * @brief constructs a default instance of a binary search tree
   */
  binary_search_tree();
  /**
   * @param element the element to add to the %binary_search_tree
   */
  void add(T element);
  /**
   * @param element the element to check the tree
   * @return whether or not the element is in the tree
   */
  bool contains(T value);
  /**
   * @return the number of elemements in the tree
   */
  int size();
  /**
   * @return a list of the items in post-order sequence
   */
  utils::linked_list<T>* post_order_traversal();
  /**
   * @return a list of the items in pre-order sequence
   */
  utils::linked_list<T>* pre_order_traversal();
  /**
   * @return a list of the items in in-order sequence
   */
  utils::linked_list<T>* in_order_traversal();

 protected:
  struct node {
    explicit node(T value);
    T value;
    node* left = nullptr;
    node* right = nullptr;
    virtual bool add(T value);
  };
  node* root_ = nullptr;
  int size_ = 0;
  bool contains(T value, node* root);
  utils::linked_list<T>* post_order_traversal(node* root,
                                             utils::linked_list<T>* ll);
  utils::linked_list<T>* pre_order_traversal(node* root,
                                            utils::linked_list<T>* ll);
  utils::linked_list<T>* in_order_traversal(node* root,
                                           utils::linked_list<T>* ll);
};

template <class T>
binary_search_tree<T>::node::node(T value) {
  this->value = value;
    this->left = nullptr;
  this->right = nullptr;
}

template <class T>
bool binary_search_tree<T>::node::add(T value) {
  if (value < this->value) {
    if (this->left == nullptr) {
      this->left = new node(value);
      return true;
    } else {
      return this->left->add(value);
    }
  } else {
    if (this->right == nullptr) {
      this->right = new node(value);
      return true;
    } else {
      return this->right->add(value);
    }
  }
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
}

template <class T>
bool binary_search_tree<T>::contains(T value) {
  return this->contains(value, this->root_);
}

template <class T>
bool binary_search_tree<T>::contains(T value, node* root) {
  if (root == nullptr) {
    return false;
  } else {
    if (value == root->value) {
      return true;
    } else if (value < root->value) {
      return this->contains(value, root->left);
    } else {
      return this->contains(value, root->right);
    }
  }
}

template <class T>
int binary_search_tree<T>::size() {
  return this->size_;
}

template <class T>
utils::linked_list<T>* binary_search_tree<T>::post_order_traversal() {
  auto ll = new utils::linked_list<T>();
  return this->post_order_traversal(this->root_, ll);
}

template <class T>
utils::linked_list<T>* binary_search_tree<T>::post_order_traversal(
    node* root, utils::linked_list<T>* ll) {
  if (root != nullptr) {
    // left, right, center
    this->post_order_traversal(root->left, ll);
    this->post_order_traversal(root->right, ll);
    ll->add(root->value);
  }
  return ll;
}

template <class T>
utils::linked_list<T>* binary_search_tree<T>::pre_order_traversal() {
  auto ll = new utils::linked_list<T>();
  return this->pre_order_traversal(this->root_, ll);
}

template <class T>
utils::linked_list<T>* binary_search_tree<T>::pre_order_traversal(
    node* root, utils::linked_list<T>* ll) {
  if (root != nullptr) {
    // center, left, right
    ll->add(root->value);
    this->pre_order_traversal(root->left, ll);
    this->pre_order_traversal(root->right, ll);
  }
  return ll;
}

template <class T>
utils::linked_list<T>* binary_search_tree<T>::in_order_traversal() {
  auto ll = new utils::linked_list<T>();
  return this->in_order_traversal(this->root_, ll);
}

template <class T>
utils::linked_list<T>* binary_search_tree<T>::in_order_traversal(
    node* root, utils::linked_list<T>* ll) {
  if (root != nullptr) {
    // left, center, right
    this->in_order_traversal(root->left, ll);
    ll->add(root->value);
    this->in_order_traversal(root->right, ll);
  }
  return ll;
}

}  // namespace util
}  // namespace iro

#endif