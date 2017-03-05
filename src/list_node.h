//
// Created by ianrobrien on 2/28/17.
//

#ifndef COMPUTING_FUNDAMENTALS_LIST_NODE_H
#define COMPUTING_FUNDAMENTALS_LIST_NODE_H

template<class T>
class ListNode {
private:
    T *data_;
    ListNode<T> *next_;
public:
    ListNode<T>(T *data);

    ListNode<T> *next();

    void setNext(ListNode<T> *next);

    T *data();

};

template<class T>
ListNode<T>::ListNode(T *data) {
    this->data_ = data;
    this->next_ = nullptr;
}

template<class T>
void ListNode<T>::setNext(ListNode<T> *next) {
    this->next_ = next;
}

template<class T>
ListNode<T> *ListNode<T>::next() {
    return this->next_;
}

template<class T>
T *ListNode<T>::data() {
    return this->data_;
}

#endif //COMPUTING_FUNDAMENTALS_LIST_NODE_H
