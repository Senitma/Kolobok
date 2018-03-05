#pragma once

#include "cocos2d.h"

// Интерфейс опции с обновлением
class ISInterval : public cocos2d::Ref
{
public:
	// Инициализация переменных
	ISInterval();
	// Уничтожение объекта
	void Destroy();
	// Обновление данных
	virtual void Update() {};

	// Обновление данных
	static void UpdateAll();
	// Удалить все опции
	static void Clear();
private:
	// Переключатель активности
	bool isActive;
	// Переключатель возможности обновления 
	bool isUpdate;
	
	// Обновление данных с переключением
	void ActiveUpdate();
};