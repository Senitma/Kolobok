#include "ISMouse.h"
#include "list"
#include "algorithm"

static std::list<std::shared_ptr<ISMouse>> items;

void ISMouse::Register(std::shared_ptr<ISMouse> option)
{
	items.push_back(option);
}
void ISMouse::PassMouseClick(const MouseType & type, const int & x, const int & y)
{
	std::for_each(items.begin(), items.end(), [&](std::shared_ptr<ISMouse> item)
	{
		if (item->GetParent().GetDestroyStatus() == false)
		{
			item->MouseClick(type, x, y);
		}
		else
		{
			items.remove(item);
		}
	});
}
