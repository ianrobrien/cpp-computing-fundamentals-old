#ifndef COMPUTING_FUNDAMENTALS_CPP_HEAP_H
#define COMPUTING_FUNDAMENTALS_CPP_HEAP_H

using namespace iro;

namespace iro {
namespace utils {

template <class T>
class heap {
 public:
  virtual T peek() = 0;
  virtual T pop() = 0;
  virtual void push(T element) = 0;
  virtual void remove() = 0;
  virtual void replace() = 0;

  virtual void heapify() = 0;
  virtual void merge(heap* other) = 0;
  virtual void meld(heap* other) = 0;

  virtual int size();
  virtual bool is_empty();

 protected:
  virtual void update_key() = 0;
  virtual void sift() = 0;
  int size_ = 0;
};

template <class T>
int heap<T>::size() {
  return this->size_;
}

template <class T>
bool heap<T>::is_empty() {
  return this->size_ == 0;
}

}  // namespace util
}  // namespace iro

#endif