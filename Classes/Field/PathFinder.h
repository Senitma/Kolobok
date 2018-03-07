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
	PathFinder(std::vector<TagAxes> & map, const BaseAxes & start, const BaseAxes & finish);

	// Проверка возможности дойти до финиша
	static bool CanMoveTo(std::vector<TagAxes> & map, const BaseAxes & start, const BaseAxes & finish);
	// Получить маршрут точек до финиша
	static std::vector<BaseAxes> MoveTo(std::vector<TagAxes> & map, const BaseAxes & start, const BaseAxes & finish);
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

	// Проложить маршрут до финиша
	bool FindFinish();
	// Найти ближайшую точку к финишу 
	bool FindNewFinish();
	// Сформировать набор точек для перемещения
	std::vector<BaseAxes> CreateMoveMap();
};