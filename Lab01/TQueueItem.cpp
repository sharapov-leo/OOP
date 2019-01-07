#include"TQueueItem.h"
#include<iostream>

TQueueItem::TQueueItem(const Pentagon& pentagon) {
	this->pentagon = pentagon;
	this->next = nullptr;
	std::cout << "Queue item: created" << std::endl;
}

TQueueItem::TQueueItem(const TQueueItem& orig) {
	this->pentagon = orig.pentagon;
	this->next = orig.next;
	std::cout << "Queue item: copied" << std::endl;
}

TQueueItem* TQueueItem::SetNext(TQueueItem* next) {
	TQueueItem* old = this->next;
	this->next = next;
	return old;
}

Pentagon TQueueItem::GetPentagon() const {
	return this->pentagon;
}

TQueueItem* TQueueItem::GetNext() {
	return this->next;
}

TQueueItem::~TQueueItem() {
	std::cout << "Queue item: deleted" << std::endl;
	delete next;
}

std::ostream& operator<<(std::ostream& os, const TQueueItem& obj) {
	os << "[" << obj.pentagon << "]" << std::endl;
	return os;
}
