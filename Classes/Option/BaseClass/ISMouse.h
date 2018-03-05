#pragma once

#include "cocos2d.h"
#include "MouseType.h"

// ��������� ����� � ������
class ISMouse : public cocos2d::Ref
{
public:
	// ������������� ����������
	ISMouse();
	// �������� ����������
	~ISMouse();
	// ���������� ������
	virtual void MouseClick(MouseType type, int x, int y) {};

	// ���������� ������
	static void MouseClickAll(MouseType type, int x, int y);
	// ������� ��� �����
	static void Clear();
};