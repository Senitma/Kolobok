#pragma once

#include "cocos2d.h"
#include "ElementNameType.h"
#include "SideType.h"
#include "ClassType.h"
#include "Field\BaseAxes.h"

// ������ ��������
struct ElementData
{
public:
	// ��� ��������
	ElementNameType name;
	// ��� ��������
	ClassType type;
	// ������� �������
	SideType side;
	// ���� ��� ����������
	cocos2d::Node * node;
	// ��������� ��������
	BaseAxes position;
	// ����� ��� ��������������
	std::vector<BaseAxes> patrolPoints;

	// ������ ��������
	bool destroyStatus;
};