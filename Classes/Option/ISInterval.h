#pragma once

#include "ISOption.h"

// Интерфейс опции с обновлением
class ISInterval : public ISOption
{
public:
	// Инициализация переменных
	ISInterval(const Element & parent) : ISOption(parent) {};

	// Обновление данных
	virtual void Update() = 0;

	// Зарегестрировать опцию
	static void Register(std::shared_ptr<ISInterval> option);
	// Обновление данных
	static void PassUpdate();
};