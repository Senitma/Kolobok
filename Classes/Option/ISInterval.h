#pragma once

#include "ISOption.h"

// ��������� ����� � �����������
class ISInterval : public ISOption
{
public:
	// ������������� ����������
	ISInterval(const Element & parent) : ISOption(parent) {};

	// ���������� ������
	virtual void Update() = 0;

	// ���������������� �����
	static void Register(std::shared_ptr<ISInterval> option);
	// ���������� ������
	static void PassUpdate();
};