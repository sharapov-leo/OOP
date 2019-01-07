#include "TQueue.h"

TQueue::TQueue() : head(nullptr) {
}

TQueue::TQueue(const TQueue& orig) {
	head = orig.head;
}

std::ostream& operator<<(std::ostream& os, const TQueue& queue) {

	TQueueItem *item = queue.head;

	while (item != nullptr)
	{
		os << *item;
		item = item->GetNext();
	}

	return os;
}

void TQueue::push(Pentagon &&pentagon) {
	TQueueItem *other = new TQueueItem(pentagon);
	std::cout << (head == NULL) << std::endl;
	other->SetNext(head);
	head = other;
}

bool TQueue::empty() {
	return head == nullptr;
}

Pentagon TQueue::pop() {
	/*Pentagon result;
	if (head != nullptr) {
		TQueueItem *old_head = head;
		head = head->GetNext();
		result = old_head->GetPentagon();
		old_head->SetNext(nullptr);
		delete old_head;
	}
	return result;*/
	Pentagon result;
	if (head != nullptr) {
		if (head->GetNext() == nullptr) {
			result = head->GetPentagon();
			delete head;
			head = nullptr;
		}
		else {
			TQueueItem *prev=head, *cur=head->GetNext();
			while (cur->GetNext() != nullptr) {
				cur = cur->GetNext();
				prev = prev->GetNext();
			}
			prev->SetNext(nullptr);
			result = cur->GetPentagon();
			delete cur;
		}
	}
	return result;
}

TQueue::~TQueue() {
	delete head;
}