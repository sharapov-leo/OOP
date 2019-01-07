#ifndef TITERATOR_H
#define	TITERATOR_H
#include <memory>
#include <iostream>
#include "TStackItem.h"

class TIteratorStack
{
public:

    TIteratorStack(TStackItem *n)   {
        node_ptr = n;
    }

    void *operator * (){
        return node_ptr->GetBlock();
    }

    void *operator -> (){
        return node_ptr->GetBlock();
    }

    void operator ++ (){
        node_ptr = node_ptr->GetNext();
    }

    TIteratorStack operator ++ (int){
        TIteratorStack iter(*this);
        ++(*this);
        return iter;
    }

    bool operator == (TIteratorStack const& i){
        return node_ptr == i.node_ptr;
    }

    bool operator != (TIteratorStack const& i){
        return !(*this == i);
    }

	TIteratorStack operator=(void *ptr) {
		*this->node_ptr = ptr;
		return *this;
	}

private:

    TStackItem *node_ptr;
};

#endif	/* TITERATOR_H */

