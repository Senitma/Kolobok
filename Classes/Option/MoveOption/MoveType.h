#pragma once

// Тип перемещения
enum class MoveType
{
	// По смежным клеткам
	ToOneStep,
	// По прямой
	ToLine,
	// В обход препятствий
	ToByPass
};