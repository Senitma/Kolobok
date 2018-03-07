#pragma once

#include "cocos2d.h"
#include "Field\FieldPoint.h"
#include "ElementNameType.h"
#include "SideType.h"
#include "ClassType.h"
#include "Field\BaseAxes.h"
#include "vector"

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
	int GetX() { return currentPoint.GetX(); }
	// �������� ���������� �� ��� Y
	int GetY() { return currentPoint.GetY(); }
	// �������� ����������
	BaseAxes GetAxes() { return currentPoint; };

	// �������� ����� ��� ��������������
	void AddPoint(int x, int y);
	// �������� ����� ��� ��������������
	BaseAxes GetPoint(int index) { return points.at(index); };
	// �������� ���������� ����� ��� ��������������
	int GetPointLength() { return this->points.size(); };

	// ���������� �������
	virtual void Destroy() {};
protected:
	// ������������� ����������
	Element() { currentPoint = BaseAxes(0, 0); };
	// ������������� ����������
	Element(cocos2d::Node * node, ElementNameType name, ClassType type);
	// ������� �������
	SideType side;
	// ��������� ��������
	BaseAxes currentPoint;
	// ���� ��� ����������
	cocos2d::Node * node;
private:
	// ��� ��������
	ElementNameType name;
	// ��� ��������
	ClassType type;

	// ����� ��� ��������������
	std::vector <BaseAxes> points;
};
