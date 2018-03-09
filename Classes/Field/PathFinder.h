#pragma once

#include "vector"

//Базовый класс всех координат
class BaseAxes;
// Класс координат с идентификатором
class TagAxes;
// Класс поиска оптимального пути
class PathFinder
{
public:
	// Инициализация переменных
	PathFinder(std::vector<TagAxes> & map);

	// Проверка возможности дойти до финиша
	static bool CanMoveTo(std::vector<TagAxes> & map, const BaseAxes & start, const BaseAxes & finish);
	// Получить маршрут точек до финиша
	static std::vector<BaseAxes> MoveTo(std::vector<TagAxes> & map, const BaseAxes & start, const BaseAxes & finish, const bool & extendedCheck);
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
	BaseAxes GetStart() const;
	// Получить координаты финиша
	BaseAxes GetFinish() const;
	// Изменить координаты старта
	void SetStart(const BaseAxes & value);
	// Изменить координаты финиша
	void SetFinish(const BaseAxes & value);

	// Проложить маршрут до финиша
	bool FindFinish(const bool & rotateCheck);
	// Найти ближайшую точку к финишу 
	bool FindNewFinish();
	// Сформировать набор точек для перемещения
	std::vector<BaseAxes> CreateMoveMap();

	// Получить ссылку на соседнюю клетку
	TagAxes & GetChild(const TagAxes & parent, const int & offsetX, const int & offsetY);
	// Удалить расчеты с карты
	void Clear();
};