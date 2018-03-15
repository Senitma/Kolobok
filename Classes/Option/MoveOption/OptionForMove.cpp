#include "MoveByPass.h"
#include "Field\AxesInfo.h"
#include "Option\MoveType.h"

#include "OptionForMove.h"

void OptionForMove::Standed()
{
	if (moveType != MoveType::ToOneStep && points.size() > 1)
	{
		// ѕри точки переходит к следующей
		if (parent.GetLeft() == AxesInfo::ConvertToLeft(this->points.front().GetX()) && 
			parent.GetTop() == AxesInfo::ConvertToTop(this->points.front().GetY()))
		{
			points.pop();
			OptionForOneStep::MoveTo(points.front().GetX(), points.front().GetY());
		}
		// ѕри движении в обход преп€тствий ищетс€ новый путь
		else if (moveType == MoveType::ToByPass)
		{
			MoveTo(nextX, nextY);
		}
		// ¬ остальных случа€х упретс€ в стену и будет ждать, пока стена не исчезнет
		else
		{
			OptionForOneStep::MoveTo(points.front().GetX(), points.front().GetY());
		}
	}
}

void OptionForMove::MoveTo(const MoveType & type, const int & x, const int & y)
{
	if (type == MoveType::ToOneStep)
	{
		return OptionForOneStep::MoveTo(x, y);
	}
	else
	{
		int calcX = parent.GetX() - x;
		int calcY = parent.GetY() - y;

		// ѕри движении в соседние клетки передаем управление в OptionForOneStep
		if (CheckAxesForNear(calcX, calcY) == true)
		{
			OptionForOneStep::MoveTo(x, y);
		}
		else
		{
			nextX = x;
			nextY = y;
			points = GeneratePath(type, x, y);
			OptionForOneStep::MoveTo(points.front().GetX(), points.front().GetY());
		}
	}
}

std::queue<Axes> OptionForMove::GeneratePath(const MoveType & type, const int & x, const int & y)
{
	switch (type)
	{
		case MoveType::ToByPass:
			return GenerateByPassPath(x, y);
			break;
		case MoveType::ToLine:
			// «начение по умолчанию
		default:
			return GenerateLinePath(x, y);
			break;
	}
}
std::queue<Axes> OptionForMove::GenerateLinePath(const int & x, const int & y)
{
	std::queue<Axes> path;
	int stepX = parent.GetX() < x ? 1 : -1;
	int stepY = parent.GetY() < y ? 1 : -1;
	int calcX = parent.GetX();
	int calcY = parent.GetY();

	while (calcX != x)
	{
		calcX += stepX;
		path.push(Axes(calcX, calcY));
	}
	while (calcY != y)
	{
		calcY += stepY;
		path.push(Axes(calcX, calcY));
	}

	return path;
}
std::queue<Axes> OptionForMove::GenerateByPassPath(const int & x, const int & y)
{
	return MoveByPass::MoveTo(parent.GetAxes(), Axes(x, y), true);
}