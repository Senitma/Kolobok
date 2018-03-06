#pragma once

#include "TagAxes.h"

// Класс поиска оптимального пути
class PathFinder : private cocos2d::Ref
{
public:
	// Проверка возможности дойти до финиша
	static bool CanMoveTo(int startX, int startY, int finishX, int finishY, cocos2d::Vector<TagAxes *> blockMap);
	// Получить маршрут точек до финиша
	static cocos2d::Vector<TagAxes *> MoveTo(int startX, int startY, int finishX, int finishY, cocos2d::Vector<TagAxes *> blockMap);
private:
	// Количество пройденных шагов
	int step;
	// Координаты финиша по оси X
	int finishX;
	// Координаты финиша по оси Y
	int finishY;

	// Проложить маршрут до финиша
	bool FindFinish(int startX, int startY, cocos2d::Vector<TagAxes *> blockMap);
	// Сформировать набор точек для перемещения
	cocos2d::Vector<TagAxes *> CreateMoveMap(cocos2d::Vector<TagAxes *> blockMap);

	// Сформировать индекс из координат
	static int GetIndex(int x, int y);
};