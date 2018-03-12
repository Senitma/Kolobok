#pragma once

#include "ISOption.h"

// ������������ ��������� ������� ����
enum MouseType;

// ��������� ����� � ������
class ISMouse : ISOption
{
public:
	// ������������� ����������
	ISMouse(Element & parent) : ISOption(parent) {}

	// ���������� ���� ������
	virtual void MouseClick(const MouseType & type, const int & x, const int & y) = 0;

	// ���������������� �����
	static void Register(std::shared_ptr<ISMouse> option);
	// �������� ���� ������
	static void PassMouseClick(const MouseType & type, const int & x, const int & y);
};