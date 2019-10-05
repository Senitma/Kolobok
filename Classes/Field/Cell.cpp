#include "algorithm"

#include "Axes.h"
#include "AxesInfo.h"
#include "Relations.h"
#include "ResultType.h"
#include "Settings.h"

#include "Cell.h"

Cell::Cell()
{
	items = std::list<MoveElement>();
}
Cell::~Cell()
{
	std::for_each(++items.begin(), items.end(), [=](Element & item)
	{
		item.SetDestroyStatus(true);
		items.remove(item);
	});
}

void Cell::SetIndex(const int & index)
{
	Axes value = AxesInfo::ConvertToAxes(index);
	x = value.GetX();
	y = value.GetY();
}

bool Cell::CanAddElement(const ClassType & type) const
{
	return Relations::CanAdd(type, GetAllTypes());
}
bool Cell::ContainName(const ElementNameType & name) const
{
	auto result = std::find_if(items.begin(), items.end(), [=](const MoveElement & item)
	{
		return name == item.GetName();
	});

	return result != items.end();
}
bool Cell::ContainType(const ClassType & type) const
{
	auto result = std::find_if(items.begin(), items.end(), [=](const MoveElement & item)
	{
		return type == item.GetType();
	});

	return result != items.end();
}
bool Cell::ContainElement(const Element & item) const
{
	return std::find(items.begin(), items.end(), item) != items.end();
}
ResultType Cell::AddElement(Element & item)
{
	if (ContainElement(item) == false)
	{
		int order;
		int orderDelta = Relations::GetOrderDelta(item.GetType());

		if (orderDelta == 1)
		{
			order = x * Settings::VERTICALCELLCOUNT + y;
		}
		else
		{
			int calcX = x;
			int calcY = y;

			if (x < item.GetX())
			{
				calcX = item.GetX();
			}
			if (y < item.GetY())
			{
				calcY = item.GetY();
			}

			order = Settings::VERTICALCELLCOUNT * Settings::HORIZONTALCELLCOUNT + (calcX + calcY) * 5 + Relations::GetOrderDelta(item.GetType());
		}

		items.push_back(item);
		items.back().SetPosition(x, y, order);
		return CheckRelations();
	}

	return ResultType::None;
}
ResultType Cell::RemoveElement(Element & item)
{
	items.remove(item);
	
	return CheckRelations();
}

ClassType Cell::GetDoubleElements() const
{
	int result = 0;
	int types = 0;

	std::any_of(items.begin(), items.end(), [&](const MoveElement & item)
	{
		int type = item.GetType();
		if ((types & type) == type)
		{
			result = item.GetType();
			return false;
		}
		else
		{
			types |= type;
			return true;
		}
	});

	return (ClassType)result;
}
int Cell::GetAllTypes() const
{
	int result = 0;

	std::for_each(items.begin(), items.end(), [&](const MoveElement & item)
	{
		result |= (int)item.GetType();
	});

	return result;
}
ResultType Cell::CheckRelations()
{
	if (Relations::DoubleCalc(GetDoubleElements()) == ResultType::Destroy)
	{
		Destroy(false);
	}

	ResultType result = Relations::Calc(GetAllTypes());
	if ((result == ResultType::Destroy) || (result == ResultType::Lose))
	{
		Destroy(false);
	}

	return result;
}
void Cell::Destroy(const bool & allItem)
{
	std::for_each(++items.begin(), items.end(), [=](Element & item)
	{
		if ((allItem == true) || (Relations::CanDestroy(item.GetType()) == true))
		{
			item.SetDestroyStatus(true);
			items.remove(item);
		}
	});
}