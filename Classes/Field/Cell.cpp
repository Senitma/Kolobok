#include "Cell.h"
#include "Element\ElementRelations.h"

bool Cell::CanAddElement(const ClassType & type) const
{
	return ElementRelations::CanAdd(type, GetAllTypes());
}
ResultType Cell::AddElement(const Element & item)
{
	if (ContainElement(item) == false)
	{
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
	ClassType result = ClassType::Empty;
	int types = 0;

	std::any_of(items.begin(), items.end(), [&](const Element & item)
	{
		int type = (int)item.GetType();
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

	return result;
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
	if (ElementRelations::DoubleCalc(GetDoubleElements()) == ResultType::Destroy)
	{
		Destroy(false);
	}

	ResultType result = ElementRelations::Calc(GetAllTypes());
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
		if ((allItem == true) || (ElementRelations::CanDestroy(item.GetType()) == true))
		{
			items.remove(item);
		}
	});
}