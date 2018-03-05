#pragma once

#include "Headers.h"

// ����� ���������� ���������
class AdvancedElement;
// ����� �������� ���������
class ElementCreator : private cocos2d::Ref
{
public:
	// �������� ��������
	static Element * Create(ElementNameType name, int x, int y);
	// �������� ��������
	static Element * Create(ElementNameType name, SideType side, int x, int y);
private:
	// �������� �������� ���������
	static AdvancedElement * CreateNinja(SideType side, int x, int y);
	// �������� �������� ������
	static AdvancedElement * CreateFinish(SideType side, int x, int y);
	// �������� �����
	static AdvancedElement * CreateWall(SideType side, int x, int y);
	// �������� �������
	static AdvancedElement * CreatePatrol(SideType side, int x, int y);
	// �������� �����
	static AdvancedElement * CreateGun(SideType side, int x, int y);
	// �������� ��������� ����
	static AdvancedElement * CreateFireball(SideType side, int x, int y);

	// �������� ��������
	static AdvancedElement * Create(char * nodeName, ElementNameType name, ClassType type, SideType side, int x, int y);
};