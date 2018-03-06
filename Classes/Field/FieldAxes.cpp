#include "FieldAxes.h"
#include "Axes.h"


void FieldAxes::SetX(const int &value)
{
	originalX = value;
	if (originalX < 0)
	{
		x = 0;
	}
	else if (originalX > Axes::GetMaxForX())
	{
		x = Axes::GetMaxForX();
	}
	else
	{
		x = originalX;
	}
}
void FieldAxes::SetY(const int &value)
{
	originalY = value;
	if (originalY < 0)
	{
		y = 0;
	}
	else if (originalY > Axes::GetMaxForY())
	{
		y = Axes::GetMaxForY();
	}
	else
	{
		y = originalY;
	}
}
int FieldAxes::ToLeft() const
{
	return Axes::ConvertToLeft(x);
}
int FieldAxes::ToTop() const
{
	return Axes::ConvertToLeft(y);;
}
cocos2d::Vec2 FieldAxes::ToVec2() const
{
	return Axes::ConvertToVec2(x, y);;
}
bool FieldAxes::CheckOutside() const
{
	if (originalX != x || originalY != y)
	{
		return false;
	}
	else
	{ 
		return true;
	}
}

