#include "FieldAxes.h"

void FieldAxes::SetX(const int &value)
{
	originalX = value;
	if (originalX < 0)
	{
		x = 0;
	}
	else if (originalX > maxForX)
	{
		x = maxForX;
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
	else if (originalY > maxForY)
	{
		y = maxForY;
	}
	else
	{
		y = originalY;
	}
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

int FieldAxes::ConvertToX(const int &value)
{
	return value / (fieldWidth / maxForX);
}
int FieldAxes::ConvertToY(const int &value)
{
	return value / (fieldHeight / maxForY);
}

cocos2d::Vec2 FieldAxes::ConvertToVec2(const int &x, const int &y)
{
	return cocos2d::Vec2(x,y);
}
int FieldAxes::ConvertToLeft(const int &value)
{
	return (fieldWidth / maxForX) / 2 + value * (fieldWidth / maxForX);
}
int FieldAxes::ConvertToTop(const int &value)
{
	return fieldHeight - ((fieldHeight / maxForY) / 2 + value * (fieldHeight / maxForY));
}
