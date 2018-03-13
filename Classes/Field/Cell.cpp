#include "algorithm"

#include "AxesInfo.h"
#include "Relations.h"
#include "ResultType.h"

#include "Cell.h"

Cell::Cell(const int & x, const int & y)
{
	this->x = x;
	this->y = y;

	items = std::list<Element>();
}

bool Cell::CanAddElement(const ClassType & type) const
{
	return Relations::CanAdd(type, GetAllTypes());
}
ResultType Cell::AddElement(Element & item)
{
	if (ContainElement(item) == false)
	{
		SetAxes(item, x, y);
		items.push_back(item);
		return CheckRelations();
	}

	return ResultType::None;
}
bool Cell::ContainName(const ElementNameType & name) const
{
	auto result = std::find_if(items.begin(), items.end(), [=](const Element & item)
	{
		return name == item.GetName();
	});

	return result != items.end();
}
bool Cell::ContainType(const ClassType & type) const
{
	auto result = std::find_if(items.begin(), items.end(), [=](const Element & item)
	{
		return type == item.GetType();
	});

	return result != items.end();
}
bool Cell::ContainElement(const Element & item) const
{
	return std::find(items.begin(), items.end(), item) != items.end();
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

	std::any_of(items.begin(), items.end(), [&](const Element & item)
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

	std::for_each(items.begin(), items.end(), [&](const Element & item)
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
	if (result == ResultType::Destroy)
	{
		Destroy(false);
	}

	return result;
}
void Cell::Destroy(const bool & allItem)
{
	std::for_each(items.begin(), items.end(), [=](Element & item)
	{
		if ((allItem == true) || (Relations::CanDestroy(item.GetType()) == true))
		{
			items.remove(item);
		}
	});
}

// Friend функция класса Element
void SetAxes(Element & element, const int & x, const int & y)
{
	element.SetX(x);
	element.SetY(y);
	element.SetOrder(AxesInfo::ConvertToIndex(x, y) * Relations::GetOrderDelta(element.GetType()));
}
