#include "TQueueItem.h"

class TQueue {
public:
	TQueue();
	TQueue(const TQueue& orig);

	void push(Pentagon &&pentagon);
	bool empty();
	Pentagon pop();
	friend std::ostream& operator<<(std::ostream& os, const TQueue& queue);
	virtual ~TQueue();
private:

	TQueueItem *head;
};