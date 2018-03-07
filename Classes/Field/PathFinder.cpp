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
			// Поиск ближайшей точки к финишу
			return newPath.CreateMoveMap();
		}
		else
		{
			// Достигнута самая ближайшая точка к финишу
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

				// Функция для добавления новой точки на карте с учетом поворота
				auto AddStep = [&](TagAxes &point)
				{
					if (point.GetTag() == -1)
					{
						if ((parent.GetPrevX() != point.GetX()) && (parent.GetPrevY() != point.GetY()))
						{
							// Приходится поворачиваться
							point.SetTag(step + 2);
						}
						else
						{
							// Перемещение по прямой
							point.SetTag(step + 1);
						}

						point.SetPrevX(x);
						point.SetPrevY(y);
						moveCheker = MAXEMPTYMOVED;
					}
				};

				// Найти опорную точку для следующего шага
				if (parent.GetTag() == step)
				{
					// Отметить все свободные ячейки
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

					// Функция для поиска клетки финиша в соседних клетках
					auto CheckFinish = [&](TagAxes &point)
					{
						if (point.GetTag() == -2)
						{
							if ((parent.GetPrevX() != point.GetX()) && (parent.GetPrevY() != point.GetY()))
							{
								// Приходится поворачиваться
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

					// Проверить положение финиша рядом
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

		// Поиск максимально близкой точки к фииншу, которую можно достичь
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

	// Формирование набора точек от финиша до цели
	do
	{
		int newStep = step;
		int newX = x;
		int newY = y;

		// Функция поиска минимального шага в соседних клетках
		auto FindMinStep = [&](TagAxes &point)
		{
			if ((point.GetTag() >= 0) && (point.GetTag() < newStep))
			{
				newStep = point.GetTag();
				newX = point.GetX();
				newY = point.GetY();
			}
		};

		// Поиск минимального шага в соседних клетках
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

		// Добавление новой координаты в очередь
		step = newStep;
		x = newX;
		y = newY;
		path.push_back(BaseAxes(x, y));
	} while (step != 0);

	// Разворот набора
	std::reverse(std::begin(path), std::end(path));

	return path;
}
