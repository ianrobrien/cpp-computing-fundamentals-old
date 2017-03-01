//
// Created by ianrobrien on 2/28/17.
//

#ifndef COMPUTING_FUNDAMENTALS_LIST_NODE_H
#define COMPUTING_FUNDAMENTALS_LIST_NODE_H
#pragma once

template<class T>
class ListNode {
private:
    T data_;
    ListNode<T> *next_;
public:
    ListNode<T>(T data);

    ListNode<T> *GetNext();

    void SetNext(ListNode<T> *next);

    T GetData();

    void SetData(T data);
};

template<class T>
ListNode<T>::ListNode(T data) {
    this->data_ = data;
    this->next_ = nullptr;
}

template<class T>
void ListNode<T>::SetNext(ListNode<T> *next) {
    this->next_ = next;
}

template<class T>
ListNode<T> *ListNode<T>::GetNext() {
    return this->next_;
}

template<class T>
T ListNode<T>::GetData() {
    return this->data_;
}

template<class T>
void ListNode<T>::SetData(T data) {
    this->data_ = data;
}

#endif //COMPUTING_FUNDAMENTALS_LIST_NODE_H
