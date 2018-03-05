#pragma once

// Тип элемента
enum class ClassType
{
	// Пустой
	Empty = 0,
	// Главный персонаж
	Character = 1,
	// Финиш
	Finish = 2,
	// Препятствие
	Block = 4,
	// Враг
	Enemy = 8,
	// Снаряд
	Bullet = 16
};
