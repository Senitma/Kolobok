#pragma once

#include "Option\BaseClass\ISInterval.h"
#include "cocos2d.h"
#include "ElementNameType.h"
#include "SideType.h"
#include "ClassType.h"
#include "Field\BaseAxes.h"

// ����� ���������� ���������
class AdvancedElement
{
public:
	// ������������� ����������
	AdvancedElement(cocos2d::Node * node, ElementNameType name, ClassType type);

	// �������� ���
	ElementNameType GetName() const { return name; }
	// �������� ���
	ClassType GetType() const { return type; }
	// �������� ������� ��������
	SideType GetSide() const { return side; }
	// �������� �����������
	void SetSide(const SideType & value);

	// �������� ���������� �� ��� X
	int GetX() const { return points.at(0).GetX(); }
	// �������� ���������� �� ��� Y
	int GetY() const { return points.at(0).GetY(); }
	// �������� ����������
	BaseAxes GetAxes() const { return points.at(0); };
	// �������� ���������� �� ��� X
	void SetX(const int & value) { points.at(0).SetX(value);; };
	// �������� ���������� �� ��� Y
	void SetY(const int & value) { points.at(0).SetY(value); };;
	// �������� ����������
	void SetAxes(const int & x, const int & y);

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

	// �������� ����� ��� ��������������
	void AddPoint(const int & x, const int & y) { this->points.push_back(BaseAxes(x, y)); };
	// �������� ����� ��� ��������������
	BaseAxes GetPoint(const int & index) { return points.at(index + 1); };
	// �������� ���������� ����� ��� ��������������
	int GetPointLength() const { return this->points.size() - 1; };
	// �������� �����
	void AddOption(ISInterval * option) { items.pushBack(option); };
	// ���������� �������
	void Destroy();

	// ��������� ���� ���������
	bool operator== (const AdvancedElement & value) const { return node == value.node; };
	// ��������� ���� ���������
	bool operator!= (const AdvancedElement & value) const { return node != value.node; };
private:
	// ��� ��������
	ElementNameType name;
	// ��� ��������
	ClassType type;
	// ������� �������
	SideType side;
	// ���� ��� ����������
	cocos2d::Node * node;
	// ����� ��� ��������������
	std::vector<BaseAxes> points;

	// ������ �� ��������� �������
	bool isDestroy;
	// ����� �����
	cocos2d::Vector<ISInterval *> items;

	// �������� ������������ �� ���������
	//AdvancedElement() = delete;
};