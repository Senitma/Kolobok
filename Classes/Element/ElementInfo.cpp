#include "ElementInfo.h"
#include "ElementData.h"

ElementNameType ElementInfo::GetName() const
{
	return data->name;
}
ClassType ElementInfo::GetType() const
{
	return data->type;
}
SideType ElementInfo::GetSide() const
{
	return data->side;
}
int ElementInfo::GetX() const
{
	return data->position.GetX();
}
int ElementInfo::GetY() const
{
	return data->position.GetY();
}
BaseAxes ElementInfo::getAxes() const
{
	return data->position;
}

void ElementInfo::Destroy()
{
	data->Destroy();
}

bool ElementInfo::operator==(const ElementInfo & value)
{
	return data->node == value.data->node;
}
bool ElementInfo::operator!=(const ElementInfo & value)
{
	return data->node != value.data->node;
}
