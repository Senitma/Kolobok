#pragma once

#include "Vertex.h"

class Vertex;
// Ребро
struct Edge
{
public:
	// Инициализация переменных
	Edge() : secondStatus(false) {}

	// Получить статус второй вершины
	bool GetSecondStatus() const { return secondStatus; }
	// Получить ссылку на вторую вершину
	Vertex & GetSecondVertex() const { return *secondVertex; }
	// Изменить ссылку на вторую вершину
	void SetSecondVertex(Vertex & value) { secondVertex = &value; secondStatus = true; }
private:
	// Вторая вершина
	Vertex * secondVertex;
	// Статус второй вершины
	bool secondStatus;
};