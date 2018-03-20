#include "algorithm"

#include "BaseVertex.h"
#include "Vertex.h"
#include "Element\SideType.h"
#include "Field\Axes.h"
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
	BaseVertex::SetMaxX(Settings::HORIZONTALCELLCOUNT);

	// Функция для добавления дочерних ребер
	auto AddChild = [&](const bool & Condition, Edge & edge, const int & childX, const int & childY) 
	{
		if (Condition == true)
		{
			Vertex &child = vertexMap.at(BaseVertex::GetIndex(childX, childY));
			if (child.GetCounter() != Vertex::BLOCKINDEX)
			{
				edge.SetVertex(child);
			}
		}
	};

	// Заполнение дочерних ребер
	std::for_each(vertexMap.begin(), vertexMap.end(), [&](Vertex & item)
	{
		AddChild(item.GetX() > 0, item.GetLeftEdge(), item.GetX() - 1, item.GetY());
		AddChild(item.GetY() > 0, item.GetUpEdge(), item.GetX(), item.GetY() - 1);
		AddChild(item.GetX() < Settings::HORIZONTALCELLCOUNT - 1, item.GetRightEdge(), item.GetX() + 1, item.GetY());
		AddChild(item.GetY() < Settings::VERTICALCELLCOUNT - 1, item.GetDownEdge(), item.GetX(), item.GetY() + 1);
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
		if (value.GetEnable() == true)
		{
			value.SetWeight(value.GetWeight() + offsetWeight);
		}
	};

	SetStart(value);
	this->side = side;

	// Добавление веса каждой из сторон

	Vertex & parent = vertexMap.at(BaseVertex::GetIndex(startX, startY));
	parent.SetSide(side);
	switch (side)
	{
		case Left:
			MarkCount(parent.GetUpEdge(), 1);
			MarkCount(parent.GetRightEdge(), 2);
			MarkCount(parent.GetDownEdge(), 1);
			break;
		case Up:
			MarkCount(parent.GetLeftEdge(), 1);
			MarkCount(parent.GetRightEdge(), 1);
			MarkCount(parent.GetDownEdge(), 2);
			break;
		case Right:
			MarkCount(parent.GetLeftEdge(), 2);
			MarkCount(parent.GetUpEdge(), 1);
			MarkCount(parent.GetDownEdge(), 1);
			break;
		case Down:
			MarkCount(parent.GetLeftEdge(), 1);
			MarkCount(parent.GetUpEdge(), 2);
			MarkCount(parent.GetRightEdge(), 1);
			break;
		default:
			// Изменений не требуется
			break;
	}
}
void MoveByPass::SetStart(const Axes & value)
{
	vertexMap.at(BaseVertex::GetIndex(value.GetX(), value.GetY())).SetCounter(Vertex::STARTINDEX);
	vertexMap.at(BaseVertex::GetIndex(value.GetX(), value.GetY())).SetSideCounter(Vertex::STARTINDEX);
	startX = value.GetX();
	startY = value.GetY();
}
void MoveByPass::SetFinish(const Axes & value)
{
	vertexMap.at(BaseVertex::GetIndex(value.GetX(), value.GetY())).SetCounter(Vertex::FINISHINDEX);
	finishX = value.GetX();
	finishY = value.GetY();
}

bool MoveByPass::FindFinish()
{
	// Инициализация переменных
	step = Vertex::STARTINDEX;
	std::priority_queue<BaseVertex> queue;
	queue.push(BaseVertex(startX, startY, step));

	// Функция для изменения счетчика
	auto AddCount = [&](const int & parentCounter, Edge & value)
	{
		if (value.GetEnable() == true)
		{
			Vertex & vertex = value.GetVertex();

			if (vertex.GetCounter() == Vertex::FINISHINDEX)
			{
				queue.push(BaseVertex(vertex.GetX(), vertex.GetY(), parentCounter + vertex.GetWeight()));
				vertex.SetCounter(parentCounter + vertex.GetWeight());
				return true;
			}
			else if (vertex.GetCounter() == Vertex::EMPTYINDEX)
			{
				queue.push(BaseVertex(vertex.GetX(), vertex.GetY(), parentCounter + vertex.GetWeight()));
				vertex.SetCounter(parentCounter + vertex.GetWeight());
			}
		}

		return false;
	};

	while (queue.empty() == false)
	{
		// Получить опорную точку для изменения счетчиков
		Vertex & item = vertexMap.at(queue.top().GetIndex());
		queue.pop();

		if (step != item.GetCounter()) { step = item.GetCounter(); }

		// Отметить все соседние свободные ячейки Неймана
		if (AddCount(item.GetCounter(), item.GetLeftEdge()) |
			AddCount(item.GetCounter(), item.GetUpEdge()) |
			AddCount(item.GetCounter(), item.GetRightEdge()) |
			AddCount(item.GetCounter(), item.GetDownEdge()) == true)
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
	std::priority_queue<BaseVertex> queue;
	queue.push(BaseVertex(startX, startY, step));

	// Функция для изменения счетчика с двумя вершинами
	auto AddCount = [&](Vertex & first, Edge & next, const SideType & side)
	{
		if (next.GetEnable() == true)
		{
			Vertex & second = next.GetVertex();

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
				queue.push(BaseVertex(second.GetX(), second.GetY(), weight));
				second.SetSideCounter(weight);
				second.GetMainPrevEdge().SetVertex(first);
				second.SetSide(side);
			}
			else if (second.GetSideCounter() > weight)
			{
				queue.push(BaseVertex(second.GetX(), second.GetY(), weight));
				second.SetSideCounter(weight);
				second.GetMainPrevEdge().SetVertex(first);
				second.SetSide(side);
			}
			else if (second.GetSideCounter() == weight)
			{
				second.SetSide((SideType)(second.GetSide() | first.GetSide()));
				second.GetAddPrevEdge().SetVertex(first);
			}
		}
	};

	while (queue.empty() == false)
	{
		// Получить опорную точку для изменения счетчиков
		Vertex & item = vertexMap.at(queue.top().GetIndex());
		queue.pop();

		AddCount(item, item.GetLeftEdge(), SideType::Left);
		AddCount(item, item.GetUpEdge(), SideType::Up);
		AddCount(item, item.GetRightEdge(), SideType::Right);
		AddCount(item, item.GetDownEdge(), SideType::Down);
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
	// Функция для расчета стоимости пути
	auto CalcPath = [&](std::deque<Axes> path)
	{
		int result = 0;
		int prevX = path.front().GetX();
		int prevY = path.front().GetY();
		path.pop_front();
		Axes point;
		int index = 0;

		if (path.size() > 1)
		{
			for (int i = 0; i < path.size() - 1; i++)
			{
				Axes & item = path.at(i + 1);
				if ((item.GetX() != prevX) && (item.GetY() != prevY))
				{
					result++;
				}
				prevX = path.at(i).GetX();
				prevY = path.at(i).GetY();
			}
		}

		return result;
	};

	Axes axes = Axes(finishX, finishY);
	Axes prevAxes;

	// Формирование набора точек от финиша до цели
	while ((axes.GetX() != startX) || (axes.GetY() != startY))
	{
		if (path.size() > 0)
		{
			prevAxes = Axes(path.back().GetX(), path.back().GetY());
		}
		
		// Добавление новой координаты в очередь
		path.push_back(axes);
		
		Vertex & parent = vertexMap.at(BaseVertex::GetIndex(axes.GetX(), axes.GetY()));

		// Расчет оптимального маршрута на развилке
		if ((parent.GetAddPrevEdge().GetEnable() == true) && (path.size() > 1))
		{
			if (parent.GetAddPrevEdge().GetX() == prevAxes.GetX() ||
				parent.GetAddPrevEdge().GetY() == prevAxes.GetY())
			{
				axes = Axes(parent.GetAddPrevEdge().GetX(), parent.GetAddPrevEdge().GetY());
			}
			else
			{
				axes = Axes(parent.GetMainPrevEdge().GetX(), parent.GetMainPrevEdge().GetY());
			}
		}
		// Расчет оптимального маршрута невозможен, т.к. недостаточно данных. просчет каждого из маршрутов
		else if ((parent.GetAddPrevEdge().GetEnable() == true) && (path.size() == 1))
		{
			std::deque<Axes> firstPath = CreateMoveMap(parent.GetMainPrevEdge().GetX(), parent.GetMainPrevEdge().GetY(), path);
			std::deque<Axes> secondPath = CreateMoveMap(parent.GetAddPrevEdge().GetX(), parent.GetAddPrevEdge().GetY(), path);

			firstPath.push_back(Axes(startX, startY));
			secondPath.push_back(Axes(startX, startY));

			int x1 = CalcPath(firstPath);
			int x2 = CalcPath(secondPath);

			if (x1 == x2)
			{
				x1 += vertexMap.at(BaseVertex::GetIndex(firstPath.at(firstPath.size() - 2).GetX(), firstPath.at(firstPath.size() - 2).GetY())).GetWeight();
				x2 += vertexMap.at(BaseVertex::GetIndex(secondPath.at(secondPath.size() - 2).GetX(), secondPath.at(secondPath.size() - 2).GetY())).GetWeight();
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
			axes = Axes(startX, startY);
		}
		else
		{
			axes = Axes(parent.GetMainPrevEdge().GetX(), parent.GetMainPrevEdge().GetY());
		}
	}

	return path;
}

// Сравнение двух базвых вершин
bool operator<(const BaseVertex & left, const BaseVertex & right)
{ 
	return left.GetCounter() > right.GetCounter(); 
}