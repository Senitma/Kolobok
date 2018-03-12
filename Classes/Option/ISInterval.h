#pragma once

#include "ISOption.h"

// Интерфейс опции с обновлением
class ISInterval : ISOption
{
public:
	// Инициализация переменных
	ISInterval(Element & parent);

	// Обновление данных
	virtual void Update() = 0;

	// Обновление данных
	static void PassUpdate();
};