#pragma once

// Перечисление возможных типов
enum ClassType;
// Класс координат
struct Axes;

// Информация для координат
namespace AxesInfo
{
	// Конвертирование координат в индекс
	int ConvertToIndex(const Axes & value);
	// Конвертирование координат в индекс
	int ConvertToIndex(const int &x, const int &y);
	// Конвертирование индекса в координаты
	Axes ConvertToAxes(const int &value);
	// Конвертировать смещения в координаты
	Axes ConvertToAxes(const int &left, const int &top);
	// Конвертировать координаты в смещения
	Axes ConvertToOffset(const ClassType & type, const int & x, const int & y);

	extern int ANGLE;
};