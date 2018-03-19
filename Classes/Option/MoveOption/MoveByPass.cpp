#include "algorithm"

#include "RefVertex.h"
#include "Vertex.h"
#include "Element\SideType.h"
#include "Field\Axes.h"
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
	side = SideType::None;

	vertexMap = map;

	// Заполнение соседних вершин
	std::for_each(vertexMap.begin(), vertexMap.end(), [&](Vertex & item)
	{
		if ((item.GetX() > 0) && (vertexMap.at(AxesInfo::ConvertToIndex(item.GetX() - 1, item.GetY())).GetCounter() != Vertex::BLOCKINDEX))
		{
			item.GetLeftNearEdge().SetSecondVertex(vertexMap.at(AxesInfo::ConvertToIndex(item.GetX() - 1, item.GetY())));
			if ((item.GetX() > 1) && (vertexMap.at(AxesInfo::ConvertToIndex(item.GetX() - 2, item.GetY())).GetCounter() != Vertex::BLOCKINDEX))
			{
				item.GetLeftFarEdge().SetSecondVertex(vertexMap.at(AxesInfo::ConvertToIndex(item.GetX() - 2, item.GetY())));
			}
		}
		if ((item.GetY() > 0) && (vertexMap.at(AxesInfo::ConvertToIndex(item.GetX(), item.GetY() - 1)).GetCounter() != Vertex::BLOCKINDEX))
		{
			item.GetUpNearEdge().SetSecondVertex(vertexMap.at(AxesInfo::ConvertToIndex(item.GetX(), item.GetY() - 1)));
			if ((item.GetY() > 1) && (vertexMap.at(AxesInfo::ConvertToIndex(item.GetX(), item.GetY() - 2)).GetCounter() != Vertex::BLOCKINDEX))
			{
				item.GetUpFarEdge().SetSecondVertex(vertexMap.at(AxesInfo::ConvertToIndex(item.GetX(), item.GetY() - 2)));
			}
		}
		if ((item.GetX() < Settings::HORIZONTALCELLCOUNT - 1) && (vertexMap.at(AxesInfo::ConvertToIndex(item.GetX() + 1, item.GetY())).GetCounter() != Vertex::BLOCKINDEX))
		{
			item.GetRightNearEdge().SetSecondVertex(vertexMap.at(AxesInfo::ConvertToIndex(item.GetX() + 1, item.GetY())));
			if ((item.GetX() < Settings::HORIZONTALCELLCOUNT - 2) && (vertexMap.at(AxesInfo::ConvertToIndex(item.GetX() + 2, item.GetY())).GetCounter() != Vertex::BLOCKINDEX))
			{
				item.GetRightFarEdge().SetSecondVertex(vertexMap.at(AxesInfo::ConvertToIndex(item.GetX() + 2, item.GetY())));
			}
		}
		if ((item.GetY() < Settings::VERTICALCELLCOUNT - 1) && (vertexMap.at(AxesInfo::ConvertToIndex(item.GetX(), item.GetY() + 1)).GetCounter() != Vertex::BLOCKINDEX))
		{
			item.GetDownNearEdge().SetSecondVertex(vertexMap.at(AxesInfo::ConvertToIndex(item.GetX(), item.GetY() + 1)));
			if ((item.GetY() < Settings::VERTICALCELLCOUNT - 2) && (vertexMap.at(AxesInfo::ConvertToIndex(item.GetX(), item.GetY() + 2)).GetCounter() != Vertex::BLOCKINDEX))
			{
				item.GetDownFarEdge().SetSecondVertex(vertexMap.at(AxesInfo::ConvertToIndex(item.GetX(), item.GetY() + 2)));
			}
		}
	});
}

bool MoveByPass::CanMoveTo(const Axes & start, const Axes & finish)
{
	MoveByPass newPath = MoveByPass();
	newPath.SetStart(start);
	newPath.SetFinish(finish);

	return newPath.FindFinish();
}
std::queue<Axes> MoveByPass::MoveTo(const Axes & start, const SideType & side, const Axes & finish)
{
	// Функция создания карты для перемещения
	auto CreateMapAxes = [&](MoveByPass & path)
	{
		path.AddLinePathPreoritety();

		std::deque<Axes> axesPath;
		axesPath = path.CreateMoveMap();

		// Разворот набора
		std::reverse(axesPath.begin(), axesPath.end());
		return std::queue<Axes>(axesPath);
	};

	MoveByPass newPath = MoveByPass();
	newPath.SetStart(start, side);
	newPath.SetFinish(finish);

	if (newPath.FindFinish() == true)
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
void MoveByPass::SetStart(const Axes & value, SideType side)
{
	// Функция для заполнения счетчика
	auto MarkCount = [&](Edge & value, const int & offsetWeight)
	{
		if (value.GetSecondStatus() == true)
		{
			value.GetSecondVertex().SetWeight(value.GetSecondVertex().GetWeight() + offsetWeight);
		}
	};

	SetStart(value);
	this->side = side;

	// Добавление веса каждой из сторон

	Vertex & parent = vertexMap.at(AxesInfo::ConvertToIndex(startX, startY));
	parent.SetSide(side);
	switch (side)
	{
		case Left:
			MarkCount(parent.GetUpNearEdge(), 1);
			MarkCount(parent.GetRightNearEdge(), 2);
			MarkCount(parent.GetDownNearEdge(), 1);
			break;
		case Up:
			MarkCount(parent.GetLeftNearEdge(), 1);
			MarkCount(parent.GetRightNearEdge(), 1);
			MarkCount(parent.GetDownNearEdge(), 2);
			break;
		case Right:
			MarkCount(parent.GetLeftNearEdge(), 2);
			MarkCount(parent.GetUpNearEdge(), 1);
			MarkCount(parent.GetDownNearEdge(), 1);
			break;
		case Down:
			MarkCount(parent.GetLeftNearEdge(), 1);
			MarkCount(parent.GetUpNearEdge(), 2);
			MarkCount(parent.GetRightNearEdge(), 1);
			break;
		default:
			// Изменений не требуется
			break;
	}
}
void MoveByPass::SetStart(const Axes & value)
{
	vertexMap.at(AxesInfo::ConvertToIndex(value)).SetCounter(Vertex::STARTINDEX);
	vertexMap.at(AxesInfo::ConvertToIndex(value)).SetSideCounter(Vertex::STARTINDEX);
	startX = value.GetX();
	startY = value.GetY();
}
void MoveByPass::SetFinish(const Axes & value)
{
	vertexMap.at(AxesInfo::ConvertToIndex(value)).SetCounter(Vertex::FINISHINDEX);
	finishX = value.GetX();
	finishY = value.GetY();
}

bool MoveByPass::FindFinish()
{
	// Инициализация переменных
	step = Vertex::STARTINDEX;
	std::priority_queue<RefVertex> queue;
	queue.push(RefVertex(startX, startY, step));

	// Функция для изменения счетчика
	auto AddCount = [&](const int & parentCounter, Edge & value)
	{
		if (value.GetSecondStatus() == true)
		{
			Vertex & vertex = value.GetSecondVertex();

			if (vertex.GetCounter() == Vertex::FINISHINDEX)
			{
				queue.push(RefVertex(vertex.GetX(), vertex.GetY(), parentCounter + vertex.GetWeight()));
				vertex.SetCounter(parentCounter + vertex.GetWeight());
				return true;
			}
			else if (vertex.GetCounter() == Vertex::EMPTYINDEX)
			{
				queue.push(RefVertex(vertex.GetX(), vertex.GetY(), parentCounter + vertex.GetWeight())); 
				vertex.SetCounter(parentCounter + vertex.GetWeight());
			}
		}

		return false;
	};

	auto CheckFinish = [&](Edge & value)
	{
		if (value.GetSecondStatus() == true)
		{
			if (value.GetSecondVertex().GetCounter() == Vertex::FINISHINDEX)
			{
				return true;
			}
		}

		return false;
	};

	while (queue.size() != 0)
	{
		// Получить опорную точку для изменения счетчиков
		Vertex & item = vertexMap.at(AxesInfo::ConvertToIndex(queue.top().x, queue.top().y));
		queue.pop();

		if (item.GetCounter() != step) { step = item.GetCounter(); }

		if (CheckFinish(item.GetLeftNearEdge()) == true |
			CheckFinish(item.GetUpNearEdge()) == true |
			CheckFinish(item.GetRightNearEdge()) == true |
			CheckFinish(item.GetDownNearEdge()) == true)
		{
			if ((item.GetLeftNearEdge().GetSecondStatus() == true) && (item.GetLeftNearEdge().GetSecondVertex().GetCounter() == item.GetCounter()))
			{
				item.GetLeftNearEdge().GetSecondVertex().SetCounter(Vertex::EMPTYINDEX);
			}
			if ((item.GetUpNearEdge().GetSecondStatus() == true) && (item.GetUpNearEdge().GetSecondVertex().GetCounter() == item.GetCounter()))
			{
				item.GetUpNearEdge().GetSecondVertex().SetCounter(Vertex::EMPTYINDEX);
			}
			if ((item.GetRightNearEdge().GetSecondStatus() == true) && (item.GetRightNearEdge().GetSecondVertex().GetCounter() == item.GetCounter()))
			{
				item.GetRightNearEdge().GetSecondVertex().SetCounter(Vertex::EMPTYINDEX);
			}
			if ((item.GetDownNearEdge().GetSecondStatus() == true) && (item.GetDownNearEdge().GetSecondVertex().GetCounter() == item.GetCounter()))
			{
				item.GetDownNearEdge().GetSecondVertex().SetCounter(Vertex::EMPTYINDEX);
			}

			// В случае нахождения клетки финиша выходим из функции
			return true;
		}

		// Отметить все соседние свободные ячейки Неймана
		if (AddCount(item.GetCounter(), item.GetLeftNearEdge()) |
			AddCount(item.GetCounter(), item.GetUpNearEdge()) |
			AddCount(item.GetCounter(), item.GetRightNearEdge()) |
			AddCount(item.GetCounter(), item.GetDownNearEdge()) == true)
		{

		}
	}

	// Клетка финиша недоступна
	return false;
}
void MoveByPass::AddLinePathPreoritety()
{
	// Инициализация переменных
	step = Vertex::STARTINDEX;
	std::priority_queue<RefVertex> queue;
	queue.push(RefVertex(startX, startY, step));

	// Функция для изменения счетчика с двумя вершинами
	auto AddCount = [&](Vertex & first, Edge & next, const int & offset, const SideType & side)
	{
		if (next.GetSecondStatus() == true)
		{
			Vertex & second = next.GetSecondVertex();
			// Расчет веса ребра
			int weight = first.GetSideCounter() + offset;

			if ((second.GetSideCounter() == Vertex::EMPTYINDEX) && (second.GetCounter() != Vertex::EMPTYINDEX))
			{
				queue.push(RefVertex(second.GetX(), second.GetY(), weight));
				second.SetSideCounter(weight);
				second.GetMainPrevEdge().SetSecondVertex(first);

				if (first.GetAddPrevEdge().GetSecondStatus() == true)
				{
					if (first.GetAddPrevEdge().GetSecondVertex().GetX() == second.GetX() ||
						first.GetAddPrevEdge().GetSecondVertex().GetY() == second.GetY())
					{
						second.GetProgenitor().SetSecondVertex(first.GetAddPrevEdge().GetSecondVertex());
					}
					else
					{
						second.GetProgenitor().SetSecondVertex(first.GetMainPrevEdge().GetSecondVertex());
					}
				}
				else
				{
					if (first.GetMainPrevEdge().GetSecondStatus() == true)
					{
						second.GetProgenitor().SetSecondVertex(first.GetMainPrevEdge().GetSecondVertex());
					}
				}

				second.SetSide(side);
			}
			else if (second.GetSideCounter() > weight)
			{
				queue.push(RefVertex(second.GetX(), second.GetY(), weight));
				second.SetSideCounter(weight);
				second.GetMainPrevEdge().SetSecondVertex(first);

				if (first.GetAddPrevEdge().GetSecondStatus() == true)
				{
					if (first.GetAddPrevEdge().GetSecondVertex().GetX() == second.GetX() ||
						first.GetAddPrevEdge().GetSecondVertex().GetY() == second.GetY())
					{
						second.GetProgenitor().SetSecondVertex(first.GetAddPrevEdge().GetSecondVertex());
					}
					else
					{
						second.GetProgenitor().SetSecondVertex(first.GetMainPrevEdge().GetSecondVertex());
					}
				}
				else
				{
					if (first.GetMainPrevEdge().GetSecondStatus() == true)
					{
						second.GetProgenitor().SetSecondVertex(first.GetMainPrevEdge().GetSecondVertex());
					}
				}

				second.SetSide(side);
			}
			else if (second.GetSideCounter() == weight)
			{
				second.SetSide(SideType::None);
				second.GetAddPrevEdge().SetSecondVertex(first);

				if (first.GetMainPrevEdge().GetSecondStatus() == true)
				{
					if (first.GetMainPrevEdge().GetSecondVertex().GetX() == second.GetX() ||
						first.GetMainPrevEdge().GetSecondVertex().GetY() == second.GetY())
					{
						second.GetProgenitor().SetSecondVertex(first.GetMainPrevEdge().GetSecondVertex());
					}
				}
				if (first.GetAddPrevEdge().GetSecondStatus() == true)
				{
					if (first.GetAddPrevEdge().GetSecondVertex().GetX() == second.GetX() ||
						first.GetAddPrevEdge().GetSecondVertex().GetY() == second.GetY())
					{
						second.GetProgenitor().SetSecondVertex(first.GetAddPrevEdge().GetSecondVertex());
					}
				}
			}
		}
	};

	// Получить опорную точку для изменения счетчиков
	Vertex & item = vertexMap.at(AxesInfo::ConvertToIndex(queue.top().x, queue.top().y));
	queue.pop();

	AddCount(item, item.GetLeftNearEdge(), 0, SideType::Left);
	AddCount(item, item.GetUpNearEdge(), 0, SideType::Up);
	AddCount(item, item.GetRightNearEdge(), 0, SideType::Right);
	AddCount(item, item.GetDownNearEdge(), 0, SideType::Down);

	while (queue.size() != 0)
	{
		// Получить опорную точку для изменения счетчиков
		Vertex & item = vertexMap.at(AxesInfo::ConvertToIndex(queue.top().x, queue.top().y));
		queue.pop();

		int leftOffset = 0;
		int upOffset = 0;
		int rightOffset = 0;
		int downOffset = 0;

		switch (item.GetSide())
		{
			case SideType::Left:
				upOffset = 2;
				rightOffset = 4;
				downOffset = 2;
				break;
			case SideType::Up:
				leftOffset = 2;
				rightOffset = 2;
				downOffset = 4;
				break;
			case SideType::Right:
				leftOffset = 4;
				upOffset = 2;
				downOffset = 2;
				break;
			case SideType::Down:
				leftOffset = 2;
				upOffset = 4;
				rightOffset = 2;
				break;
			default:
				// 0
				break;
		}

		AddCount(item, item.GetLeftNearEdge(), leftOffset, SideType::Left);
		AddCount(item, item.GetUpNearEdge(), upOffset, SideType::Up);
		AddCount(item, item.GetRightNearEdge(), rightOffset, SideType::Right);
		AddCount(item, item.GetDownNearEdge(), downOffset, SideType::Down);
	}
}
bool MoveByPass::FindNewFinish()
{
	if (step == 0)
	{
		// Элемент заперт, идти некуда
		return false;
	}
	// За начало берется стартовая точка
	int minX = startX;
	int minY = startY;
	double minDelta = sqrt(pow(startX - finishX, 2) + pow(startY - finishY, 2));

	// Поиск максимально близкой точки к фииншу, которую можно достичь
	std::for_each(vertexMap.begin(), vertexMap.end(), [&](const Vertex & item) 
	{
		if (item.GetCounter() > 0)
		{
			// Вычисление расстояния между двумя координатами
			double calcDelta = sqrt(pow(item.GetX() - finishX, 2) + pow(item.GetY() - finishY, 2));
			if (calcDelta < minDelta)
			{
				minDelta = calcDelta;
				minX = item.GetX();
				minY = item.GetY();
			}
		}
	});

	if (minX == startX && minY == startY)
	{
		// Элемент уже находится на ближайшей точке
		return false;
	}
	else
	{
		finishX = minX;
		finishY = minY;

		return true;
	}
}
std::deque<Axes> MoveByPass::CreateMoveMap()
{
	std::deque<Axes> path;
	Axes prevAxes = Axes(finishX, finishY);
	Axes prev2Axes;

	// Формирование набора точек от финиша до цели
	while ((prevAxes.GetX() != startX) || (prevAxes.GetY() != startY))
	{
		if (path.size() > 0)
		{
			prev2Axes = Axes(path.back().GetX(), path.back().GetY());
		}
		
		// Добавление новой координаты в очередь
		path.push_back(prevAxes);
		
		Vertex & parent = vertexMap.at(AxesInfo::ConvertToIndex(prevAxes.GetX(), prevAxes.GetY()));

		if (parent.GetMainPrevEdge().GetSecondVertex().GetAddPrevEdge().GetSecondStatus() == true)
		{
			path.push_back(Axes(parent.GetMainPrevEdge().GetSecondVertex().GetX(), parent.GetMainPrevEdge().GetSecondVertex().GetY()));
			prevAxes = Axes(parent.GetProgenitor().GetSecondVertex().GetX(), parent.GetProgenitor().GetSecondVertex().GetY());
		}
		else
		{
			if ((parent.GetAddPrevEdge().GetSecondStatus() == true) && (path.size() > 0))
			{
				Vertex & parent2 = vertexMap.at(AxesInfo::ConvertToIndex(prev2Axes.GetX(), prev2Axes.GetY()));
				if (parent2.GetProgenitor().GetSecondStatus() == true)
				{
					prevAxes = Axes(parent2.GetProgenitor().GetSecondVertex().GetX(), parent2.GetProgenitor().GetSecondVertex().GetY());
				}
				else
				{
					prevAxes = Axes(parent.GetMainPrevEdge().GetSecondVertex().GetX(), parent.GetMainPrevEdge().GetSecondVertex().GetY());
				}
			}
			else
			{
				prevAxes = Axes(parent.GetMainPrevEdge().GetSecondVertex().GetX(), parent.GetMainPrevEdge().GetSecondVertex().GetY());
			}
		}
	}

	return path;
}
