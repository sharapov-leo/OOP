#include "TQueue.h"

TQueue::TQueue() : head(nullptr) {
}

TQueue::TQueue(const TQueue& orig) {
	head = orig.head;
}

std::ostream& operator<<(std::ostream& os, const TQueue& queue) {

	std::shared_ptr<TQueueItem> item = queue.head;

	while (item != nullptr)
	{
		os << *item;
		item = item->GetNext();
	}

	return os;
}

void TQueue::push(std::shared_ptr<Figure> &&figure) {
	std::shared_ptr<TQueueItem> other(new TQueueItem(figure));
	other->SetNext(head);
	head = other;
}

bool TQueue::empty() {
	return head == nullptr;
}

std::shared_ptr<Figure> TQueue::pop() {
	std::shared_ptr<Figure> result;
	if (head != nullptr) {
		if (head->GetNext() == nullptr) {
			result = head->GetFigure();
			head.~shared_ptr();
			head = nullptr;
		}
		else {
			std::shared_ptr<TQueueItem> prev=head, cur=head->GetNext();
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

TQueue::~TQueue() {
	head.~shared_ptr();
}