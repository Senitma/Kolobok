#pragma once

// Перечисление возможных карт
enum class MapIndexType
{
	Example,
	Labyrinth,
	AlgorithmTest,
	Empty
};

// Модуль управления картами
namespace Maps
{
	// Загрузить карту по умолчанию
	void Load();
	// Загрузить карту по индексу
	void Load(MapIndexType index);
	// Перезагрузить карту
	void ReloadMap();
};