#include "FieldPoint.h"

int FieldPoint::GetX()
{
	if (0 <= x < Settings::HORIZONTALCELLCOUNT)
	{
		return x;
	}
	else if (x < 0)
	{
		return 0;
	}
	else
	{
		return Settings::HORIZONTALCELLCOUNT - 1;
	}
}
int FieldPoint::GetY()
{
	if (0 <= y < Settings::VERTICALCELLCOUNT)
	{
		return y;
	}
	else if (y < 0)
	{
		return 0;
	}
	else
	{
		return Settings::VERTICALCELLCOUNT - 1;
	}
}

int FieldPoint::ToLeft()
{
	return FieldPoint::ConvertToLeft(GetX());
}
int FieldPoint::ToTop()
{
	return FieldPoint::ConvertToTop(GetY());
}

int FieldPoint::ConvertToX(int left)
{
	return left / FieldPoint::GetCellWidth();
}
int FieldPoint::ConvertToY(int top)
{
	return (Settings::HEIGHTSIZE - top) / FieldPoint::GetCellHeight();
}
FieldPoint * FieldPoint::ConvertToXY(int left, int top)
{
	FieldPoint * result = new FieldPoint();
	result->SetX(FieldPoint::ConvertToX(left));
	result->SetY(FieldPoint::ConvertToY(top));

	return result;
}
int FieldPoint::ConvertToLeft(int x)
{
	return FieldPoint::GetCellWidth() / 2 + x * FieldPoint::GetCellWidth();
}
int FieldPoint::ConvertToTop(int y)
{
	return Settings::HEIGHTSIZE - (FieldPoint::GetCellHeight() / 2 + y * FieldPoint::GetCellHeight());
}

int FieldPoint::GetCellWidth()
{
	return Settings::WIDTHSIZE / Settings::HORIZONTALCELLCOUNT;
}
int FieldPoint::GetCellHeight()
{
	return Settings::HEIGHTSIZE / Settings::VERTICALCELLCOUNT;
}