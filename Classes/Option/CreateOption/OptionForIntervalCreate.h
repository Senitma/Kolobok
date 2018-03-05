#pragma once

#include "OptionForCreate.h"
#include "..\Option\BaseClass\ISInterval.h"

// ����� �������� �������� ����� ��������� ��������
class OptionForIntervalCreate : public OptionForCreate, public ISInterval
{
public:
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

	// ������ �������� �����
	virtual void SetParent(AdvancedElement * value) override { parent = value; parent->AddOption(this); };
protected:
	// ������������� ����������
	bool isActive;
	// ������ ��������
	int interval;
private:
	// ������� �����
	int currentTime;
};