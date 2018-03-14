#pragma once

#include "OptionForOneStep.h"
#include "Option\ISMouse.h"

// Опция для перемещения
class OptionForMouseMove : public OptionForOneStep, public ISMouse
{
public:
	// Инициализация переменных
	OptionForMouseMove(const Element & parent) : OptionForOneStep(parent), ISMouse(parent) {}

	// Клик мышкой
	void MouseClick(const MouseType & type, const int & x, const int & y) override;
};