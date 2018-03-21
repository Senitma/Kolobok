#include "algorithm"
#include "list"

#include "Element\ElementNameType.h"
#include "Field\Field.h"
#include "Field\GameStatusType.h"

#include "ISInterval.h"

// Набор опций
static std::list<std::shared_ptr<ISInterval>> items;

void ISInterval::Register(std::shared_ptr<ISInterval> option)
{
	items.push_back(option);
}
void ISInterval::PassUpdate()
{
	if (Field::GetCurrentGameStatus() == GameStatusType::Gaming)
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
	else
	{
		// Запуск анимации только для главного героя
		std::for_each(items.begin(), items.end(), [](std::shared_ptr<ISInterval> item)
		{
			if (item->GetParent().GetDestroyStatus() == false)
			{
				if (item->GetParent().GetName() == ElementNameType::Main)
				{
					item->Update();
				}
			}
			else
			{
				items.remove(item);
			}
		});
	}
}