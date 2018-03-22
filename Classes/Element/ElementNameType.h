#pragma once

// Перечисление возможных имен
enum class ElementNameType
{
	// Имя не указано
	Empty,
	// Пол
	Floor,
	// Главный персонаж
	Main,
	// Финиш
	Finish,
	// Блокировка пути
	Block,
	// Патруль
	Patrol,
	// Оружие
	Gun,
	// Снаряд
	Fireball
};