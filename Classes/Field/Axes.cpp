#include "Axes.h"

int Axes::maxForX = 20;
int Axes::maxForY = 15;

int Axes::nodeWidth = 0;
int Axes::nodeHeight = 0;
int Axes::cellWidth = 0;
int Axes::cellHeight = 0;
int Axes::cellDepth = 0;
int Axes::fieldWidth = 0;
int Axes::fieldHeight = 0;
int Axes::gapWidth = 0;
int Axes::gapHeight = 0;

BaseAxes Axes::ConvertToAxes(const int & value)
{
	int x = value % maxForX;
	int y = value / maxForX;

	return BaseAxes(x, y);
}

int Axes::ConvertToX(const int &value)
{
	return value / (fieldWidth / maxForX);
}
int Axes::ConvertToY(const int &value)
{
	return value / (fieldHeight / maxForY);
}

int Axes::ConvertToLeft(const int &value)
{
	return (fieldWidth / maxForX) / 2 + value * (fieldWidth / maxForX);
}
int Axes::ConvertToTop(const int &value)
{
	return fieldHeight - ((fieldHeight / maxForY) / 2 + value * (fieldHeight / maxForY));
}