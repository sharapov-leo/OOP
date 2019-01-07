#include "TQueue.h"

template <class T> TQueue<T>::TQueue() : head(nullptr) {
}

template <class T> TQueue<T>::TQueue(const TQueue<T>& orig) {
	head = orig.head;
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
	std::shared_ptr<TQueueItem<T>> other(new TQueueItem<T>(figure));
	other->SetNext(head);
	head = other;
}

template <class T> bool TQueue<T>::empty() {
	return head == nullptr;
}

template <class T> std::shared_ptr<T> TQueue<T>::pop() {
	std::shared_ptr<T> result;
	if (head != nullptr) {
		if (head->GetNext() == nullptr) {
			result = head->GetFigure();
			head.~shared_ptr();
			head = nullptr;
		}
		else {
			std::shared_ptr<TQueueItem<T>> prev=head, cur=head->GetNext();
			while (cur->GetNext() != nullptr) {
				cur = cur->GetNext();
				prev = prev->GetNext();
			}
			prev->SetNext(nullptr);
			result = cur->GetFigure();
			cur.~shared_ptr();
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