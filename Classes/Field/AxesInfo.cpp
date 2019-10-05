#include "cmath"

#include "Axes.h"
#include "Element\ClassType.h"
#include "Relations.h"
#include "Settings.h"

#include "AxesInfo.h"

int AxesInfo::ANGLE = 120;

Axes AxesInfo::ConvertToAxes(const int & value)
{
	int x = value % Settings::HORIZONTALCELLCOUNT;
	int y = value / Settings::HORIZONTALCELLCOUNT;

	return Axes(x, y);
}
Axes AxesInfo::ConvertToAxes(const int & left, const int & top)
{
	//int x = (Settings::FIELDWIDTHSIZE - (left - Settings::OFFSETX)) / Settings::CELLWIDTH;
	//int y = (Settings::FIELDHEIGHTSIZE - (top - Settings::OFFSETY)) / Settings::CELLHEIGHT;

	int x = round((double)Settings::HORIZONTALCELLCOUNT - (left - Settings::OFFSETX) / (double)Settings::CELLWIDTH - (top - Settings::OFFSETY) / (double)Settings::CELLHEIGHT);
	int y = round((left - Settings::OFFSETX) / (double)Settings::CELLWIDTH + (double)Settings::VERTICALCELLCOUNT - (top - Settings::OFFSETY) / (double)Settings::CELLHEIGHT);

	Axes a = Axes(x, y);
	
	return a;
}
Axes AxesInfo::ConvertToOffset(const ClassType & side, const int & x, const int & y)
{
	//int left = (Settings::FIELDWIDTHSIZE - (Settings::CELLWIDTH / 2 + x * Settings::CELLWIDTH)) + Settings::OFFSETX;
	//int top = (Settings::FIELDHEIGHTSIZE - (Settings::CELLHEIGHT / 2 + y * Settings::CELLHEIGHT)) + Settings::OFFSETY;

	int left = ((Settings::HORIZONTALCELLCOUNT - x - Settings::VERTICALCELLCOUNT + y) * Settings::CELLWIDTH - Settings::CELLWIDTH) / 2 + Settings::OFFSETX;
	int top = ((Settings::HORIZONTALCELLCOUNT - x + Settings::VERTICALCELLCOUNT - y) * Settings::CELLHEIGHT + Settings::CELLHEIGHT) / 2 + Settings::OFFSETY;

	if (Relations::GetOrderDelta(side) != 1) { top += 61; }

	return Axes(left, top);
}
int AxesInfo::ConvertToIndex(const Axes & value)
{
	return ConvertToIndex(value.GetX(), value.GetY());
}
int AxesInfo::ConvertToIndex(const int & x, const int & y)
{
	return y * Settings::HORIZONTALCELLCOUNT + x;
}
