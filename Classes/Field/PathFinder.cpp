#include "PathFinder.h"
#include "TagAxes.h"
#include "Axes.h"

PathFinder::PathFinder(std::vector<TagAxes> & map, const BaseAxes & start, const BaseAxes & finish)
{
	this->map = map;
	this->map.at(Axes::ConvertToIndex(start)).SetTag(0);
	this->map.at(Axes::ConvertToIndex(finish)).SetTag(-2);

	startX = start.GetX();
	startY = start.GetY();
	finishX = finish.GetX();
	finishY = finish.GetY();
}

bool PathFinder::CanMoveTo(std::vector<TagAxes> & map, const BaseAxes & start, const BaseAxes & finish)
{
	PathFinder newPath = PathFinder(map, start, finish);

	return newPath.FindFinish();
}
std::vector<BaseAxes> PathFinder::MoveTo(std::vector<TagAxes> & map, const BaseAxes & start, const BaseAxes & finish)
{
	PathFinder newPath = PathFinder(map, start, finish);

	if (newPath.FindFinish() == true)
	{
		return newPath.CreateMoveMap();
	}
	else
	{
		if (newPath.FindNewFinish() == true)
		{
			// ����� ��������� ����� � ������
			return newPath.CreateMoveMap();
		}
		else
		{
			// ���������� ����� ��������� ����� � ������
			return std::vector<BaseAxes>{ start };
		}
	}
}

bool PathFinder::FindFinish()
{
	bool isFinished = false;
	step = 0;

	int moveCheker;
	const int MAXEMPTYMOVED = 3;

	do
	{
		for (int x = 0; x < Axes::GetMaxForX(); x++)
		{
			for (int y = 0; y < Axes::GetMaxForY(); y++)
			{
				TagAxes &parent = map.at(Axes::ConvertToIndex(x, y));

				// ������� ��� ���������� ����� ����� �� ����� � ������ ��������
				auto AddStep = [&](TagAxes &point)
				{
					if (point.GetTag() == -1)
					{
						if ((parent.GetPrevX() != point.GetX()) && (parent.GetPrevY() != point.GetY()))
						{
							// ���������� ��������������
							point.SetTag(step + 2);
						}
						else
						{
							// ����������� �� ������
							point.SetTag(step + 1);
						}

						point.SetPrevX(x);
						point.SetPrevY(y);
						moveCheker = MAXEMPTYMOVED;
					}
				};

				// ����� ������� ����� ��� ���������� ����
				if (parent.GetTag() == step)
				{
					// �������� ��� ��������� ������
					if (x != Axes::GetMaxForX() - 1)
					{
						AddStep(map.at(Axes::ConvertToIndex(x + 1, y)));
					}
					if (y != Axes::GetMaxForY() - 1)
					{
						AddStep(map.at(Axes::ConvertToIndex(x, y + 1)));
					}
					if (x != 0)
					{
						AddStep(map.at(Axes::ConvertToIndex(x - 1, y)));
					}
					if (y != 0)
					{
						AddStep(map.at(Axes::ConvertToIndex(x, y - 1)));
					}

					// ������� ��� ������ ������ ������ � �������� �������
					auto CheckFinish = [&](TagAxes &point)
					{
						if (point.GetTag() == -2)
						{
							if ((parent.GetPrevX() != point.GetX()) && (parent.GetPrevY() != point.GetY()))
							{
								// ���������� ��������������
								parent.SetTag(parent.GetTag() + 1);
								step++;
							}

							return true;
						}
						else
						{
							return false;
						}
					};

					// ��������� ��������� ������ �����
					if (((x < Axes::GetMaxForX() - 1) && (CheckFinish(map.at(Axes::ConvertToIndex(x + 1, y))) == true)) ||
					    ((y < Axes::GetMaxForY() - 1) && (CheckFinish(map.at(Axes::ConvertToIndex(x, y + 1))) == true)) ||
						((x > 0) && (CheckFinish(map.at(Axes::ConvertToIndex(x - 1, y))) == true)) ||
						((y > 0) && (CheckFinish(map.at(Axes::ConvertToIndex(x, y - 1))) == true)))
					{
						isFinished = true;
					}
				}
			}
		}

		step++;
		moveCheker--;
	} while (isFinished == false && moveCheker > 0);

	return isFinished;
}
bool PathFinder::FindNewFinish()
{
	if (step > 1)
	{
		int minX = finishX;
		int minY = finishY;
		int maxX = finishX;
		int maxY = finishY;

		// ����� ����������� ������� ����� � ������, ������� ����� �������
		do
		{
			for (int x = minX; x < maxX; x++)
			{
				for (int y = minY; y < maxY; y++)
				{
					TagAxes point = map.at(Axes::ConvertToIndex(x, y));
					if (point.GetTag() > 0)
					{
						finishX = point.GetX();;
						finishY = point.GetY();
						step = point.GetTag();

						return true;
					}
				}
			}
			if (minX > 0) { minX--; }
			if (minY > 0) { minY--; }
			if (maxX < Axes::GetMaxForX()) { maxX++; }
			if (maxY < Axes::GetMaxForY()) { maxY++; }
		} while ((minX > 0) || (minY >0) || (maxX < Axes::GetMaxForX()) || (maxY < Axes::GetMaxForY()));

		return false;
	}
	else
	{
		return false;
	}
}
std::vector<BaseAxes> PathFinder::CreateMoveMap()
{
	int x = finishX;
	int y = finishY;

	std::vector<BaseAxes> path;
	path.push_back(BaseAxes(x, y));

	// ������������ ������ ����� �� ������ �� ����
	do
	{
		int newStep = step;
		int newX = x;
		int newY = y;

		// ������� ������ ������������ ���� � �������� �������
		auto FindMinStep = [&](TagAxes &point)
		{
			if ((point.GetTag() >= 0) && (point.GetTag() < newStep))
			{
				newStep = point.GetTag();
				newX = point.GetX();
				newY = point.GetY();
			}
		};

		// ����� ������������ ���� � �������� �������
		if (x < Axes::GetMaxForX() - 1)
		{
			FindMinStep(map.at(Axes::ConvertToIndex(x + 1, y)));
		}
		if (y < Axes::GetMaxForY() - 1)
		{
			FindMinStep(map.at(Axes::ConvertToIndex(x, y + 1)));
		}
		if (x > 0)
		{
			FindMinStep(map.at(Axes::ConvertToIndex(x - 1, y)));
		}
		if (y > 0)
		{
			FindMinStep(map.at(Axes::ConvertToIndex(x, y - 1)));
		}

		// ���������� ����� ���������� � �������
		step = newStep;
		x = newX;
		y = newY;
		path.push_back(BaseAxes(x, y));
	} while (step != 0);

	// �������� ������
	std::reverse(std::begin(path), std::end(path));

	return path;
}
