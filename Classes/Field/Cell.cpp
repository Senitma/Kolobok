#include "Cell.h"

bool Cell::CanAddElement(Element * item)
{
	return this -> CanAddElement(item->GetType());
}
bool Cell::CanAddElement(ClassType type)
{
	return ElementRelations::CanAdd(type, this->GetAllTypes());
}
void Cell::AddElement(Element * item)
{
	if (items.contains(item) == false)
	{
		this->items.pushBack(item);
		this->CheckRelations();
	}
}
bool Cell::ContainName(ElementNameType name)
{
	for (int index = 0; index < this->items.size(); index++)
	{
		if (items.at(index)->GetName() == name)
		{
			return true;
		}
	}

	return false;
}
bool Cell::ContainType(ClassType type)
{
	for (int index = 0; index < this->items.size(); index++)
	{
		if (items.at(index)->GetType() == type)
		{
			return true;
		}
	}

	return false;
}
bool Cell::ContainElement(Element * item)
{
	return items.contains(item);
}
void Cell::RemoveElement(Element * item)
{
	this->items.eraseObject(item, true);
	this->CheckRelations();
}
void Cell::RemoveElement(ElementNameType nodename)
{
	for (int index = 0; index < this->items.size(); index++)
	{
		if (items.at(index)->GetName() == nodename)
		{
			this->items.eraseObject(items.at(index), true);
			index--;
		}
	}

	this->CheckRelations();
}
Element * Cell::GetElement(ElementNameType nodename)
{
	for (int index = 0; index < this->items.size(); index++)
	{
		Element * item = items.at(index);
		if (item->GetName() == nodename)
		{
			return item;
		}
	}

	return nullptr;
}
void Cell::DestroyAll()
{
	Destroy(true);
	items.clear();
}

ClassType Cell::GetDoubleElements()
{
	int calcValue = 0;
	for (int index = 0; index < this->items.size(); index++)
	{
		int type = (int)items.at(index)->GetType();
		if ((calcValue & type) == type)
		{
			return (ClassType)type;
		}
		else
		{
			calcValue |= type;
		}
	}

	return ClassType::Empty;
}
int Cell::GetAllTypes()
{
	int calcValue = 0;
	for (int index = 0; index < this->items.size(); index++)
	{
		calcValue |= (int)items.at(index)->GetType();
	}

	return calcValue;
}
void Cell::CheckRelations()
{
	if (ElementRelations::DoubleCalc(this->GetDoubleElements()) == ResultType::Destroy)
	{
		this->Destroy();
	}
	switch (ElementRelations::Calc(this->GetAllTypes()))
	{
		case ResultType::Win:
			// Win
			this->Destroy();
			break;
		case ResultType::Lose:
			// Lose
			this->Destroy();
			break;
		case ResultType::Destroy:
			this->Destroy();
			break;
	}
}
void Cell::Destroy()
{
	Destroy(false);
}
void Cell::Destroy(bool allItem)
{
	for (int index = this->items.size() - 1; index >= 0; index--)
	{
		Element * item = items.at(index);
		if ((allItem == true) || (ElementRelations::CanDestroy(item->GetType()) == true))
		{
			item->Destroy();
		}
	}
}
