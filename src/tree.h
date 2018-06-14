#ifndef COMPUTING_FUNDAMENTALS_CPP_TREE_H
#define COMPUTING_FUNDAMENTALS_CPP_TREE_H

#include "src/linked_list.h"

using namespace iro;

namespace iro {
namespace utils {

template <class T>
class tree {
 public:
  /**
   * @param element the element to add to the %tree
   */
  virtual void add(T element) = 0;
  /**
   * @param element the element to check the tree
   * @return whether or not the element is in the tree
   */
  virtual bool contains(T element) = 0;
  /**
   * @return the number of elements in the tree
   */
  virtual int size() = 0;
  /**
   * @return a list of the items in post-order sequence
   */
  virtual utils::linked_list<T>* post_order_traversal() = 0;
  /**
   * @return a list of the items in pre-order sequence
   */
  virtual utils::linked_list<T>* pre_order_traversal() = 0;
  /**
   * @return a list of the items in in-order sequence
   */
  virtual utils::linked_list<T>* in_order_traversal() = 0;
};

}  // namespace util
}  // namespace iro

#endif