#pragma once

#include "BaseVertex.h"
#include "Edge.h"

// Перечисление возможных направлений
enum SideType;

// Класс вершины
class Vertex : public BaseVertex
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
	Vertex(const int & x, const int & y) : Vertex(x, y, Vertex::EMPTYINDEX) {}
	// Инициализация переменных
	Vertex(const int & x, const int & y, const int & counter);

	// Получить счетчик поворота
	int GetSideCounter() const { return sideCounter; }
	// Изменить счетчик поворота
	void SetSideCounter(const int & value) { sideCounter = value; }
	// Получить вес
	int GetWeight() const { return weight; }
	// Изменить вес
	void SetWeight(const int & value) { weight = value; }
	// Получить направление
	SideType GetSide() { return side; }
	// Изменить направление
	void SetSide(const SideType & value) { side = value; }

	// Получить главное родительское ребро
	Edge & GetMainPrevEdge() { return mainPrevEdge; }
	// Получить главное родительское ребро
	Edge & GetAddPrevEdge() { return addPrevEdge; }

	// Получить левое ребро
	Edge & GetLeftEdge() { return leftEdge; }
	// Получить верхнее ребро
	Edge & GetUpEdge() { return upEdge; }
	// Получить правое ребро
	Edge & GetRightEdge() { return rightEdge; }
	// Получить нижнее ребро
	Edge & GetDownEdge() { return downEdge; }
private:
	// Счетчик поворота
	int sideCounter;
	// Вес
	int weight;
	// Направление
	SideType side;

	// Главное родительское ребро
	Edge mainPrevEdge;
	// Дополнительное родительское ребро
	Edge addPrevEdge;
	
	// Левое ребро
	Edge leftEdge;
	// Верхнее ребро
	Edge upEdge;
	// Правое ребро
	Edge rightEdge;
	// Нижнее ребро
	Edge downEdge;
};