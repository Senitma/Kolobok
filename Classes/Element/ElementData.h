#pragma once

#include "queue"

#include "ElementAnimation.h"
#include "ElementNameType.h"
#include "SideType.h"
#include "ClassType.h"
#include "Field\Axes.h"

#include "cocos2d.h"
#include "2d\CCNode.h"
#include "cocostudio\ActionTimeline\CCActionTimeline.h"

// ������ ��������
struct ElementData
{
	// ������������ �������������
	int id;
	// ��� ��������
	ElementNameType name;
	// ��� ��������
	ClassType type;
	// ������� �����������
	SideType side;
	// ���� ��� ����������
	cocos2d::Node * node;
	// ��������
	ElementAnimation animation;

	// ��������� ��������
	Axes position;
	// ����� ��� ��������������
	std::queue<Axes> patrolPoints;

	// ������ ��������
	bool destroyStatus;
	// ������ ���� ��� ����������
	bool destroyNodeStatus;
};