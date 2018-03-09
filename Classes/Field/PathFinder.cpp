#include "PathFinder.h"
#include "TagAxes.h"
#include "Axes.h"

PathFinder::PathFinder(std::vector<TagAxes> & map)
{
	this->map = map;
}

bool PathFinder::CanMoveTo(std::vector<TagAxes> & map, const BaseAxes & start, const BaseAxes & finish)
{
	PathFinder newPath = PathFinder(map);
	newPath.SetStart(start);
	newPath.SetFinish(finish);

	return newPath.FindFinish(false);
}
std::vector<BaseAxes> PathFinder::MoveTo(std::vector<TagAxes> & map, const BaseAxes & start, const BaseAxes & finish, const bool & extendedCheck)
{
	// Функция создания карты для перемещения
	auto CreateMapAxes = [&](PathFinder path)
	{
		std::vector<BaseAxes> axesPath;

		if (extendedCheck == true)
		{
			path.Clear();
			path.FindFinish(true);
		}

		axesPath = path.CreateMoveMap();
		// Разворот набора
		std::reverse(axesPath.begin(), axesPath.end());

		if (extendedCheck == true)
		{
			std::vector<BaseAxes> reverseAxesPath;
			PathFinder reversePath = PathFinder(map);
			reversePath.SetStart(path.GetFinish());
			reversePath.SetFinish(path.GetStart());
			reversePath.Clear();

			reversePath.FindFinish(true);
			reverseAxesPath = reversePath.CreateMoveMap();

			if (path.GetStep() > reversePath.GetStep())
			{
				return reverseAxesPath;
			}
			else
			{
				return axesPath;
			}
		}
		else
		{
			return axesPath;
		}
	};

	PathFinder newPath = PathFinder(map);
	newPath.SetStart(start);
	newPath.SetFinish(finish);

	if (newPath.FindFinish(false) == true)
	{
		return CreateMapAxes(newPath);
	}
	else
	{
		// Поиск ближайшей точки к финишу
		if (newPath.FindNewFinish() == true)
		{
			return CreateMapAxes(newPath);
		}
		else
		{
			// Достигнута самая ближайшая точка к финишу
			return std::vector<BaseAxes>{ start };
		}
	}
}

BaseAxes PathFinder::GetStart() const
{
	return BaseAxes(startX, startY);
}

BaseAxes PathFinder::GetFinish() const
{
	return BaseAxes(finishX, finishY);
}

void PathFinder::SetStart(const BaseAxes & value)
{
	this->map.at(Axes::ConvertToIndex(value)).SetTag(0);
	startX = value.GetX();
	startY = value.GetY();
}

void PathFinder::SetFinish(const BaseAxes & value)
{
	this->map.at(Axes::ConvertToIndex(value)).SetTag(-2);
	finishX = value.GetX();
	finishY = value.GetY();
}

bool PathFinder::FindFinish(const bool & rotateCheck)
{
	// Функция для добавления новой точки на карте с учетом поворота
	auto AddStep = [&](const TagAxes & parent, const int & offsetX, const int & offsetY, const int & offsetStep)
	{
		TagAxes & child = GetChild(GetChild(parent, offsetX, 0), 0, offsetY);

		if (child.GetTag() == -1)
		{
			child.SetTag(step + offsetStep);
			return true;
		}
		else
		{
			return false;
		}
	};
	// Функция для поиска клетки финиша в соседних клетках
	auto CheckFinish = [&](TagAxes & parent, const int & offsetX, const int & offsetY)
	{
		TagAxes & child = GetChild(parent, offsetX, offsetY);

		if (child.GetTag() == -2)
		{
			return true;
		}
		else
		{
			return false;
		}
	};

	step = 0;
	int currentEmptyMove = 0;
	const int MAXEMPTYMOVE = 4;
	bool isFinished = false;

	do
	{
		std::all_of(map.begin(), map.end(), [&](TagAxes & item)
		{
			// Найти опорную точку для следующего шага
			if (item.GetTag() == step)
			{
				// Отметить все соседние свободные ячейки Неймана
				if ((AddStep(item, 1, 0, 1) | AddStep(item, 0, 1, 1) | AddStep(item, -1, 0, 1) | AddStep(item, 0, -1, 1)) == true)
				{
					currentEmptyMove = MAXEMPTYMOVE;
				}
				if (rotateCheck == true)
				{
					// Отметить все соседние свободные ячейки Мура
					if ((AddStep(item, 1, 1, 3) | AddStep(item, -1, 1, 3) | AddStep(item, 1, -1, 3) | AddStep(item, -1, -1, 3)) == true)
					{
						currentEmptyMove = MAXEMPTYMOVE;
					}
				}

				// Проверить наличие финиша рядом
				if ((CheckFinish(item, 1, 0) == true) ||
					((CheckFinish(item, 0, 1) == true) ||
					(CheckFinish(item, -1, 0) == true) ||
					(CheckFinish(item, 0, -1) == true)))
				{
					isFinished = true;
				}
			}

			return !isFinished;
		});
		step++;
		currentEmptyMove--;
	} while (isFinished == false && currentEmptyMove > 0);

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
	std::vector<BaseAxes> path;
	TagAxes prevAxes = TagAxes(finishX, finishY, step);
	BaseAxes prevPrevAxes = prevAxes;
	step = 0;

	// Формирование набора точек от финиша до цели
	while (prevAxes.GetTag() != 0)
	{
		TagAxes newAxes = TagAxes(0, 0, 0);
		int newStep = 0;

		// Добавление новой координаты в очередь
		path.push_back(BaseAxes(prevAxes));

		// Функция поиска нового шага рядом с клеткой
		auto FindMinStep = [&](const int & offsetX, const int & offsetY)
		{
			TagAxes & child = GetChild(prevAxes, offsetX, offsetY);

			// Пути по прямой в приоритете
			if ((child.GetTag() >= 0) && (child.GetTag() < prevAxes.GetTag()))
			{
				if ((child.GetX() == prevPrevAxes.GetX()) || (child.GetY() == prevPrevAxes.GetY()))
				{
					newAxes = child;
					newStep = 1;
				}
				else if (newAxes.GetTag() == 0)
				{
					newAxes = child;
					newStep = 2;
				}
			}
		};

		// Поиск нового шага рядом с клеткой
		FindMinStep(1, 0);
		FindMinStep(0, 1);
		FindMinStep(-1, 0);
		FindMinStep(0, -1);

		prevPrevAxes = prevAxes;
		prevAxes = newAxes;
		step += newStep;
	}
#pragma warning( default: "Убрать строку после переработки опций" )
	path.push_back(BaseAxes(prevAxes));

	return path;
}

TagAxes & PathFinder::GetChild(const TagAxes & parent, const int & offsetX, const int & offsetY)
{
	if ((offsetX == 1) && (parent.GetX() < Axes::GetMaxForX() - 1))
	{
		return map.at(Axes::ConvertToIndex(parent.GetX() + offsetX, parent.GetY() + offsetY));
	}
	else if ((offsetY == 1) && (parent.GetY() < Axes::GetMaxForY() - 1))
	{
		return map.at(Axes::ConvertToIndex(parent.GetX() + offsetX, parent.GetY() + offsetY));
	}
	else if ((offsetX == -1) && (parent.GetX() > 0))
	{
		return map.at(Axes::ConvertToIndex(parent.GetX() + offsetX, parent.GetY() + offsetY));
	}
	else if ((offsetY == -1) && (parent.GetY() > 0))
	{
		return map.at(Axes::ConvertToIndex(parent.GetX() + offsetX, parent.GetY() + offsetY));
	}
	else
	{
		return map.at(Axes::ConvertToIndex(parent.GetX(), parent.GetY()));
	}
}
void PathFinder::Clear()
{
	std::for_each(map.begin(), map.end(), [&](TagAxes & item)
	{
		if (item.GetTag() > 0)
		{
			item.SetTag(-1);
		}
	});
}
