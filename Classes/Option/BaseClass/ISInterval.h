#pragma once

#include "cocos2d.h"

// ��������� ����� � �����������
class ISInterval : public cocos2d::Ref
{
public:
	// ������������� ����������
	ISInterval();
	// ����������� �������
	void Destroy();
	// ���������� ������
	virtual void Update() {};

	// ���������� ������
	static void UpdateAll();
	// ������� ��� �����
	static void Clear();
private:
	// ������������� ����������
	bool isActive;
	// ������������� ����������� ���������� 
	bool isUpdate;
	
	// ���������� ������ � �������������
	void ActiveUpdate();
};