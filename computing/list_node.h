#pragma once

template <class T>
class ListNode {
private:
	T data_;
	ListNode<T>* next_;
public:
	ListNode<T>(T data);
	ListNode<T>* GetNext();
	void SetNext(ListNode<T>* next);
};

template <class T>
ListNode<T>::ListNode(T data) {
	this->data_ = data;
	this->next_ = nullptr;
}

template <class T>
void ListNode<T>::SetNext(ListNode<T>* next) {
	this->next_ = next;
}

template <class T>
ListNode<T>* ListNode<T>::GetNext() {
	return this->next_;
}