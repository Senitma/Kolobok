#pragma once

#include "Element\Element.h"
#include "Option\BaseClass\ISInterval.h"

// ����� ���������� ���������
class AdvancedElement : public Element
{
public:
	// ������������� ����������
	AdvancedElement(cocos2d::Node * node, ElementNameType name, ClassType type) : Element(node, name, type) { isDestroy = false; };

	// �������� ���������� �� ��� X
	void SetX(const int & value) { Element::SetX(value); };
	// �������� ���������� �� ��� Y
	void SetY(const int & value) { Element::SetY(value); };;
	// �������� ����������
	void SetAxes(const int & x, const int & y);
	// �������� �����������
	void SetSide(const SideType & value);

	// �������� �������� �����
	int GetLeft();
	// �������� �������� ������
	int GetTop();
	// �������� ��������
	void SetPosition(cocos2d::Vec2 value);
	// �������� ���� ��������
	int GetRotation();
	// ������� ���� ��������
	void SetRotation(int value);

	// �������� �����
	void AddOption(ISInterval * option) { items.pushBack(option); };
	// ���������� �������
	void Destroy() override;
private:
	// ������ �� ��������� �������
	bool isDestroy;
	// ����� �����
	cocos2d::Vector<ISInterval *> items;
};