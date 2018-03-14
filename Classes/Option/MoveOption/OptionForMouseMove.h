#pragma once

#include "OptionForOneStep.h"
#include "Option\ISMouse.h"

// ����� ��� �����������
class OptionForMouseMove : public OptionForOneStep, public ISMouse
{
public:
	// ������������� ����������
	OptionForMouseMove(const Element & parent) : OptionForOneStep(parent), ISMouse(parent) {}

	// ���� ������
	void MouseClick(const MouseType & type, const int & x, const int & y) override;
};