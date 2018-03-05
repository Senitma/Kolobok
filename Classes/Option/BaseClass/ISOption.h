#pragma once

#include "cocos2d.h"
#include "Element\AdvancedElement.h"

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