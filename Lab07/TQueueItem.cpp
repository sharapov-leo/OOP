#include"TQueueItem.h"
#include<iostream>

template <class T> TQueueItem<T>::TQueueItem(const Pentagon& pentagon) {
	this->figure = figure;
	this->next = nullptr;
	std::cout << "Queue item: created" << std::endl;
}

template <class T> TQueueItem<T>::TQueueItem(const TQueueItem<T>& orig) {
	this->figure = orig.figure;
	this->next = orig.next;
	std::cout << "Queue item: copied" << std::endl;
}

template <class T> TQueueItem<T>::TQueueItem(const std::shared_ptr<T> &figure) {
	this->figure = figure;
	this->next = nullptr;
	std::cout << "Queue item: created" << std::endl;
}

template <class T>  TAllocationBlock TQueueItem<T>::stackitem_allocator(sizeof(TQueueItem<T>), 100);

template <class T> std::shared_ptr<TQueueItem<T>> TQueueItem<T>::SetNext(std::shared_ptr<TQueueItem<T>> next) {
	std::shared_ptr<TQueueItem> old = this->next;
	this->next = next;
	return old;
}

template <class T> std::shared_ptr<T> TQueueItem<T>::GetFigure() const {
	return this->figure;
}

template <class T> std::shared_ptr<TQueueItem<T>> TQueueItem<T>::GetNext() {
	return this->next;
}

template <class T> TQueueItem<T>::~TQueueItem() {
	std::cout << "Queue item: deleted" << std::endl;
	next.~shared_ptr();
}

template <class T> std::ostream& operator<<(std::ostream& os, const TQueueItem<T>& obj) {
	//os << "[" << obj.figure->Print() << "]" << std::endl;
	obj.figure->Print();
	return os;
}

template <class T> void * TQueueItem<T>::operator new (size_t size) {
	//std::cout << "Allocated :" << size << "bytes" << std::endl;
	return stackitem_allocator.allocate();
}

template <class T> void TQueueItem<T>::operator delete(void *p) {
	std::cout << "Deleted" << std::endl;
	
	stackitem_allocator.deallocate(p);
}

//#include "Figure.h"
template class TQueueItem<Figure>;
template std::ostream& operator<<(std::ostream& os, const TQueueItem<Figure>& obj);