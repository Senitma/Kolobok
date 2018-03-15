#pragma once

#include "OptionForMove.h"
#include "Option\ISMouse.h"

// Опция для перемещения
class OptionForMouseMove : public OptionForMove, public ISMouse
{
public:
	// Инициализация переменных
	OptionForMouseMove(const Element & parent) : OptionForMove(parent), ISMouse(parent) {}

	// Клик мышкой
	void MouseClick(const MouseType & type, const int & x, const int & y) override;
};