#pragma once

#include "vector"
#include "deque"
#include "queue"

// Координаты элемента
struct Axes;
// Класс вершины
class Vertex;
// Структура ссылки на вершину
struct RefVertex;
// Обратная структура ссылки на вершину
struct ReverseRefVertex;
// Перечисление возможных направлений
enum SideType;

// Класс поиска оптимального пути
class MoveByPass
{
public:
	// Инициализация переменных
	MoveByPass();
	// Инициализация переменных
	MoveByPass(const std::vector<Vertex> & map);

	// Проверка возможности дойти до финиша
	static bool CanMoveTo(const Axes & start, const Axes & finish);
	// Получить маршрут точек до финиша
	static std::queue<Axes> MoveTo(const Axes & start, const SideType & side, const Axes & finish);
private:
	// Количество пройденных шагов
	int step;
	// Координаты старта по оси X
	int startX;
	// Координаты старта по оси Y
	int startY;
	// Координаты финиша по оси X
	int finishX;
	// Координаты финиша по оси Y
	int finishY;
	// Направление старта
	SideType side;
	// Карта для прохождения
	std::vector<Vertex> vertexMap;

	// Получить количество шагов
	int GetStep() const { return step; };
	//// Изменить координаты старта
	void SetStart(const Axes & value, SideType side);
	//// Изменить координаты старта
	void SetStart(const Axes & value);
	//// Изменить координаты финиша
	void SetFinish(const Axes & value);

	// Проложить маршрут до финиша
	bool FindFinish();
	// Добавить приоритет выбора прямого пути
	void AddLinePathPreoritety();
	// Найти ближайшую точку к финишу 
	bool FindNewFinish();
	// Сформировать набор точек для перемещения
	std::deque<Axes> CreateMoveMap();
	// Сформировать набор точек для перемещения
	std::deque<Axes> CreateMoveMap(const int & finishX, const int & finishY, std::deque<Axes> path);
};