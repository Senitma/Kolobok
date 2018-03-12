#pragma once

// Основные настройки приложения
class Settings
{
public:

#pragma region Настройки окна

	// Ширина окна
	static const int FIELDWIDTHSIZE = 1280;
	// Высота окна
	static const int FIELDHEIGHTSIZE = 960;
	// Переключатель FPS
	static const bool SHOWFPS = true;

	// Ширина прорисовки
	static const int NODEWIDTH = 64;
	// Высота прорисовки
	static const int NODEHEIGHT = 64;
	// Ширина ячейки
	static const int CELLWIDTHSIZE = 0;
	// Высота ячейки
	static const int CELLHEIGHTSIZE = 0;
	// Глубина ячейки
	static const int CELLDEPTHSIZE = 0;
	// Ширина зазора
	static const int GAPWIDTHSIZE = 0;
	// Высота зазора
	static const int GAPHEIGHTSIZE = 0;

#pragma endregion
#pragma region Настройки игры

	// количество клеток по горизонтали
	static int HORIZONTALCELLCOUNT;
	// Количество клеток по вертикали
	static int VERTICALCELLCOUNT;

	// Индекс карты для загрузки
	static int MAPINDEX;
	// Скорость перемещения персонажа
	static float MOVESPEED;
	// Скорость вращения персонажа
	static float ROTATESPEED;
	// Период создания снаряда
	static float CREATEFIREBALLINTERVAL;
	// Скорость снаряда
	static float FIREBALLSPEED;

#pragma endregion
};