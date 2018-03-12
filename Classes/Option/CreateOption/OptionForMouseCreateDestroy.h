#pragma once

#include "OptionForCreate.h"
#include "Option\ISMouse.h"

// Опция создания элемента
class OptionForMouseCreateDestroy : public OptionForCreate, public ISMouse
{
public:

	// Инициализация переменных
	OptionForMouseCreateDestroy(Element & parent) : OptionForCreate(parent), ISMouse(parent) {};

	void MouseClick(const MouseType & type, const int & x, const int & y) override;
};