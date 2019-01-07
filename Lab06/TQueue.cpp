#include "TQueue.h"

template <class T> TQueue<T>::TQueue() : head(nullptr) {
}

template <class T> TQueue<T>::TQueue(const TQueue<T>& orig) {
	head = orig.head;
}

template <class T> void TQueue<T>::RemoveSubitem(IRemoveCriteria<T> * criteria) {
	std::shared_ptr<TQueueItem<T>> cur = head;
	while (cur != nullptr) {
		TStack<T> stackCopy;
		while (!cur->stack.empty()) {
			std::shared_ptr<T> curI = cur->stack.pop();
			if (criteria->isIt(curI)) {
				std::cout << "Stack: Delete element " << std::endl;
				cur->length--;
			}
			else
				stackCopy.push(curI);
		}
		if (stackCopy.empty()) {
			std::shared_ptr<TQueueItem<T>> start = head;
			if (cur == head) {
				
				head = head->GetNext();
			}
			else {
				
				while (start->GetNext() != cur) {
					start = start->GetNext();
				}
				
				start->SetNext(cur->GetNext());
				//cur = nullptr;
				cur = start;
			}
		}
		/*if (stackCopy.empty()) {
			std::shared_ptr<TQueueItem<T>> start = head;
			if (start == cur) {
				std::cout<<"here";
				head = head->GetNext();
				cur = head;
				continue;
			}
			while (start->GetNext() != cur) {
				start = start->GetNext();
			}
			start->SetNext(cur->GetNext());
			cur = start->GetNext();
			continue;
		}*/
		while (!stackCopy.empty())
			cur->stack.push(stackCopy.pop());
		cur = cur->GetNext();
	}
}

template <class T> std::ostream& operator<<(std::ostream& os, const TQueue<T>& queue) {

	std::shared_ptr<TQueueItem<T>> item = queue.head;

	while (item != nullptr)
	{
		os << *item;
		item = item->GetNext();
	}

	return os;
}

template <class T> void TQueue<T>::push(std::shared_ptr<T> &&figure) {
	std::shared_ptr<TQueueItem<T>> cur = head;
	bool ok = false;
	while (cur != nullptr) {
		if (cur->length < 5) {
			cur->stack.push(figure);
			cur->length++;
			ok = true;
			std::cout << cur->length;
			break;
		}
		else {
			cur = cur->GetNext();
		}
	}
	if (!ok) {
		std::shared_ptr<TQueueItem<T>> other(new TQueueItem<T>(figure));
		other->SetNext(head);
		head = other;
		head->length++;
	}

}

template <class T> bool TQueue<T>::empty() {
	return head == nullptr;
}

template <class T> std::shared_ptr<T> TQueue<T>::pop() {
	std::shared_ptr<T> result;
	if (head != nullptr) {
		if (head->GetNext() == nullptr) {
			//result = head->GetFigure();
			head = nullptr;
		}
		else {
			std::shared_ptr<TQueueItem<T>> prev=head, cur=head->GetNext();
			while (cur->GetNext() != nullptr) {
				cur = cur->GetNext();
				prev = prev->GetNext();
			}
			prev->SetNext(nullptr);
			//result = cur->GetFigure();
			cur = nullptr;
		}
	}
	return result;
}

template <class T> TIterator<TQueueItem<T>, T> TQueue<T>::begin()
{
	return TIterator<TQueueItem<T>, T>(head);
}

template <class T> TIterator<TQueueItem<T>, T> TQueue<T>::end()
{
	return TIterator<TQueueItem<T>, T>(nullptr);
}

template <class T> TQueue<T>::~TQueue() {
	head.~shared_ptr();
}

template class TQueue<Figure>;
template std::ostream& operator<<(std::ostream& os, const TQueue<Figure>& queue);