#pragma once

#include "list_node.h"

template <class T>
class LinkedList {
private:
	ListNode<T>* head_;
	int size_;
public:
	LinkedList<T>();
	void Add(T data);
	void Remove(T data);
	T Get(int index);
	int Size() const;
};

template <class T>
LinkedList<T>::LinkedList() {
	this->size_ = 0;
	this->head_ = nullptr;
}

template <class T>
void LinkedList<T>::Add(T data) {
	ListNode<T>* inserting = new ListNode<T>(data);
	if (!this->head_) {
		this->head_ = inserting;
	}
	else {
		ListNode<T>* current = this->head_;
		while (current->GetNext()) {
			current = current->GetNext();
		}
		current->SetNext(inserting);
	}
}

template <class T>
void LinkedList<T>::Remove(T data) {
	// walk list
}

template <class T>
T LinkedList<T>::Get(int index) {
	ListNode<T>* node = this->head_;
	for (int i = 0; i < index; index++) {
		node = node->GetNext();
	}
	return node;
}

template <class T>
int LinkedList<T>::Size() const {
	return this->size_;
}