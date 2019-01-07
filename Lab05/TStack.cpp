#include "TStack.h"
#include "TIterator.h"

TStack::TStack() : head(nullptr) {
}

TStack::TStack(const TStack& orig) {
    head = orig.head;
}

void TStack::push(void *block) {
    TStackItem *other = new TStackItem(block);
    other->SetNext(head);
    head = other;
}

bool TStack::empty() {
    return head == nullptr;
}

/*void* TStack::pop() {
	void *result = nullptr;
    if (head != nullptr) {
        TStackItem *old_head = head;
        head = head->GetNext();
        result = old_head->GetBlock();
        old_head->SetNext(nullptr);
        delete old_head;
    }

    return result;
}*/

TIteratorStack TStack::begin()
{
	return TIteratorStack(head);
}

TIteratorStack TStack::end()
{
	return TIteratorStack(nullptr);
}

TStack::~TStack() {
    delete head;
}

