#pragma once

#include "ISOption.h"

// ��������� ����� � �����������
class ISInterval : ISOption
{
public:
	// ������������� ����������
	ISInterval(Element & parent);

	// ���������� ������
	virtual void Update() = 0;

	// ���������� ������
	static void PassUpdate();
};