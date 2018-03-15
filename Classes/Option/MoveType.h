#pragma once

// Перечисление возможных типов перемещения
enum class MoveType
{
	// Не задан
	None,
	// По смежным клеткам
	ToOneStep,
	// По прямой
	ToLine,
	// В обход препятствий
	ToByPass
};