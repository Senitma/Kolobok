#include "PathFinder.h"
#include "Main\Settings.h"

bool PathFinder::CanMoveTo(int startX, int startY, int finishX, int finishY, std::vector<TagAxes> blockMap)
{
	blockMap.at(GetIndex(startX, startY)).SetTag(0);
	blockMap.at(GetIndex(finishX, finishY)).SetTag(-2);
	PathFinder * newPath = new PathFinder(blockMap);

	if (newPath->FindFinish(startX, startY) == true)
	{
		return true;
	}
	else
	{
		return false;
	}
}
std::vector<TagAxes> PathFinder::MoveTo(int startX, int startY, int finishX, int finishY, std::vector<TagAxes> blockMap)
{
	blockMap.at(GetIndex(startX, startY)).SetTag(0);
	blockMap.at(GetIndex(finishX, finishY)).SetTag(-2);
	PathFinder * newPath = new PathFinder(blockMap);

	if (newPath->FindFinish(startX, startY) == true)
	{
		return newPath->CreateMoveMap();
	}
	else
	{
		if (newPath->step > 1)
		{
			TagAxes newFinish = TagAxes(finishX, finishY);
			bool isFind = false;
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
						if (blockMap.at(GetIndex(x, y)).GetTag() > 0)
						{
							newFinish = blockMap.at(GetIndex(x, y));
							isFind = true;
						}
					}
				}
				if (minX > 0)
				{
					minX--;
				}
				if (minY > 0)
				{
					minY--;
				}
				if (maxX < Settings::HORIZONTALCELLCOUNT)
				{
					maxX++;
				}
				if (maxY < Settings::VERTICALCELLCOUNT)
				{
					maxY++;
				}
			} while (isFind == false);

			newPath->finishX = newFinish.GetX();
			newPath->finishY = newFinish.GetY();
			newPath->step = newFinish.GetTag();

			return newPath->CreateMoveMap();
		}
		else
		{
			std::vector<TagAxes> noPath;
			noPath.push_back(TagAxes(startX, startY));
			return noPath;
		}
	}
}

bool PathFinder::FindFinish(int startX, int startY)
{
	bool isFinished = false;
	bool isMoved;

	step = 0;

	do
	{
		isMoved = false;
		for (int x = 0; x < Settings::HORIZONTALCELLCOUNT; x++)
		{
			for (int y = 0; y < Settings::VERTICALCELLCOUNT; y++)
			{
				// Найти опорную точку для следующего шага
				if (map.at(GetIndex(x,y)).GetTag() == step)
				{
					// Пометить все свободные ячейки как размер шага + 1
					if (x != Settings::HORIZONTALCELLCOUNT - 1)
					{
						if (map.at(GetIndex(x + 1, y)).GetTag() == -1)
						{
							map.at(GetIndex(x + 1, y)).SetTag(step + 1);
							isMoved = true;
						}
					}
					if (y != Settings::VERTICALCELLCOUNT - 1)
					{
						if (map.at(GetIndex(x, y + 1)).GetTag() == -1)
						{
							map.at(GetIndex(x, y + 1)).SetTag(step + 1);
							isMoved = true;
						}
					}
					if (x != 0)
					{
						if (map.at(GetIndex(x - 1, y)).GetTag() == -1)
						{
							map.at(GetIndex(x - 1, y)).SetTag(step + 1);
							isMoved = true;
						}
					}
					if (y != 0)
					{
						if (map.at(GetIndex(x, y - 1)).GetTag() == -1)
						{
							map.at(GetIndex(x, y - 1)).SetTag(step + 1);
							isMoved = true;
						}
					}
						
					// Проверить положение финиша рядом
					if (x < Settings::HORIZONTALCELLCOUNT - 1)
					{
						if (map.at(GetIndex(x + 1, y)).GetTag() == -2)
						{
							finishX = x + 1;
							finishY = y;
							isFinished = true;
						}
					}
					if (y < Settings::VERTICALCELLCOUNT - 1)
					{
						if (map.at(GetIndex(x, y + 1)).GetTag() == -2)
						{
							finishX = x;
							finishY = y + 1;
							isFinished = true;
						}
					}
					if (x > 0)
					{
						if (map.at(GetIndex(x - 1, y)).GetTag() == -2)
						{
							finishX = x - 1;
							finishY = y;
							isFinished = true;
						}
					}
					if (y > 0)
					{
						if (map.at(GetIndex(x, y - 1)).GetTag() == -2)
						{
							finishX = x;
							finishY = y - 1;
							isFinished = true;
						}
					}
				}
			}
		}
		step++;
	} while (isFinished == false && isMoved == true);

	return isFinished;
}
std::vector<TagAxes> PathFinder::CreateMoveMap()
{
	int x = finishX;
	int y = finishY;

	std::vector<TagAxes> path;
	path.push_back(TagAxes(x, y));

	// Формирование набора точек от финиша до цели
	do
	{
		// Для предотвращения ходьбы лесенкой проверяется только одна точка за раз
		if ((x < Settings::HORIZONTALCELLCOUNT - 1) && (map.at(GetIndex(x + 1, y)).GetTag() == step - 1))
		{
			path.push_back(map.at(GetIndex(x + 1, y)));
			step--;
			x++;
		}
		else if ((y < Settings::VERTICALCELLCOUNT - 1) && (map.at(GetIndex(x, y + 1)).GetTag() == step - 1))
		{
			path.push_back(map.at(GetIndex(x, y + 1)));
			step--;
			y++;
		}
		else if ((x > 0) && (map.at(GetIndex(x - 1, y)).GetTag() == step - 1))
		{
			path.push_back(map.at(GetIndex(x - 1, y)));
			step--;
			x--;
		}
		else if ((y > 0) && (map.at(GetIndex(x, y - 1)).GetTag() == step - 1))
		{
			path.push_back(map.at(GetIndex(x, y - 1)));
			step--;
			y--;
		}
	} while (step != 0);

	std::vector<TagAxes> result;
	// Разворот набора
	for (int index = path.size() - 1; index >= 0; index--)
	{
		result.push_back(path.at(index));
	}

	return result;
}

int PathFinder::GetIndex(int x, int y)
{
	if (y * Settings::HORIZONTALCELLCOUNT + x >= 300)
	{
		return 0;
	}

	return y * Settings::HORIZONTALCELLCOUNT + x;
}
