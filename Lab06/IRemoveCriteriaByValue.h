#ifndef IREMOVECRITERIABYVALUE_H
#define	IREMOVECRITERIABYVALUE_H

#include "IRemoveCriteriaAll.h"
template <class T> class IRemoveCriteriaByValue : public IRemoveCriteria<T>{
public:
    IRemoveCriteriaByValue(const std::shared_ptr<T> && value) : _value(value) {};
    bool isIt(std::shared_ptr<T> &value) override{
        return _value->Square()==value->Square();
    }

private:
	std::shared_ptr<T> _value;
};

#endif	/* IREMOVECRITERIABYVALUE_H */

