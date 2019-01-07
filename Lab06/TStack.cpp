#include "TStack.h"

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

template <class T> void TStack<T>::push(std::shared_ptr<T> &item) {
	if (head == nullptr) {
		std::shared_ptr<TStackItem<T>> other(new TStackItem<T>(item));
		other->SetNext(head);
		head = other;
	}
	else {
		std::shared_ptr<TStackItem<T>> other(new TStackItem<T>(item));
		std::shared_ptr<TStackItem<T>> cur = head;
		while ((cur->GetNext()!=nullptr)&&(cur->GetFigure()->Square() < item->Square())) {
			cur = cur->GetNext();
		}
		if (cur->GetNext() == nullptr) {
			if (cur == head) {
				if (cur->GetFigure()->Square() < item->Square()) {
					head->SetNext(other);
				}
				else {
					other->SetNext(head);
					head = other;
				}
				return;
			}
			else
			{
				//cur->SetNext(other);
				if (cur->GetFigure()->Square() < item->Square()) {
					cur->SetNext(other);
				}
				else {
					std::shared_ptr<TStackItem<T>> curT = head;
					while (curT->GetNext() != cur) {
						curT = curT->GetNext();
					}
					curT->SetNext(other);
					other->SetNext(cur);
				}
			}
			return;
		}
		else {
			if (cur == head) {
				if (cur->GetFigure()->Square() < item->Square()) {
					head->SetNext(other);
				}
				else {
					other->SetNext(head);
					head = other;
				}
				return;
			}
			else {
				std::shared_ptr<TStackItem<T>> curc = head;
				while (curc->GetNext() != cur) {
					curc = curc->GetNext();
				}
				curc->SetNext(other);
				other->SetNext(cur);
			}
		}

	}
}

template <class T> void TStack<T>::push(const std::shared_ptr<T> &item) {
	if (head == nullptr) {
		std::shared_ptr<TStackItem<T>> other(new TStackItem<T>(item));
		other->SetNext(head);
		head = other;
	}
	else {
		std::shared_ptr<TStackItem<T>> other(new TStackItem<T>(item));
		std::shared_ptr<TStackItem<T>> cur = head;
		while ((cur->GetNext() != nullptr) && (cur->GetFigure()->Square() < item->Square())) {
			cur = cur->GetNext();
		}
		if (cur->GetNext() == nullptr) {
			if (cur == head) {
				if (cur->GetFigure()->Square() < item->Square()) {
					head->SetNext(other);
				}
				else {
					other->SetNext(head);
					head = other;
				}
				return;
			}
			else
			{
				//cur->SetNext(other);
				if (cur->GetFigure()->Square() < item->Square()) {
					cur->SetNext(other);
				}
				else {
					std::shared_ptr<TStackItem<T>> curT = head;
					while (curT->GetNext() != cur) {
						curT = curT->GetNext();
					}
					curT->SetNext(other);
					other->SetNext(cur);
				}
			}
			return;
		}
		else {
			if (cur == head) {
				if (cur->GetFigure()->Square() < item->Square()) {
					head->SetNext(other);
				}
				else {
					other->SetNext(head);
					head = other;
				}
				return;
			}
			else {
				std::shared_ptr<TStackItem<T>> curc = head;
				while (curc->GetNext() != cur) {
					curc = curc->GetNext();
				}
				curc->SetNext(other);
				other->SetNext(cur);
			}
		}

	}
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
template std::ostream& operator<<(std::ostream& os, const TStack<Figure>& stack); 