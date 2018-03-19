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

				if ((vertex.GetLeftNearEdge().GetSecondStatus() == true) && (vertex.GetLeftNearEdge().GetSecondVertex().GetCounter() == vertex.GetCounter()))
				{
					vertex.GetLeftNearEdge().GetSecondVertex().SetCounter(Vertex::EMPTYINDEX);
				}
				if ((vertex.GetUpNearEdge().GetSecondStatus() == true) && (vertex.GetUpNearEdge().GetSecondVertex().GetCounter() == vertex.GetCounter()))
				{
					vertex.GetUpNearEdge().GetSecondVertex().SetCounter(Vertex::EMPTYINDEX);
				}
				if ((vertex.GetRightNearEdge().GetSecondStatus() == true) && (vertex.GetRightNearEdge().GetSecondVertex().GetCounter() == vertex.GetCounter()))
				{
					vertex.GetRightNearEdge().GetSecondVertex().SetCounter(Vertex::EMPTYINDEX);
				}
				if ((vertex.GetDownNearEdge().GetSecondStatus() == true) && (vertex.GetDownNearEdge().GetSecondVertex().GetCounter() == vertex.GetCounter()))
				{
					vertex.GetDownNearEdge().GetSecondVertex().SetCounter(Vertex::EMPTYINDEX);
				}

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

	while (queue.size() != 0)
	{
		// Получить опорную точку для изменения счетчиков
		Vertex & item = vertexMap.at(AxesInfo::ConvertToIndex(queue.top().x, queue.top().y));
		queue.pop();

		if (step != item.GetCounter()) { step = item.GetCounter(); }

		// Отметить все соседние свободные ячейки Неймана
		if (AddCount(item.GetCounter(), item.GetLeftNearEdge()) |
			AddCount(item.GetCounter(), item.GetUpNearEdge()) |
			AddCount(item.GetCounter(), item.GetRightNearEdge()) |
			AddCount(item.GetCounter(), item.GetDownNearEdge()) == true)
		{

			// В случае нахождения клетки финиша выходим из функции
			return true;
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
	auto AddCount = [&](Vertex & first, Edge & next, const SideType & side)
	{
		if (next.GetSecondStatus() == true)
		{
			Vertex & second = next.GetSecondVertex();

			int newSide = second.GetSide() | side;
			int offset = 2;

			if ((first.GetX() == startX) && (first.GetY() == startY))
			{
				offset = 0;
			}
			else
			{
				switch (first.GetSide())
				{
					case SideType::Left:
						if (newSide & 2 == 2) { if (offset > 0) { offset = 0; } }
						if (newSide & 4 == 4) { if (offset > 1) { offset = 1; } }
						if (newSide & 16 == 16) { if (offset > 1) { offset = 1; } }
						break;
					case SideType::Up:
						if (newSide & 2 == 2) { if (offset > 1) { offset = 1; } }
						if (newSide & 4 == 4) { if (offset > 0) { offset = 0; } }
						if (newSide & 8 == 8) { if (offset > 1) { offset = 1; } }
						break;
					case SideType::Right:
						if (newSide & 4 == 4) { if (offset > 1) { offset = 1; } }
						if (newSide & 8 == 8) { if (offset > 0) { offset = 0; } }
						if (newSide & 16 == 16) { if (offset > 1) { offset = 1; } }
						break;
					case SideType::Down:
						if (newSide & 2 == 2) { if (offset > 1) { offset = 1; } }
						if (newSide & 8 == 8) { if (offset > 1) { offset = 1; } }
						if (newSide & 16 == 16) { if (offset > 0) { offset = 0; } }
						break;
					default:
						// Изменений не требуется
						break;
				}
			}

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
				second.SetSide((SideType)(second.GetSide() | first.GetSide()));
				second.GetAddPrevEdge().SetSecondVertex(first);

				//if (first.GetMainPrevEdge().GetSecondStatus() == true)
				//{
				//	if (first.GetMainPrevEdge().GetSecondVertex().GetX() == second.GetX() ||
				//		first.GetMainPrevEdge().GetSecondVertex().GetY() == second.GetY())
				//	{
				//		//if (second.GetX() != first.GetMainPrevEdge().GetSecondVertex().GetX() ||
				//		//	second.GetY() != first.GetMainPrevEdge().GetSecondVertex().GetY())
				//		//{
				//			second.GetProgenitor().SetSecondVertex(first.GetMainPrevEdge().GetSecondVertex());
				//		//}
				//	}
				//}
				//if (first.GetAddPrevEdge().GetSecondStatus() == true)
				//{
				//	if (first.GetAddPrevEdge().GetSecondVertex().GetX() == second.GetX() ||
				//		first.GetAddPrevEdge().GetSecondVertex().GetY() == second.GetY())
				//	{
				//		//if (second.GetX() != first.GetMainPrevEdge().GetSecondVertex().GetX() ||
				//		//	second.GetY() != first.GetMainPrevEdge().GetSecondVertex().GetY())
				//		//{
				//			second.GetProgenitor().SetSecondVertex(first.GetMainPrevEdge().GetSecondVertex());
				//		//}
				//	}
				//}
			}
		}
	};

	while (queue.size() != 0)
	{
		// Получить опорную точку для изменения счетчиков
		Vertex & item = vertexMap.at(AxesInfo::ConvertToIndex(queue.top().x, queue.top().y));
		queue.pop();

		AddCount(item, item.GetLeftNearEdge(), SideType::Left);
		AddCount(item, item.GetUpNearEdge(), SideType::Up);
		AddCount(item, item.GetRightNearEdge(), SideType::Right);
		AddCount(item, item.GetDownNearEdge(), SideType::Down);
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
	return CreateMoveMap(finishX, finishY, std::deque<Axes>());
}
std::deque<Axes> MoveByPass::CreateMoveMap(const int & finishX, const int & finishY, std::deque<Axes> path)
{
	auto CalcPath = [&](std::deque<Axes> oldPath, std::deque<Axes> newPath)
	{
		int result = 0;
		int prevX = oldPath.front().GetX();
		int prevY = oldPath.front().GetY();
		oldPath.pop_front();
		Axes point;
		int index = 0;

		if (oldPath.size() > 1)
		{
			for (int i = 0; i < oldPath.size() - 1; i++)
			{
				Axes & item = oldPath.at(i + 1);
				if ((item.GetX() != prevX) && (item.GetY() != prevY))
				{
					result++;
				}
				prevX = oldPath.at(i).GetX();
				prevY = oldPath.at(i).GetY();
			}
		}
		if (oldPath.size() > 0)
		{
			if ((newPath.front().GetX() != prevX) && (newPath.front().GetY() != prevY))
			{
				result++;
			}
			prevX = oldPath.back().GetX();
			prevY = oldPath.back().GetY();
		}

		if (newPath.size() > 1)
		{
			for (int i = 0; i < newPath.size() - 1; i++)
			{
				Axes & item = newPath.at(i + 1);
				if ((item.GetX() != prevX) && (item.GetY() != prevY))
				{
					result++;
				}
				prevX = newPath.at(i).GetX();
				prevY = newPath.at(i).GetY();
			}
		}

		return result;
	};

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

		if ((parent.GetAddPrevEdge().GetSecondStatus() == true) && (path.size() > 1))
		{
			if (parent.GetAddPrevEdge().GetSecondVertex().GetX() == prev2Axes.GetX() ||
				parent.GetAddPrevEdge().GetSecondVertex().GetY() == prev2Axes.GetY())
			{
				prevAxes = Axes(parent.GetAddPrevEdge().GetSecondVertex().GetX(), parent.GetAddPrevEdge().GetSecondVertex().GetY());
			}
			else
			{
				prevAxes = Axes(parent.GetMainPrevEdge().GetSecondVertex().GetX(), parent.GetMainPrevEdge().GetSecondVertex().GetY());
			}
		}
		else if ((parent.GetAddPrevEdge().GetSecondStatus() == true) && (path.size() == 1))
		{
			std::deque<Axes> firstPath = CreateMoveMap(parent.GetMainPrevEdge().GetSecondVertex().GetX(), parent.GetMainPrevEdge().GetSecondVertex().GetY(), path);
			std::deque<Axes> secondPath = CreateMoveMap(parent.GetAddPrevEdge().GetSecondVertex().GetX(), parent.GetAddPrevEdge().GetSecondVertex().GetY(), path);

			firstPath.push_back(Axes(startX, startY));
			secondPath.push_back(Axes(startX, startY));

			int x1 = CalcPath(path, firstPath);
			int x2 = CalcPath(path, secondPath);

			if (x1 == x2)
			{
				x1 += vertexMap.at(AxesInfo::ConvertToIndex(firstPath.at(firstPath.size() - 2))).GetWeight();
				x2 += vertexMap.at(AxesInfo::ConvertToIndex(secondPath.at(secondPath.size() - 2))).GetWeight();
			}

			if (x1 < x2)
			{
				while (firstPath.size() > 0)
				{
					path.push_back(firstPath.front());
					firstPath.pop_front();
				}
			}
			else
			{
				while (secondPath.size() > 0)
				{
					path.push_back(secondPath.front());
					secondPath.pop_front();
				}
			}

			path.pop_back();
			prevAxes = Axes(startX, startY);
		}
		else
		{
			prevAxes = Axes(parent.GetMainPrevEdge().GetSecondVertex().GetX(), parent.GetMainPrevEdge().GetSecondVertex().GetY());
		}
	}

	return path;
}
