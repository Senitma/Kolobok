#include "AxesInfo.h"
#include "Axes.h"

int AxesInfo::maxForX = 20;
int AxesInfo::maxForY = 15;
int AxesInfo::nodeWidth = 0;
int AxesInfo::nodeHeight = 0;
int AxesInfo::cellWidth = 0;
int AxesInfo::cellHeight = 0;
int AxesInfo::cellDepth = 0;
int AxesInfo::fieldWidth = 0;
int AxesInfo::fieldHeight = 0;
int AxesInfo::gapWidth = 0;
int AxesInfo::gapHeight = 0;

Axes AxesInfo::ConvertToAxes(const int & value)
{
	int x = value % maxForX;
	int y = value / maxForX;

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
int AxesInfo::ConvertToX(const int &value)
{
	return value / (fieldWidth / maxForX);
}
int AxesInfo::ConvertToY(const int &value)
{
	return value / (fieldHeight / maxForY);
}
int AxesInfo::ConvertToLeft(const int &value)
{
	return (fieldWidth / maxForX) / 2 + value * (fieldWidth / maxForX);
}
int AxesInfo::ConvertToTop(const int &value)
{
	return fieldHeight - ((fieldHeight / maxForY) / 2 + value * (fieldHeight / maxForY));
}