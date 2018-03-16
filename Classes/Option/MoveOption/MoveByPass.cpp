#include "algorithm"

#include "Field\Vertex.h"
#include "Field\AxesInfo.h"
#include "Field\Field.h"
#include "Settings.h"

#include "MoveByPass.h"

MoveByPass::MoveByPass() : MoveByPass(Field::CreateBlockMap()) {}
MoveByPass::MoveByPass(const std::vector<Vertex> & map)
{
	step = 0;
	startX = 0;
	startY = 0;
	finishX = 0;
	finishY = 0;

	this->map = map;
}

bool MoveByPass::CanMoveTo(const Axes & start, const Axes & finish)
{
	MoveByPass newPath = MoveByPass();
	newPath.SetStart(start);
	newPath.SetFinish(finish);

	return newPath.FindFinish(false);
}
std::queue<Axes> MoveByPass::MoveTo(const Axes & start, const Axes & finish, const bool & extendedCheck)
{
	// Функция создания карты для перемещения
	auto CreateMapAxes = [&](MoveByPass path)
	{
		std::deque<Axes> axesPath;

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
			MoveByPass reversePath = MoveByPass(path.GetMap());
			reversePath.SetStart(path.GetFinish());
			reversePath.SetFinish(path.GetStart());
			reversePath.Clear();

			reversePath.FindFinish(true);
			std::deque<Axes> reverseAxesPath;
			reverseAxesPath = reversePath.CreateMoveMap();

			if (path.GetStep() > reversePath.GetStep())
			{
				return std::queue<Axes>(reverseAxesPath);
			}
			else
			{
				return std::queue<Axes>(axesPath);
			}
		}
		else
		{
			return std::queue<Axes>(axesPath);
		}
	};

	MoveByPass newPath = MoveByPass();
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
			auto nullResult = std::queue<Axes>();
			nullResult.push(start);
			return nullResult;
		}
	}
}

Axes MoveByPass::GetStart() const
{
	return Axes(startX, startY);
}
Axes MoveByPass::GetFinish() const
{
	return Axes(finishX, finishY);
}
void MoveByPass::SetStart(const Axes & value)
{
	map.at(AxesInfo::ConvertToIndex(value)).SetPathCounter(0);
	//map.at(AxesInfo::ConvertToIndex(value)).SetEmpty(true);
	startX = value.GetX();
	startY = value.GetY();
}
void MoveByPass::SetFinish(const Axes & value)
{
	map.at(AxesInfo::ConvertToIndex(value)).SetPathCounter(-2);
	finishX = value.GetX();
	finishY = value.GetY();
}

bool MoveByPass::FindFinish(const bool & rotateCheck)
{
	// Функция для добавления новой точки на карте с учетом поворота
	auto AddStep = [&](const Vertex & parent, const int & offsetX, const int & offsetY, const int & offsetStep, const bool & empty)
	{
		Vertex & child = GetChild(GetChild(parent, offsetX, 0), 0, offsetY);

		if (child.GetPathCounter() == -1)
		{
			child.SetPathCounter(step + offsetStep);
			//child.SetEmpty(child.GetEmpty() | empty);
			return true;
		}
		else if (child.GetPathCounter() > step)
		{
			//child.SetEmpty(child.GetEmpty() | empty);
			return false;
		}
		else
		{
			return false;
		}
	};
	// Функция для поиска клетки финиша в соседних клетках
	auto CheckFinish = [&](Vertex & parent, const int & offsetX, const int & offsetY)
	{
		Vertex & child = GetChild(parent, offsetX, offsetY);

		if (child.GetPathCounter() == -2)
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
	const int MAXEMPTYMOVE = 3;
	bool isFinished = false;

	do
	{
		std::all_of(map.begin(), map.end(), [&](Vertex & item)
		{
			// Найти опорную точку для следующего шага
			if (item.GetPathCounter() == step)
			{
				//if (item.GetEmpty() == false)
				//{
				//	item.SetPathCounter(-1);
				//}
				//else
				{
					// Отметить все соседние свободные ячейки Неймана
					if ((AddStep(item, 1, 0, 1, true) | AddStep(item, 0, 1, 1, true) | AddStep(item, -1, 0, 1, true) | AddStep(item, 0, -1, 1, true)) == true)
					{
						currentEmptyMove = MAXEMPTYMOVE;
					}
					if (rotateCheck == true)
					{
						// Отметить все соседние свободные ячейки Мура
						if ((AddStep(item, 1, 1, 3, false) | AddStep(item, -1, 1, 3, false) | AddStep(item, 1, -1, 3, false) | AddStep(item, -1, -1, 3, false)) == true)
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
			}

			return !isFinished;
		});
		step++;
		currentEmptyMove--;
	} while (isFinished == false && currentEmptyMove > 0);

	return isFinished;
}
bool MoveByPass::FindNewFinish()
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
					Vertex point = map.at(AxesInfo::ConvertToIndex(x, y));
					if (point.GetPathCounter() > 0)
					{
						finishX = point.GetX();;
						finishY = point.GetY();
						step = point.GetPathCounter();

						return true;
					}
				}
			}
			if (minX > 0) { minX--; }
			if (minY > 0) { minY--; }
			if (maxX < Settings::HORIZONTALCELLCOUNT) { maxX++; }
			if (maxY < Settings::VERTICALCELLCOUNT) { maxY++; }
		} while ((minX > 0) || (minY > 0) || (maxX < Settings::HORIZONTALCELLCOUNT) || (maxY < Settings::VERTICALCELLCOUNT));

		return false;
	}
	else
	{
		return false;
	}
}
std::deque<Axes> MoveByPass::CreateMoveMap()
{
	std::deque<Axes> path;
	Vertex prevAxes = Vertex(finishX, finishY, step);
	Axes prevPrevAxes = prevAxes;
	step = 0;

	// Формирование набора точек от финиша до цели
	while (prevAxes.GetPathCounter() != 0)
	{
		Vertex newAxes = Vertex(0, 0, 0);
		int newStep = 0;

		// Добавление новой координаты в очередь
		path.push_back(Axes(prevAxes));

		// Функция поиска нового шага рядом с клеткой
		auto FindMinStep = [&](const int & offsetX, const int & offsetY)
		{
			Vertex & child = GetChild(prevAxes, offsetX, offsetY);

			// Пути по прямой в приоритете
			if ((child.GetPathCounter() >= 0) && (child.GetPathCounter() < prevAxes.GetPathCounter()))
			{
				if ((child.GetX() == prevPrevAxes.GetX()) || (child.GetY() == prevPrevAxes.GetY()))
				{
					newAxes = child;
					newStep = 1;
				}
				else if (newAxes.GetPathCounter() == 0)
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

	return path;
}

Vertex & MoveByPass::GetChild(const Vertex & parent, const int & offsetX, const int & offsetY)
{
	if ((offsetX == 1) && (parent.GetX() < Settings::HORIZONTALCELLCOUNT - 1))
	{
		return map.at(AxesInfo::ConvertToIndex(parent.GetX() + offsetX, parent.GetY() + offsetY));
	}
	else if ((offsetY == 1) && (parent.GetY() < Settings::VERTICALCELLCOUNT - 1))
	{
		return map.at(AxesInfo::ConvertToIndex(parent.GetX() + offsetX, parent.GetY() + offsetY));
	}
	else if ((offsetX == -1) && (parent.GetX() > 0))
	{
		return map.at(AxesInfo::ConvertToIndex(parent.GetX() + offsetX, parent.GetY() + offsetY));
	}
	else if ((offsetY == -1) && (parent.GetY() > 0))
	{
		return map.at(AxesInfo::ConvertToIndex(parent.GetX() + offsetX, parent.GetY() + offsetY));
	}
	else
	{
		return map.at(AxesInfo::ConvertToIndex(parent.GetX(), parent.GetY()));
	}
}
void MoveByPass::Clear()
{
	std::for_each(map.begin(), map.end(), [&](Vertex & item)
	{
		if (item.GetPathCounter() > 0)
		{
			item.SetPathCounter(-1);
			//item.SetEmpty(false);
		}
	});
}
