#include "Cell.h"
#include "Field.h"
#include "Element\ElementRelations.h"

using namespace std;

bool Cell::CanAddElement(const ClassType & type) const
{
	return ElementRelations::CanAdd(type, GetAllTypes());
}
void Cell::AddElement(AdvancedElement & item)
{
	AdvancedElement && a = std::move(item);

	if (ContainElement(item) == false)
	{
		items.push_back(a);
		CheckRelations();
	}
}
bool Cell::ContainName(const ElementNameType & name) const
{
	auto result = std::find_if(items.begin(), items.end(), [=](const AdvancedElement & item)
	{
		return name == item.GetName();
	});

	return result != items.end();
}
bool Cell::ContainType(const ClassType & type) const
{
	auto result = std::find_if(items.begin(), items.end(), [=](const AdvancedElement & item)
	{
		return type == item.GetType();
	});

	return result != items.end();
}
bool Cell::ContainElement(const AdvancedElement & item) const
{
	return std::find(items.begin(), items.end(), item) != items.end();
}
void Cell::RemoveElement(AdvancedElement & item)
{
	//items.remove_if([&](const AdvancedElement & value) {return item.GetName() == value.GetName(); });
	items.remove(item);
	
	CheckRelations();
}
ClassType Cell::GetDoubleElements()
{
	ClassType result = ClassType::Empty;
	int types = 0;

	std::any_of(items.begin(), items.end(), [&](const AdvancedElement & item)
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

	std::for_each(items.begin(), items.end(), [&](const AdvancedElement & item)
	{
		result |= (int)item.GetType();
	});

	return result;
}
void Cell::CheckRelations()
{
	if (ElementRelations::DoubleCalc(GetDoubleElements()) == ResultType::Destroy)
	{
		Destroy();
	}
	switch (ElementRelations::Calc(GetAllTypes()))
	{
	case ResultType::Win:
		// Win
		Field::WinGame();
		Destroy();
		break;
	case ResultType::Lose:
		// Lose
		Field::LoseGame();
		Destroy();
		break;
	case ResultType::Destroy:
		Destroy();
		break;
	}
}
void Cell::Destroy(bool allItem)
{
	std::for_each(items.begin(), items.end(), [=](AdvancedElement & item)
	{
		if ((allItem == true) || (ElementRelations::CanDestroy(item.GetType()) == true))
		{
			AdvancedElement * prov = &item;
			prov->Destroy();
		}
	});
}