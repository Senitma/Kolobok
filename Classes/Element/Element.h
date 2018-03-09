#pragma once

#include "cocos2d.h"
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
	ElementNameType GetName() const { return name; }
	// �������� ���
	ClassType GetType() const { return type; }
	// �������� ������� ��������
	SideType GetSide() const { return side; }

	// �������� ���������� �� ��� X
	int GetX() const { return points.at(0).GetX(); }
	// �������� ���������� �� ��� Y
	int GetY() const { return points.at(0).GetY(); }
	// �������� ����������
	BaseAxes GetAxes() const { return points.at(0); };

	// �������� ����� ��� ��������������
	void AddPoint(const int & x,const int & y);
	// �������� ����� ��� ��������������
	BaseAxes GetPoint(const int & index) { return points.at(index + 1); };
	// �������� ���������� ����� ��� ��������������
	int GetPointLength() const { return this->points.size() - 1; };

	// ���������� �������
	virtual void Destroy() {};
protected:
	// ������� �������
	SideType side;
	// ���� ��� ����������
	cocos2d::Node * node;

	// ������������� ����������
	Element(cocos2d::Node * node, const ElementNameType & name, const ClassType & type);

	// �������� ���������� �� ��� X
	void SetX(const int & value) { points.at(0).SetX(value); };
	// �������� ���������� �� ��� Y
	void SetY(const int & value) { points.at(0).SetY(value); };
private:
	// ��� ��������
	ElementNameType name;
	// ��� ��������
	ClassType type;

	// ����� ��� ��������������
	std::vector<BaseAxes> points;
};
