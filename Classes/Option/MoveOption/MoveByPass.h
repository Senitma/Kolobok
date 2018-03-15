#pragma once

#include "vector"
#include "deque"
#include "queue"

//Базовый класс всех координат
class Axes;
// Класс координат с идентификатором
class TagAxes;

// Класс поиска оптимального пути
class MoveByPass
{
public:
	// Инициализация переменных
	MoveByPass();
	// Инициализация переменных
	MoveByPass(const std::vector<TagAxes> & map);

	// Получить карту для прохождения
	const std::vector<TagAxes> & GetMap() const { return map; };

	// Проверка возможности дойти до финиша
	static bool CanMoveTo(const Axes & start, const Axes & finish);
	// Получить маршрут точек до финиша
	static std::queue<Axes> MoveTo(const Axes & start, const Axes & finish, const bool & extendedCheck);
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
	// Карта для прохождения
	std::vector<TagAxes> map;

	// Получить количество шагов
	int GetStep() const { return step; };
	// Получить координаты старта
	Axes GetStart() const;
	// Получить координаты финиша
	Axes GetFinish() const;
	// Изменить координаты старта
	void SetStart(const Axes & value);
	// Изменить координаты финиша
	void SetFinish(const Axes & value);

	// Проложить маршрут до финиша
	bool FindFinish(const bool & rotateCheck);
	// Найти ближайшую точку к финишу 
	bool FindNewFinish();
	// Сформировать набор точек для перемещения
	std::deque<Axes> CreateMoveMap();

	// Получить ссылку на соседнюю клетку
	TagAxes & GetChild(const TagAxes & parent, const int & offsetX, const int & offsetY);
	// Удалить расчеты с карты
	void Clear();
};