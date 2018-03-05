#pragma once

#include "OptionForCreate.h"
#include "..\Option\BaseClass\ISMouse.h"

// Опция создания элемента
class OptionForMouseCreateDestroy : public OptionForCreate, public ISMouse
{
public:
	void MouseClick(MouseType type, int x, int y) override;
};