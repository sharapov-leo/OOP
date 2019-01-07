#ifndef TSTACK_H
#define	TSTACK_H


#include "TIteratorStack.h"

class TStack {
public:
    TStack();
    TStack(const TStack& orig);
    
    void push(void *block);
    bool empty();
    //void *pop();

	TIteratorStack begin();
	TIteratorStack end();

    virtual ~TStack();
private:
    
    TStackItem *head;
};

#endif	/* TSTACK_H */

