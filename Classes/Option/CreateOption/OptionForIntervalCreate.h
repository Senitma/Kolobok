#pragma once

#include "OptionForCreate.h"
#include "Option\ISInterval.h"

// ����� �������� �������� ����� ��������� ��������
class OptionForIntervalCreate : public OptionForCreate, public ISInterval
{
public:
	// ������������� ����������
	OptionForIntervalCreate(Element & parent) : OptionForCreate(parent) , ISInterval(parent) {};

	// �������� ������������� ����������
	bool GetActive() { return isActive; };
	// ������ ������������� ����������
	void SetActive(bool value) { isActive = value; };
	// �������� ������ ��������
	int GetInterval() { return interval; };
	// ������ ������ ��������
	void SetInterval(int value) { interval = value; };
	// ���������� ������
	void Update() override;
protected:
	// ������������� ����������
	bool isActive;
	// ������ ��������
	int interval;
private:
	// ������� �����
	int currentTime;
};