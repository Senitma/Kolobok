#pragma once

#include "ISOption.h"

// ��������� ����� � �����������
class ISInterval : ISOption
{
public:
	// ������������� ����������
	ISInterval(Element & parent) : ISOption(parent) {};

	// ���������� ������
	virtual void Update() = 0;

	// ���������������� �����
	static void Register(std::shared_ptr<ISInterval> option);
	// ���������� ������
	static void PassUpdate();
};