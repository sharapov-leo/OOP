#ifndef IREMOVECRITERIA_H
#define	IREMOVECRITERIA_H

template <class T> class IRemoveCriteria {
public:
    virtual bool isIt(std::shared_ptr<T> &value) = 0;
private:

};

#endif	/* IREMOVECRITERIA_H */

