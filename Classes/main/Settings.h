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
	const int MAPINDEX = 0;

#pragma endregion
}