#include "MoveByPass.h"
#include "Field\AxesInfo.h"
#include "Option\MoveType.h"

#include "OptionForMove.h"

OptionForMove::OptionForMove(const Element & parent) : OptionForOneStep(parent)
{
	int nextX = 0;
	int nextY = 0;

	MoveType moveType = MoveType::None;
	std::queue<Axes> points = std::queue<Axes>();
}

void OptionForMove::Standed()
{
	if (moveType != MoveType::ToOneStep && points.size() > 1)
	{
		// ��� ����� ��������� � ���������

		Axes calcAxes = AxesInfo::ConvertToOffset(parent.GetType(), points.front().GetX(), points.front().GetY());
		if ((parent.GetLeft() == calcAxes.GetX()) && (parent.GetTop() == calcAxes.GetY()))
		{
			points.pop();
			OptionForOneStep::MoveTo(points.front().GetX(), points.front().GetY());
		}
		// ��� �������� � ����� ����������� ������ ����� ����
		else if (moveType == MoveType::ToByPass)
		{
			MoveTo(nextX, nextY);
		}
		// � ��������� ������� ������� � ����� � ����� �����, ���� ����� �� ��������
		else
		{
			OptionForOneStep::MoveTo(points.front().GetX(), points.front().GetY());
			MoveFinished();
		}
	}
	else
	{
		MoveFinished();
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

		// ��� �������� � �������� ������ �������� ���������� � OptionForOneStep
		if (CheckAxesForNear(calcX, calcY) == true)
		{
			OptionForOneStep::MoveTo(x, y);
		}
		else if ((parent.GetX() != x) || (parent.GetY() != y))
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
			// �������� �� ���������
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
	return MoveByPass::MoveTo(parent.GetAxes(), parent.GetSide(), Axes(x, y));
}