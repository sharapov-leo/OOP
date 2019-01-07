#include "TStackItem.h"
#include <iostream>

TStackItem::TStackItem(void *block) {
    this->block = block;
    this->next = nullptr;
    std::cout << "Stack item: created" << std::endl;
}

/*TStackItem::TStackItem(const TStackItem& orig) {
    this->triangle = orig.triangle;
    this->next = orig.next;
    std::cout << "Stack item: copied" << std::endl;
}*/

TStackItem* TStackItem::SetNext(TStackItem* next) {
    TStackItem* old = this->next;
    this->next = next;
    return old;
}

void* TStackItem::GetBlock() const {
    return this->block;
}

TStackItem * TStackItem::operator=(void *ptr) {
	this->block = ptr;
	return this;
}



TStackItem* TStackItem::GetNext() {
    return this->next;
}

TStackItem::~TStackItem() {
    std::cout << "Stack item: deleted" << std::endl;
    delete next;
}