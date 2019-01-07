#include"TQueueItem.h"
#include<iostream>

template <class T> TQueueItem<T>::TQueueItem(const std::shared_ptr<T> &figure) {
	//this->figure = figure;
	this->stack.push(figure);
	this->next = nullptr;
	std::cout << "Queue item: created" << std::endl;
}

template <class T> std::shared_ptr<TQueueItem<T>> TQueueItem<T>::SetNext(std::shared_ptr<TQueueItem<T>> next) {
	std::shared_ptr<TQueueItem> old = this->next;
	this->next = next;
	return old;
}


template <class T> std::shared_ptr<TQueueItem<T>> TQueueItem<T>::GetNext() {
	return this->next;
}

template <class T> TQueueItem<T>::~TQueueItem() {
	std::cout << "Queue item: deleted" << std::endl;
	next.~shared_ptr();
}

template <class T> std::ostream& operator<<(std::ostream& os, const TQueueItem<T>& obj) {

	std::cout << "["<<std::endl<<obj.stack<<"]"<<std::endl;
	return os;
}

template <class T> void * TQueueItem<T>::operator new (size_t size) {
	std::cout << "Allocated :" << size << "bytes" << std::endl;
	return malloc(size);
}

template <class T> void TQueueItem<T>::operator delete(void *p) {
	std::cout << "Deleted" << std::endl;
	free(p);
}

//#include "Figure.h"
template class TQueueItem<Figure>;
template std::ostream& operator<<(std::ostream& os, const TQueueItem<Figure>& obj);