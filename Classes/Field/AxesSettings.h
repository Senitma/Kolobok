#pragma once

#include "Axes.h"

// Класс настроек координат
class AxesSettings : Axes
{
	// Изменить максимальное положение по оси X
	static void SetMaxForX(const int &value) { maxForX = value; };
	// Изменить максимальное положение по оси Y
	static void SetMaxForY(const int &value) { maxForY = value; };
};