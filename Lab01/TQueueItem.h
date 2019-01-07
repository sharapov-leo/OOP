#include "Pentagon.h"
class TQueueItem {
public:
	TQueueItem(const Pentagon& pentagon);
	TQueueItem(const TQueueItem& orig);
	friend std::ostream& operator<<(std::ostream& os, const TQueueItem& obj);

	TQueueItem* SetNext(TQueueItem* next);
	TQueueItem* GetNext();
	Pentagon GetPentagon() const;

	virtual ~TQueueItem();
private:
	Pentagon pentagon;
	TQueueItem *next;
};