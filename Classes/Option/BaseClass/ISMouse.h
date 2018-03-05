#pragma once

#include "cocos2d.h"
#include "MouseType.h"

// Интерфейс опции с мышкой
class ISMouse : public cocos2d::Ref
{
public:
	// Инициализация переменных
	ISMouse();
	// Удаление переменных
	~ISMouse();
	// Обновление данных
	virtual void MouseClick(MouseType type, int x, int y) {};

	// Обновление данных
	static void MouseClickAll(MouseType type, int x, int y);
	// Удалить все опции
	static void Clear();
};