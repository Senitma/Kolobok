#pragma once

// Настройки приложения
namespace Settings
{
#pragma region Настройки окна
	// Ширина окна
	const int WIDTHSIZE = 1280;
	// Высота окна
	const int HEIGHTSIZE = 960;
	// Переключатель FPS
	const bool SHOWFPS = true;
#pragma endregion
#pragma region Настройки игры

	// количество клеток по горизонтали
	const int HORIZONTALCELLCOUNT = 20;
	// Количество клеток по вертикали
	const int VERTICALCELLCOUNT = 15;
	// Индекс карты для загрузки
	const int MAPINDEX = 2;
	// Скорость перемещения персонажа
	const float MOVESPEED = 4;
	// Скорость вращения персонажа
	const float ROTATESPEED = 4;
	// Период создания снаряда
	const float CREATEFIREBALLINTERVAL = 120;
	// Скорость снаряда
	const float FIREBALLSPEED = 8;

#pragma endregion
}