#pragma once

#include "Main\Maps.h"

// Модуль настроек приложения
namespace Settings
{
#pragma region Настройки окна

	// Ширина окна
	const int FIELDWIDTHSIZE = 1280;
	// Высота окна
	const int FIELDHEIGHTSIZE = 960;
	// Переключатель FPS
	const bool SHOWFPS = true;
	// FPS
	const float FPS = 60;

	// Ширина прорисовки
	const int NODEWIDTH = 128;
	// Высота прорисовки
	const int NODEHEIGHT = 128;
	// Ширина ячейки
	const int CELLWIDTH = 128;
	// Высота ячейки
	const int CELLHEIGHT = 70;

#pragma endregion
#pragma region Настройки игры

	// Смещение изображения по оси X
	extern const int & OFFSETX;
	// Смещение изображения по оси Y
	extern const int & OFFSETY;

	// количество клеток по горизонтали
	extern const int & HORIZONTALCELLCOUNT;
	// Количество клеток по вертикали
	extern const int & VERTICALCELLCOUNT;

	// Карта для загрузки по умолчанию
	const MapIndexType DEFAULTMAP = MapIndexType::Example;

	// Скорость перемещения персонажа
	const float MOVESPEED = 3.1F;
	// Скорость вращения персонажа
	const float ROTATESPEED = 4.5F;
	// Период создания снаряда
	const float CREATEFIREBALLINTERVAL = 240.0F;
	// Скорость снаряда
	const float FIREBALLSPEED = 5.0F;

#pragma endregion
};