#include "TQueueItem.h"
#include "TIterator.h"
#include "IRemoveCriteria.h"
#include <memory>

template <class T> class TQueue {
public:
	TQueue();
	TQueue(const TQueue& orig);

	void push(std::shared_ptr<T> &&figure);
	bool empty();
	std::shared_ptr<T> pop();

	void RemoveSubitem(IRemoveCriteria<T> * criteria);

	TIterator<TQueueItem<T>, T> begin();
	TIterator<TQueueItem<T>, T> end();

	template <class A> friend std::ostream& operator<<(std::ostream& os, const TQueue<A>& queue);

	virtual ~TQueue();
private:
	std::shared_ptr<TQueueItem<T>> head;
};