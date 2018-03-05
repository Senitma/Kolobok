#pragma once

#include "cocos2d.h"
#include "Field\FieldPoint.h"
#include "ElementNameType.h"
#include "SideType.h"
#include "ClassType.h"

// ������� ����� ���� ���������
class Element : public cocos2d::Ref
{
public:
	// �������� ���
	ElementNameType GetName() { return name; }
	// �������� ���
	ClassType GetType() { return type; }
	// �������� ������� ��������
	SideType GetSide() { return side; }

	// �������� ���������� �� ��� X
	int GetX() { return currentPoint->GetX(); }
	// �������� ���������� �� ��� Y
	int GetY() { return currentPoint->GetY(); }
	// �������� ����������
	FieldPoint GetXY() { return * currentPoint; };

	// �������� ����� ��� ��������������
	void AddPoint(FieldPoint * point);
	// ������� ����� ��� ��������������
	void RemovePoint(FieldPoint * point);
	// �������� ����� ��� ��������������
	FieldPoint * GetPoint(int index) { return points.at(index); };
	// �������� ���������� ����� ��� ��������������
	int GetPointLength() { return this->points.size(); };

	// ���������� �������
	virtual void Destroy();
protected:
	// ������������� ����������
	Element() { currentPoint = new FieldPoint(0, 0); };
	// ������������� ����������
	Element(cocos2d::Node * node, ElementNameType name, ClassType type);
	// ������� �������
	SideType side;
	// ��������� ��������
	FieldPoint * currentPoint;
	// ���� ��� ����������
	cocos2d::Node * node;
private:
	// ��� ��������
	ElementNameType name;
	// ��� ��������
	ClassType type;

	// ����� ��� ��������������
	cocos2d::Vector <FieldPoint *> points;
};
