#pragma once

// Перечисление возможных состояний игры
enum class GameStatusType
{
	// Нет результата
	None,
	// Выйгрыш
	Win,
	// Проигрыш
	Lose,
	// Игра в процессе
	Gaming
};
