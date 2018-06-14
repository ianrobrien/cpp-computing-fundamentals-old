//
// Created by ianrobrien on 2/28/17.
//

#ifndef COMPUTING_FUNDAMENTALS_LIST_H
#define COMPUTING_FUNDAMENTALS_LIST_H

namespace iro {
namespace utils {
template <class T>
class list {
 public:
  /**
   * @brief The number of nodes in the list
   * @return The number of nodes in the list
   */
  int size() const;
  /**
   * @brief Searches the list to see whether or not it contains the
   * specified element
   * @param element The element for which the search is executed
   * @return true if the element is in the list or false otherwise
   */
  virtual bool contains(T element) = 0;
  /**
   * @brief Gets the element at the specified index
   * @param index The index of the element to retrieve, starting at 0
   */
  virtual T get(int index) = 0;
  /**
   * @brief Gets the index of the specified element
   * @param element The element whose index is desired
   * @return The element's index if it is in the list, -1 if it is not
   */
  virtual int index_of(T element) = 0;
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
  virtual int last_index_of(T element) = 0;
  /**
   * @brief Adds the specified element to the list
   * @param element The element to add to the list
   * @return Whether or not the element has been successfully added
   */
  virtual bool add(T element) = 0;
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
  virtual bool add(int index, T element) = 0;
  /**
   * @brief Removes all elements from the list
   */
  virtual void clear() = 0;
  /**
   * @brief Removes the specified element from the list
   * @param element The element to remove from the list
   * @return True if the element has been removed from the list, false otherwise
   *
   * If the element is removed, then the indexes of all elements after the
   * removed element are decremented by 1
   */
  virtual bool remove(T element) = 0;
  /**
   * @brief Removes the element at the specified index from the list
   * @param element The index of the element to remove from the list
   * @return True if the element has been removed from the list, false otherwise
   *
   * If the element is removed, then the indexes of all elements after the
   * removed element are decremented by 1
   */
  virtual bool remove_at(int index) = 0;
  /**
   * @brief Sets the element at the specified index to the specified value
   * @param index The index of the element to set
   * @param element The element to set at the specified index
   * @return The element that was replaced at the specified index
   */
  virtual T set(int index, T element) = 0;

  virtual T* to_array() = 0;

 protected:
  int size_ = 0;
};

template <class T>
int list<T>::size() const {
  return this->size_;
}

template <class T>
bool list<T>::empty() {
  return this->size_ == 0;
}

}  // namespace utils
}  // namespace iro

#endif  // COMPUTING_FUNDAMENTALS_LINKED_LIST_H
