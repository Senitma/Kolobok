#pragma once

#include "Headers.h"

// ��������� �����
class ISOption : public cocos2d::Ref
{
public:
	// ������������� ����������
	ISOption() {};
	// �������� �������� �����
	AdvancedElement * GetParent() { return parent; };
	// ������ �������� �����
	virtual void SetParent(AdvancedElement * value) = 0;
protected:
	// �������� �����
	AdvancedElement * parent;
};