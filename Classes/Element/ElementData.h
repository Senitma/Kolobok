#pragma once

#include "cocos2d.h"

#include "ElementNameType.h"
#include "ClassType.h"
#include "SideType.h"
#include "Field\BaseAxes.h"
#include "Option\BaseClass\ISInterval.h"

// ����� ������ ��� ��������
class ElementData
{
public:
	// ��� ��������
	ElementNameType name;
	// ��� ��������
	ClassType type;
	// ������� ��������
	SideType side;
	// ���������� ��������
	BaseAxes position;

	// ���� ��� ����������
	cocos2d::Node * node;
	// ���������� ��� �������
	std::vector<BaseAxes> patrolPoints;
	// ����� �����
	std::list<ISInterval *> options;

	// �������� ��������� �������
	bool GetDestroyStatus() const { return isDestroy; };
	// �������� ������
	void Destroy();
	// �������� ������
	ElementData() { Destroy(); };
private:
	// ������ �� ��������� �������
	bool isDestroy;
};