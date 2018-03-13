#include "Axes.h"
#include "Settings.h"

#include "AxesInfo.h"

Axes AxesInfo::ConvertToAxes(const int & value)
{
	int x = value % Settings::HORIZONTALCELLCOUNT;
	int y = value / Settings::HORIZONTALCELLCOUNT;

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
	return y * Settings::HORIZONTALCELLCOUNT + x;
}
int AxesInfo::ConvertToX(const int &value)
{
	return value / (Settings::FIELDWIDTHSIZE / Settings::HORIZONTALCELLCOUNT);
}
int AxesInfo::ConvertToY(const int &value)
{
	return (Settings::FIELDHEIGHTSIZE - value) / (Settings::FIELDHEIGHTSIZE / Settings::VERTICALCELLCOUNT);
}
int AxesInfo::ConvertToLeft(const int &value)
{
	return (Settings::FIELDWIDTHSIZE / Settings::HORIZONTALCELLCOUNT) / 2 + value * (Settings::FIELDWIDTHSIZE / Settings::HORIZONTALCELLCOUNT);
}
int AxesInfo::ConvertToTop(const int &value)
{
	return Settings::FIELDHEIGHTSIZE - ((Settings::FIELDHEIGHTSIZE / Settings::VERTICALCELLCOUNT) / 2 + value * (Settings::FIELDHEIGHTSIZE / Settings::VERTICALCELLCOUNT));
}
