#pragma once

#include "cocos2d.h"
#include "Element\Element.h"

// ��������� �����
class ISOption : public cocos2d::Ref
{
public:
	// ������������� ����������
	ISOption(Element & parent) : parent(parent) {};
	// �������� �������� �����
	Element & GetParent() { return parent; };
protected:
	// �������� �����
	Element parent;
};