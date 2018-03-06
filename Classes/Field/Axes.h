#pragma once

#include "BaseAxes.h"

// Класс для расчетов и хранения настроек координат
class Axes
{
public:
	// Получить максимальное положение по оси X
	static int GetMaxForX() { return maxForX; };
	// Получить максимальное положение по оси Y
	static int GetMaxForY() { return maxForY; };
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

	// Конвертирование координат в индекс
	static int ConvertToIndex(const int &x, const int &y) { return y * maxForX + x; };
	// Конвертирование индекса в координаты
	static BaseAxes ConvertToXY(const int &value);

	// Конвертировать смещения в координаты
	static int ConvertToX(const int &value);
	// Конвертировать смещения в координаты
	static int ConvertToY(const int &value);
	// Конвертировать смещения в координаты
	static BaseAxes ConvertToXY(const int &left, const int &top) { return BaseAxes(ConvertToX(left), ConvertToY(top)); };
	// Конвертировать координаты X в смещение слева
	static int ConvertToLeft(const int &value);
	// Конвертировать координаты Y в смещение сверху
	static int ConvertToTop(const int &value);
protected:
	// Максимальное положение по оси X
	static int maxForX;
	// Максимальное положение по оси Y
	static int maxForY;

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
};