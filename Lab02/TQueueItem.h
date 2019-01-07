#include "Hexagon.h"
#include <memory>
class TQueueItem {
public:
	TQueueItem(const Pentagon& pentagon);
	TQueueItem(const TQueueItem& orig);
	TQueueItem(const std::shared_ptr<Figure> &figure);
	friend std::ostream& operator<<(std::ostream& os, const TQueueItem& obj);

	std::shared_ptr<TQueueItem> SetNext(std::shared_ptr<TQueueItem> next);
	std::shared_ptr<TQueueItem> GetNext();
	std::shared_ptr<Figure> GetFigure() const;

	virtual ~TQueueItem();
private:
	std::shared_ptr<Figure> figure;
	std::shared_ptr<TQueueItem> next;
};