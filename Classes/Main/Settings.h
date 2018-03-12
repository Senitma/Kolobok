#pragma once

// Основные настройки приложения
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
	extern int HORIZONTALCELLCOUNT;
	// Количество клеток по вертикали
	extern int VERTICALCELLCOUNT;

	// Индекс карты для загрузки
	extern int MAPINDEX;
	// Скорость перемещения персонажа
	extern float MOVESPEED;
	// Скорость вращения персонажа
	extern float ROTATESPEED;
	// Период создания снаряда
	extern float CREATEFIREBALLINTERVAL;
	// Скорость снаряда
	extern float FIREBALLSPEED;

#pragma endregion
};