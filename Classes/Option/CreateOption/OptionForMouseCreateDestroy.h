#pragma once

#include "OptionForCreate.h"
#include "Option\BaseClass\ISMouse.h"

// ����� �������� ��������
class OptionForMouseCreateDestroy : public OptionForCreate, public ISMouse
{
public:

	OptionForMouseCreateDestroy(Element & parent) : OptionForCreate(parent) {};
	void MouseClick(MouseType type, int x, int y) override;
};