#pragma once

#include "cocos2d.h"
#include "ElementNameType.h"
#include "SideType.h"
#include "ClassType.h"
#include "Field\Axes.h"

// ������ ��������
struct ElementData
{
	// ��� ��������
	ElementNameType name;
	// ��� ��������
	ClassType type;
	// ������� �������
	SideType side;
	// ���� ��� ����������
	cocos2d::Node * node;
	// ��������� ��������
	Axes position;
	// ����� ��� ��������������
	std::vector<Axes> patrolPoints;

	// ������ ��������
	bool destroyStatus;
};