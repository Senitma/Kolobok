#pragma once

// Класс координат
struct Axes;

// Класс информации для координат
class AxesInfo
{
public:

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

};