#pragma once

#include "FieldAxes.h"

// Класс настройки координат на поле
class FieldAxesSettings : FieldAxes
{
public:
	// Изменить размер ширины узла
	static void SetNodeWidth(const int &value) { nodeWidth = value; };
	// Изменить размер высоты узла
	static void SetNodeHeight(const int &value) { nodeHeight = value;; };
	// Изменить размер ширины клетки
	static void SetCellWidth(const int &value) { cellWidth = value; };
	// Изменить размер высоты клетки
	static void SetCellHeight(const int &value) { cellHeight = value; };
	// Изменить размер глубины клетки
	static void SetCellDepth(const int &value) { cellDepth = value; };
	// Изменить размер ширины поля
	static void SetFieldWidth(const int &value) { fieldWidth = value; };
	// Изменить размер высоты поля
	static void SetFieldHeight(const int &value) { fieldHeight = value; };
	// Изменить размер ширины зазора
	static void SetGapWidth(const int &value) { gapWidth = value; };
	// Изменить размер высоты зазора
	static void SetGapHeight(const int &value) { gapHeight = value; };
};