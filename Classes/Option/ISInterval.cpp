#include "ISInterval.h"
#include "list"
#include "algorithm"

// Набор опций с обновлением
static std::list<ISInterval *> items;

ISInterval::ISInterval(Element & parent) : ISOption(parent)
{
	items.push_back(this);
}

void ISInterval::PassUpdate()
{
	std::for_each(items.begin(), items.end(), [](ISInterval * item)
	{
		if (item->GetParent().GetDestroyStatus() == false)
		{
			item->Update();
		}
		else
		{
			items.remove(item);
		}
	});
}