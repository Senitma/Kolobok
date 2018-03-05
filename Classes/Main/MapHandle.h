#pragma once

#include "cocos2d.h"

// Класс управления картой
class MapHandle : public cocos2d::Ref
{
public:
	// Загрузить карту по умолчанию
	static void LoadDefault();
	// Загрузить карту по индексу
	static void LoadForIndex(int index);
	// Перезагрузить карту
	static void ReloadMap();
	// Проверить наличие пути от главного персонажа до финиша
	static bool CheckPath();
private:
	// Загрузить карту по индексу 0
	static void LoadForIndex0();
	// Загрузить карту по индексу 1
	static void LoadForIndex1();
	// Загрузить карту по индексу 2
	static void LoadForIndex2();
};