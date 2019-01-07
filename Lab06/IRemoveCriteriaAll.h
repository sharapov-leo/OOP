#ifndef IREMOVECRITERIAALL_H
#define	IREMOVECRITERIAALL_H

#include "IRemoveCriteria.h"

template <class T> class IRemoveCriteriaAll : public IRemoveCriteria<T>{
public:
    IRemoveCriteriaAll() {};
    bool isIt(std::shared_ptr<T> &value) override{
        return true;
    }
private:

};

#endif	/* IREMOVECRITERIAALL_H */

