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

	// Ширина прорисовки
	const int NODEWIDTH = 64;
	// Высота прорисовки
	const int NODEHEIGHT = 64;
	// Ширина ячейки
	const int CELLWIDTHSIZE = 0;
	// Высота ячейки
	const int CELLHEIGHTSIZE = 0;
	// Глубина ячейки
	const int CELLDEPTHSIZE = 0;
	// Ширина зазора
	const int GAPWIDTHSIZE = 0;
	// Высота зазора
	const int GAPHEIGHTSIZE = 0;

#pragma endregion
#pragma region Настройки игры

	// количество клеток по горизонтали
	extern const int & HORIZONTALCELLCOUNT;
	// Количество клеток по вертикали
	extern const int & VERTICALCELLCOUNT;

	// Карта для загрузки по умолчанию
	const MapIndexType DEFAULTMAP = MapIndexType::Empty;

	// Скорость перемещения персонажа
	const float MOVESPEED = 4;
	// Скорость вращения персонажа
	const float ROTATESPEED = 4;
	// Период создания снаряда
	const float CREATEFIREBALLINTERVAL = 120;
	// Скорость снаряда
	const float FIREBALLSPEED = 8;

#pragma endregion
};