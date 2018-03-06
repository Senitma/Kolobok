#pragma once

#include "TagAxes.h"
#include "vector"

// Класс поиска оптимального пути
class PathFinder
{
public:
	// Инициализация переменных
	PathFinder(std::vector<TagAxes> blockMap) { map = blockMap; };
	// Проверка возможности дойти до финиша
	static bool CanMoveTo(int startX, int startY, int finishX, int finishY, std::vector<TagAxes> blockMap);
	// Получить маршрут точек до финиша
	static std::vector<TagAxes> MoveTo(int startX, int startY, int finishX, int finishY, std::vector<TagAxes> blockMap);
private:
	// Количество пройденных шагов
	int step;
	// Координаты финиша по оси X
	int finishX;
	// Координаты финиша по оси Y
	int finishY;
	// Карта для прохождения
	std::vector<TagAxes> map;

	// Проложить маршрут до финиша
	bool FindFinish(int startX, int startY);
	// Сформировать набор точек для перемещения
	std::vector<TagAxes> CreateMoveMap();

	// Сформировать индекс из координат
	static int GetIndex(int x, int y);
};