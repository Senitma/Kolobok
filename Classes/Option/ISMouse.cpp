#include "algorithm"
#include "list"

#include "Field\Field.h"
#include "Field\GameStatusType.h"

#include "ISMouse.h"

// Набор опций
static std::list<std::shared_ptr<ISMouse>> items;

void ISMouse::Register(std::shared_ptr<ISMouse> option)
{
	items.push_back(option);
}
void ISMouse::PassMouseClick(const MouseType & type, const int & x, const int & y)
{
	if (Field::GetCurrentGameStatus() == GameStatusType::Gaming)
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
	else
	{
		items.clear();
		Field::Reload();
	}
}
