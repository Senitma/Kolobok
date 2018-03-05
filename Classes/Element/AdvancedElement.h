#pragma once

#include "Headers.h"

// ����� ���������� ���������
class AdvancedElement : public Element
{
public:
	// ������������� ����������
	AdvancedElement() : Element() { isDestroy = true; };
	// ������������� ����������
	AdvancedElement(cocos2d::Node * node, ElementNameType name, ClassType type) : Element(node, name, type) { isDestroy = false; };
	// �������� ���������� �� ��� X
	void SetX(int value) { currentPoint->SetX(value); };
	// �������� ���������� �� ��� Y
	void SetY(int value) { currentPoint->SetY(value); };
	// �������� ����������
	void SetXY(FieldPoint value);
	// �������� �����������
	void SetSide(SideType value);

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

	// ���������� �������
	void Destroy() override;
private:
	// ������ �� ��������� �������
	bool isDestroy;
};