#include "algorithm"
#include "list"

#include "ISInterval.h"

// Набор опций
static std::list<std::shared_ptr<ISInterval>> items;

void ISInterval::Register(std::shared_ptr<ISInterval> option)
{
	items.push_back(option);
}
void ISInterval::PassUpdate()
{
	std::for_each(items.begin(), items.end(), [](std::shared_ptr<ISInterval> item)
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