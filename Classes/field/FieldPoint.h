#pragma once

#include "headers.h"

// Класс точки
class FieldPoint : public cocos2d::Ref
{
public:
	// Инициализация переменных
	FieldPoint() { x = 0; y = 0; tag = 0; };
	// Инициализация переменных
	FieldPoint(int x, int y) { this->x = x, this->y = y, tag = 0; };
	// Инициализация переменных
	FieldPoint(int x, int y, int tag) { this->x = x, this->y = y, this->tag = tag; };
	// Получить координаты по оси X
	int GetX();
	// Задать координаты по оси X
	void SetX(int value) { this->x = value; };
	// Получить координаты по оси Y
	int GetY();
	// Задать координаты по оси и Y
	void SetY(int value) { this->y = value; };

	// Получить идентификатор
	int GetTag() { return tag; };
	// Изменить идентификатор
	void SetTag(int value) { tag = value; };

	// Конвертирование координаты X в отступ слева
	int ToLeft();
	// Конвертирование координаты Y в отступ сверху
	int ToTop();

	// Конвертирование отступа в координаты
	static int ConvertToX(int left);
	// Конвертирование отступа в координаты
	static int ConvertToY(int top);
	// Конвертирование отступов в координаты
	static FieldPoint * ConvertToXY(int left, int top);
	// Конвертирование координаты X в отступ слева
	static int ConvertToLeft(int x);
	// Конвертирование координаты Y в отступ сверху
	static int ConvertToTop(int y);

	// Получить ширину клетки
	static int GetCellWidth();
	// Получить высоту клетки
	static int GetCellHeight();
protected:
	// Положение по оси X
	int x;
	// Положение по оси Y
	int y;
	// Идентификатор
	int tag;
};