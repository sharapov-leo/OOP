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
template <class T> void TQueue<T>::pushA(std::shared_ptr<T> figure) {
	std::shared_ptr<TQueueItem<T>> other(new TQueueItem<T>(figure));
	other->SetNext(head);
	head = other;
}
template <class T> bool TQueue<T>::empty() {
	return head == nullptr;
}

template <class T> size_t TQueue<T>::size() {
	int result = 0;
    for (auto i : * this) result++;
    return result;
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
template <class T> std::shared_ptr<T> TQueue<T>::pop_last() {
	std::shared_ptr<T> result;

	if (head != nullptr) {
		std::shared_ptr<TQueueItem < T>> element = head;
		std::shared_ptr<TQueueItem < T>> prev = nullptr;

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
template <class T> void TQueue<T>::sort() {
	if (size() > 1) {
		std::shared_ptr<T> middle = pop();
		TQueue<T> left, right;

		while (!empty()) {
			std::shared_ptr<T> item = pop();
			if (item->Square() < middle->Square()) {
				left.pushA(item);
			}
			else {
				right.pushA(item);
			}
		}

		left.sort();
		right.sort();

		while (!left.empty()) pushA(left.pop_last());
		pushA(middle);
		while (!right.empty()) pushA(right.pop_last());

	}
}

template<class T > std::future<void> TQueue<T>::sort_in_background() {
	return std::async(std::bind(std::mem_fn(&TQueue<T>::sort_parallel), this));
}

template <class T> void TQueue<T>::sort_parallel() {
	if (size() > 1) {
		std::shared_ptr<T> middle = pop_last();
		TQueue<T> left, right;

		while (!empty()) {
			std::shared_ptr<T> item = pop_last();
			if (item->Square() < middle->Square()) {
				left.pushA(item);
			}
			else {
				right.pushA(item);
			}
		}

		std::future<void> left_res = left.sort_in_background();
		std::future<void> right_res = right.sort_in_background();


		left_res.get();


		while (!left.empty()) pushA(left.pop_last());
		pushA(middle);

		right_res.get();
		while (!right.empty()) pushA(right.pop_last());

	}
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