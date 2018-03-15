#pragma once

#include "OptionForMove.h"
#include "Option\ISMouse.h"

// ����� ��� �����������
class OptionForMouseMove : public OptionForMove, public ISMouse
{
public:
	// ������������� ����������
	OptionForMouseMove(const Element & parent) : OptionForMove(parent), ISMouse(parent) {}

	// ���� ������
	void MouseClick(const MouseType & type, const int & x, const int & y) override;
};