#pragma once

#include "ISOption.h"

// Перечисление возможных клавиши мыши
enum MouseType;

// Интерфейс опции с мышкой
class ISMouse : ISOption
{
public:
	// Инициализация переменных
	ISMouse(Element & parent) : ISOption(parent) {}

	// Обработать клик мышкой
	virtual void MouseClick(const MouseType & type, const int & x, const int & y) = 0;

	// Зарегестрировать опцию
	static void Register(std::shared_ptr<ISMouse> option);
	// Передать клик мышкой
	static void PassMouseClick(const MouseType & type, const int & x, const int & y);
};