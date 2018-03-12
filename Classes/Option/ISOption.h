#pragma once

#include "Element\Element.h"

// ������� ��������� ��� ���� �����
class ISOption
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