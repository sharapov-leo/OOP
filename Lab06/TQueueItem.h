#include <memory>
#include "TStack.h"
template <class T> class TQueueItem {
public:
	//TQueueItem(const Pentagon& pentagon);
	//TQueueItem(const TQueueItem& orig);
	TQueueItem(const std::shared_ptr<T> &figure);
	template <class A> friend std::ostream& operator<<(std::ostream& os, const TQueueItem<A>& obj);

	std::shared_ptr<TQueueItem<T>> SetNext(std::shared_ptr<TQueueItem> next);
	std::shared_ptr<TQueueItem<T>> GetNext();
	//std::shared_ptr<T> GetFigure() const;

	TStack<T> stack;
	int length = 0;

	void * operator new (size_t size);
	void operator delete(void *p);

	virtual ~TQueueItem();
private:
	//std::shared_ptr<T> figure;
	std::shared_ptr<TQueueItem<T>> next;
};