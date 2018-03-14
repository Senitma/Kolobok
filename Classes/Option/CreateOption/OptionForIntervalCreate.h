#pragma once

#include "OptionForCreate.h"
#include "Option\ISInterval.h"

// Опция создания элемента через временной интервал
class OptionForIntervalCreate : public OptionForCreate, public ISInterval
{
public:
	// Инициализация переменных
	OptionForIntervalCreate(Element & parent);

	// Получить переключатель активности
	bool GetActive() { return isActive; };
	// Задать переключатель активности
	void SetActive(bool value) { isActive = value; };
	// Получить период создания
	int GetInterval() { return interval; };
	// Задать период создания
	void SetInterval(int value) { interval = value; };

	// Обновление данных
	void Update() override;
protected:
	// Переключатель активности
	bool isActive;
	// Период создания
	int interval;
private:
	// Текущее время
	int currentTime;
};