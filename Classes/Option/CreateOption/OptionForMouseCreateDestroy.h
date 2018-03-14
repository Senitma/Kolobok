#pragma once

#include "OptionForCreate.h"
#include "Option\ISMouse.h"

// Опция создания и удаления элемента с помощью мыши
class OptionForMouseCreateDestroy : public OptionForCreate, public ISMouse
{
public:
	// Инициализация переменных
	OptionForMouseCreateDestroy(Element & parent) : OptionForCreate(parent), ISMouse(parent) {};

	// Клик мышкой
	void MouseClick(const MouseType & type, const int & x, const int & y) override;
};