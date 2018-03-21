#pragma once

// Перечисление возможных типов анимации
enum class AnimationType
{
	// Тип не задан
	None,
	// Анимация перемещения
	MoveToLeft,
	// Анимация перемещения
	MoveToUp,
	// Анимация перемещения
	MoveToRight,
	// Анимация перемещения
	MoveToDown,
	// Анимация поворота
	RotateLeftToUp,
	// Анимация поворота
	RotateUpToLeft,
	// Анимация поворота
	RotateUpToRight,
	// Анимация поворота
	RotateRightToUp,
	// Анимация поворота
	RotateRightToDown,
	// Анимация поворота
	RotateDownToRight,
	// Анимация поворота
	RotateDownToLeft,
	// Анимация поворота
	RotateLeftToDown
};