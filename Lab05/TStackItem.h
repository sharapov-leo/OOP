#ifndef TSTACKITEM_H
#define	TSTACKITEM_H

class TStackItem {
public:
    TStackItem(void *block);
    //TStackItem(const TStackItem& orig);
    
    TStackItem* SetNext(TStackItem* next);
    TStackItem* GetNext();
    void *GetBlock() const;

	TStackItem * operator=(void *ptr);

    virtual ~TStackItem();
private:
	void *block;
    TStackItem *next;
};

#endif	/* TSTACKITEM_H */

