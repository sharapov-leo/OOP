#include "TStack.h"
#include <exception>

template <class T> TStack<T>::TStack() : head(nullptr) {
}


template <class T> std::ostream& operator<<(std::ostream& os, const TStack<T>& stack) {

    std::shared_ptr<TStackItem<T>> item = stack.head;
    
    while(item!=nullptr)
    {
      os << *item;
      item = item->GetNext();
    }
    
    return os;
}

template <class T> void TStack<T>::push(std::shared_ptr<T> &&item) {
    std::shared_ptr<TStackItem<T>> other(new TStackItem<T>(item));
    other->SetNext(head);
    head = other;

}

template <class T> bool TStack<T>::empty() {
    return head == nullptr;
}

template <class T> std::shared_ptr<T> TStack<T>::pop() {
    std::shared_ptr<T> result;
    if (head != nullptr) {
        result = head->GetFigure();
        head = head->GetNext();
    }

    return result;
}

template <class T> std::shared_ptr<T> TStack<T>::pop_last() {
	std::shared_ptr<T> result;

	if (head != nullptr) {
		std::shared_ptr<TStackItem < T>> element = head;
		std::shared_ptr<TStackItem < T>> prev = nullptr;

		while (element->GetNext() != nullptr) {
			prev = element;
			element = element->GetNext();
		}

		if (prev != nullptr) {
			prev->SetNext(nullptr);
			result = element->GetFigure();

		}
		else {
			result = element->GetFigure();
			head = nullptr;
		}
	}

	return result;

}

template <class T> TIterator<TStackItem<T>, T> TStack<T>::begin()
{
	return TIterator<TStackItem<T>, T>(head);
}

template <class T> TIterator<TStackItem<T>, T> TStack<T>::end()
{
	return TIterator<TStackItem<T>, T>(nullptr);
}
template <class T> TStack<T>::~TStack() {

}

//#include "Figure.h"
template class TStack<Figure>;
template class TStack<std::function<void(void)>>;
template std::ostream& operator<<(std::ostream& os, const TStack<Figure>& stack); 