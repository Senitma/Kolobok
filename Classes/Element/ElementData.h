#pragma once

#include "ElementNameType.h"
#include "SideType.h"
#include "ClassType.h"
#include "Field\Axes.h"

#include "cocos2d.h"

// ������ ��������
struct ElementData
{
	// ��� ��������
	ElementNameType name;
	// ��� ��������
	ClassType type;
	// ������� �����������
	SideType side;
	// ���� ��� ����������
	cocos2d::Node * node;
	// ��������� ��������
	Axes position;
	// ����� ��� ��������������
	std::vector<Axes> patrolPoints;

	// ������ ��������
	bool destroyStatus;
	// ������ ���� ��� ����������
	bool destroyNodeStatus;
};