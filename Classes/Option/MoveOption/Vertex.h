#pragma once

#include "vector"
#include "Edge.h"
#include "Field\Axes.h"

// Перечисление возможных направлений
enum SideType;

// Класс вершины
class Vertex : public Axes
{
public:
	// Значение клетки с блоком
	static const int BLOCKINDEX = -3;
	// Значение клетки финиша
	static const int FINISHINDEX = -2;
	// Значение пустой клетки
	static const int EMPTYINDEX = -1;
	// Значение клетки старта 
	static const int STARTINDEX = 0;

	// Инициализация переменных
	Vertex() : Vertex(0, 0, Vertex::EMPTYINDEX) {}
	// Инициализация переменных
	Vertex(const Axes & value) : Vertex(value.GetX(), value.GetY(), Vertex::EMPTYINDEX) {}
	// Инициализация переменных
	Vertex(const int & x, const int & y) : Vertex(x, y, Vertex::EMPTYINDEX) {}
	// Инициализация переменных
	Vertex(const int & x, const int & y, const int & counter);

	// Получить счетчик
	int GetCounter() const { return counter; }
	// Изменить счетчик
	void SetCounter(const int & value) { counter = value; }
	// Получить счетчик поворота
	int GetSideCounter() const { return sideCounter; }
	// Изменить счетчик поворота
	void SetSideCounter(const int & value) { sideCounter = value; }
	// Получить смещение счетчика
	int GetOffsetCounter() const { return offsetCounter; }
	// Изменить смещение счетчика
	void SetOffsetCounter(const int & value) { offsetCounter = value; }
	// Получить вес
	int GetWeight() const { return weight; }
	// Изменить вес
	void SetWeight(const int & value) { weight = value; }

	// Получить главное предыдущее ребро
	Edge & GetMainPrevEdge() { return mainPrevEdge; }
	// Получить главное предыдущее ребро
	Edge & GetAddPrevEdge() { return addPrevEdge; }
	// Получить правродителя
	Edge & GetProgenitor() { return progenitor; }

	// Получить направление вершины
	SideType GetSide() { return side; }
	// Изменить направление вершины
	void SetSide(const SideType & value) { side = value; }

	// Получить левое ближнее ребро
	Edge & GetLeftNearEdge() { return leftNearEdge; }
	// Получить верхнее ближнее ребро
	Edge & GetUpNearEdge() { return upNearEdge; }
	// Получить правое ближнее ребро
	Edge & GetRightNearEdge() { return rightNearEdge; }
	// Получить нижнее ближнее ребро
	Edge & GetDownNearEdge() { return downNearEdge; }

	// Получить левое дальнее ребро
	Edge & GetLeftFarEdge() { return leftFarEdge; }
	// Получить верхнее дальнее ребро
	Edge & GetUpFarEdge() { return upFarEdge; }
	// Получить правое дальнее ребро
	Edge & GetRightFarEdge() { return rightFarEdge; }
	// Получить нижнее дальнее ребро
	Edge & GetDownFarEdge() { return downFarEdge; }
private:
	// Счетчик
	int counter;
	// Счетчик поворота
	int sideCounter;
	// Смещение счетчика
	int offsetCounter;
	// Вес
	int weight;

	SideType side;

	// Главное предыдущее ребро
	Edge mainPrevEdge;
	// Дополнительное предыдущее ребро
	Edge addPrevEdge;
	// Прародительское ребро
	Edge progenitor;
	
	// Левое ближнее ребро
	Edge leftNearEdge;
	// Верхнее ближнее ребро
	Edge upNearEdge;
	// Правое ближнее ребро
	Edge rightNearEdge;
	// Нижнее ближнее ребро
	Edge downNearEdge;

	// Левое дальнее ребро
	Edge leftFarEdge;
	// Верхнее дальнее ребро
	Edge upFarEdge;
	// Правое дальнее ребро
	Edge rightFarEdge;
	// Нижнее дальнее ребро
	Edge downFarEdge;
};