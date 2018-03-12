#pragma once

// Класс координат
class Axes;
// Класс информации для координат
class AxesInfo
{
public:
	// Получить максимальное положение по оси X
	static int GetMaxX();
	// Получить максимальное положение по оси Y
	static int GetMaxY();

	// Конвертирование координат в индекс
	static int ConvertToIndex(const Axes & value);
	// Конвертирование координат в индекс
	static int ConvertToIndex(const int &x, const int &y);
	// Конвертировать смещения в координаты
	static int ConvertToX(const int &value);
	// Конвертировать смещения в координаты
	static int ConvertToY(const int &value);
	// Конвертирование индекса в координаты
	static Axes ConvertToAxes(const int &value);
	// Конвертировать смещения в координаты
	static Axes ConvertToAxes(const int &left, const int &top);
	// Конвертировать координаты X в смещение слева
	static int ConvertToLeft(const int &value);
	// Конвертировать координаты Y в смещение сверху
	static int ConvertToTop(const int &value);
private:
	// Получить ширину поля
	static int GetFieldWidth();
	// Получить высота поля
	static int GetFieldHeight();
};