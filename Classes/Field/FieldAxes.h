#pragma once

#include "Axes.h"

// Класс координат на поле
class FieldAxes : public Axes
{
public:
	// Инициализация переменных
	FieldAxes() : FieldAxes(0, 0) {};
	// Инициализация переменных
	FieldAxes(const int &x, const int &y) : Axes(x, y) {};

	// Получить оригинальное положение по оси X
	int GetOriginalX() const { return originalX; };
	// Получить оригинальное положение по оси Y
	int GetOriginalY() const { return originalY; };
	// Получить переключатель выхода за границы поля 
	bool GetOutsideStatus() const { return CheckOutside(); };

	// Изменить положение по оси X
	void SetX(const int &value) override;
	// Изменить положение по оси Y
	void SetY(const int &value) override;

	// Конвертировать положение по оси X в смещение слева
	int ToLeft() const { return ConvertToLeft(x); };
	// Конвертировать положение по оси Y в смещение сверху
	int ToTop() const { return ConvertToLeft(y); };
	// Конвертировать координаты в вектор
	cocos2d::Vec2 ToVec2() const { ConvertToVec2(x, y); };

	// Конвертировать смещения в координаты
	static int ConvertToX(const int &value);
	// Конвертировать смещения в координаты
	static int ConvertToY(const int &value);
	// Конвертировать смещения в координаты
	static FieldAxes ConvertToXY(const int &left, const int &top) { return FieldAxes(ConvertToX(left), ConvertToY(top)); };
	// Конвертировать координаты в вектор
	static cocos2d::Vec2 ConvertToVec2(const int &x, const int &y);
	// Конвертировать координаты X в смещение слева
	static int ConvertToLeft(const int &value);
	// Конвертировать координаты Y в смещение сверху
	static int ConvertToTop(const int &value);

	// Получить размер ширины узла
	static int GetNodeWidth() { return nodeWidth; };
	// Получить размер высоты узла
	static int GetNodeHeight() { return nodeHeight; };
	// Получить размер ширины клетки
	static int GetCellWidth() { return cellWidth; };
	// Получить размер высоты клетки
	static int GetCellHeight() { return cellHeight; };
	// Получить размер глубины клетки
	static int GetCellDepth() { return cellDepth; };
	// Получить размер ширины поля
	static int GetFieldWidth() { return fieldWidth; };
	// Получить размер высоты поля
	static int GetFieldHeight() { return fieldHeight; };
	// Получить размер ширины зазора
	static int GetGapWidth() { return gapWidth; };
	// Получить размер высоты зазора
	static int GetGapHeight() { return gapHeight; };
protected:
	// Ширина узла
	static int nodeWidth;
	// Высота узла
	static int nodeHeight;
	// Ширина клетки
	static int cellWidth;
	// Высота клетки
	static int cellHeight;
	// Глубина клетки
	static int cellDepth;
	// Ширина поля
	static int fieldWidth;
	// Высота поля
	static int fieldHeight;
	// Ширина зазора
	static int gapWidth;
	// Высота зазора
	static int gapHeight;
private:
	// Неизмененное положение по оси X
	int originalX;
	// Неизмененное положение по оси Y
	int originalY;

	// Проверить выход за край поля
	bool CheckOutside() const;
};