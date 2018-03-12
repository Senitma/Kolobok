#include "AxesInfo.h"
#include "Axes.h"
#include "Main\Settings.h"

int AxesInfo::GetMaxX()
{
	return Settings::HORIZONTALCELLCOUNT;
}
int AxesInfo::GetMaxY()
{
	return Settings::VERTICALCELLCOUNT;
}
int AxesInfo::GetFieldWidth()
{
	return Settings::FIELDWIDTHSIZE;
}
int AxesInfo::GetFieldHeight()
{
	return Settings::FIELDHEIGHTSIZE;
}

Axes AxesInfo::ConvertToAxes(const int & value)
{
	int x = value % GetMaxX();
	int y = value / GetMaxX();

	return Axes(x, y);
}
Axes AxesInfo::ConvertToAxes(const int & left, const int & top)
{
	return Axes(ConvertToX(left), ConvertToY(top));
}
int AxesInfo::ConvertToIndex(const Axes & value)
{
	return ConvertToIndex(value.GetX(), value.GetY());
}
int AxesInfo::ConvertToIndex(const int & x, const int & y)
{
	return y * GetMaxX() + x;
}
int AxesInfo::ConvertToX(const int &value)
{
	return value / (GetFieldWidth() / GetMaxX());
}
int AxesInfo::ConvertToY(const int &value)
{
	return value / (GetFieldHeight() / GetMaxY());
}
int AxesInfo::ConvertToLeft(const int &value)
{
	return (GetFieldWidth() / GetMaxX()) / 2 + value * (GetFieldWidth() / GetMaxX());
}
int AxesInfo::ConvertToTop(const int &value)
{
	return GetFieldHeight() - ((GetFieldHeight() / GetMaxY()) / 2 + value * (GetFieldHeight() / GetMaxY()));
}
