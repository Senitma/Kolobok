#pragma once

#include "cocos2d.h"
#include "Element.h"
#include "ElementNameType.h"
#include "ClassType.h"
#include "SideType.h"

// ����� �������� ���������
class ElementCreator : private cocos2d::Ref
{
public:
	// �������� ��������
	static Element Create(ElementNameType name, int x, int y);
	// �������� ��������
	static Element Create(ElementNameType name, SideType side, int x, int y);
private:
	// �������� �������� ���������
	static Element CreateNinja(SideType side, int x, int y);
	// �������� �������� ������
	static Element CreateFinish(SideType side, int x, int y);
	// �������� �����
	static Element CreateWall(SideType side, int x, int y);
	// �������� �������
	static Element CreatePatrol(SideType side, int x, int y);
	// �������� �����
	static Element CreateGun(SideType side, int x, int y);
	// �������� ��������� ����
	static Element CreateFireball(SideType side, int x, int y);

	// �������� ��������
	static Element Create(char * nodeName, ElementNameType name, ClassType type, SideType side, int x, int y);
};