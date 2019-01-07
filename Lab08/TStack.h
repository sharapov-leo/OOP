#ifndef TSTACK_H
#define	TSTACK_H

#include "Hexagon.h"
#include "TStackItem.h"
#include "TIterator.h"
#include <memory>
#include <future>
#include <mutex>
#include <thread>

template <class T> class TStack {
public:
    TStack();
    
    void push(std::shared_ptr<T> &&item);
    bool empty();
    std::shared_ptr<T> pop();
	std::shared_ptr<T> pop_last();

	TIterator<TStackItem<T>, T> begin();
	TIterator<TStackItem<T>, T> end();

    template <class A> friend std::ostream& operator<<(std::ostream& os,const TStack<A>& stack);
    
	virtual ~TStack();
private:
    
    std::shared_ptr<TStackItem<T>> head;
};

#endif	/* TSTACK_H */

