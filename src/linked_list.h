//
// Created by ianrobrien on 2/28/17.
//

#ifndef COMPUTING_FUNDAMENTALS_LINKED_LIST_H
#define COMPUTING_FUNDAMENTALS_LINKED_LIST_H

#include "list_node.h"

template <class T>
class LinkedList
{
  private:
    ListNode<T> *head_;
    int size_;

  public:
    LinkedList<T>();
    int size() const;
    bool Contains(T *element);
    T Get(int index);
    int IndexOf(T *element);
    bool IsEmpty();
    int LastIndexOf(T *element);
    bool Add(T *element);
    bool Add(int index, T *element);
    void Clear();
    bool Remove(T *element);
    bool RemoveAt(int index, T *element);
    T Set(int index, T *element);
};

template <class T>
LinkedList<T>::LinkedList()
{
    this->size_ = 0;
    this->head_ = nullptr;
}

template <class T>
int LinkedList<T>::size() const
{
    return this->size_;
}

template <class T>
T LinkedList<T>::Get(int index)
{
    ListNode<T> *node = this->head_;
    for (int i = 0; i < index; index++)
    {
        node = node->next();
    }
    return node;
}

template <class T>
bool LinkedList<T>::Contains(T *element)
{
    return this->IndexOf(element) >= 0;
};

template <class T>
int LinkedList<T>::IndexOf(T *element)
{
    ListNode<T> *current = this->head_;
    int index = 0;
    while (current)
    {
        if (current->data() == element)
        {
            return index;
        }
        current = current->next();
        index++;
    }
    return -1;
};

template <class T>
bool LinkedList<T>::IsEmpty()
{
    return this->size_ == 0;
}

template <class T>
int LinkedList<T>::LastIndexOf(T *element)
{
    ListNode<T> *current = this->head_;
    int lastIndex = -1;
    int currentIndex = 0;
    while (current)
    {
        if (current->data() == element)
        {
            lastIndex = currentIndex;
        }
        current = current->next();
        currentIndex++;
    }
    return lastIndex;
};

template <class T>
bool LinkedList<T>::Add(T *element)
{
    this->Add(this->size_, element);
}

template <class T>
bool LinkedList<T>::Add(int index, T *element)
{
    ListNode<T> *inserting = new ListNode<T>(element);
    if (index == 0)
    {
        if (this->head_)
        {
            inserting->setNext(this->head_);
        }
        this->head_ = inserting;
    }
    else
    {
        ListNode<T> *current = this->head_;
        for (int i = 0; i < index - 1; i++)
        {
            current = current->next();
        }
        current->setNext(inserting);
    }
    this->size_++;
}

template <class T>
void LinkedList<T>::Clear()
{
}

template <class T>
bool LinkedList<T>::Remove(T *element)
{
}

template <class T>
bool LinkedList<T>::RemoveAt(int index, T *element)
{
    return false;
}

#endif //COMPUTING_FUNDAMENTALS_LINKED_LIST_H
