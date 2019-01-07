#include "TQueueItem.h"
#include "TIterator.h"
#include <memory>
#include <future>
#include <mutex>

template <class T> class TQueue {
public:
	TQueue();
	TQueue(const TQueue& orig);

	void push(std::shared_ptr<T> &&figure);
	void pushA(std::shared_ptr<T> figure);
	bool empty();
	size_t size();
	std::shared_ptr<T> pop();
	std::shared_ptr<T> pop_last();

	void sort();
	void sort_parallel();

	TIterator<TQueueItem<T>, T> begin();
	TIterator<TQueueItem<T>, T> end();

	template <class A> friend std::ostream& operator<<(std::ostream& os, const TQueue<A>& queue);

	virtual ~TQueue();
private:
	std::future<void> sort_in_background();
	std::shared_ptr<TQueueItem<T>> head;
};