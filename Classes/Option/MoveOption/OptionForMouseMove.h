#pragma once

#include "OptionForMove.h"
#include "Option\BaseClass\ISMouse.h"

// ����� ��� �����������
class OptionForMouseMove : public OptionForMove, public ISMouse
{
public:
	void MouseClick(MouseType type, int x, int y) override;
};