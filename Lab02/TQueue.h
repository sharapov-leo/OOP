#include "TQueueItem.h"
#include <memory>
class TQueue {
public:
	TQueue();
	TQueue(const TQueue& orig);

	void push(std::shared_ptr<Figure> &&figure);
	bool empty();
	std::shared_ptr<Figure> pop();

	friend std::ostream& operator<<(std::ostream& os, const TQueue& queue);

	virtual ~TQueue();
private:
	std::shared_ptr<TQueueItem> head;
};