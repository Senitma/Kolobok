#pragma once

#include "cocos2d.h"
#include "Field\FieldPoint.h"

//#include "TagAxes.h"

// ����� ������ ������������ ����
class PathFinder : private cocos2d::Ref
{
public:
	// �������� ����������� ����� �� ������
	static bool CanMoveTo(int startX, int startY, int finishX, int finishY, cocos2d::Vector<FieldPoint *> blockMap);
	// �������� ������� ����� �� ������
	static cocos2d::Vector<FieldPoint *> MoveTo(int startX, int startY, int finishX, int finishY, cocos2d::Vector<FieldPoint *> blockMap);
private:
	// ���������� ���������� �����
	int step;
	// ���������� ������ �� ��� X
	int finishX;
	// ���������� ������ �� ��� Y
	int finishY;

	// ��������� ������� �� ������
	bool FindFinish(int startX, int startY, cocos2d::Vector<FieldPoint *> blockMap);
	// ������������ ����� ����� ��� �����������
	cocos2d::Vector<FieldPoint *> CreateMoveMap(cocos2d::Vector<FieldPoint *> blockMap);

	// ������������ ������ �� ���������
	static int GetIndex(int x, int y);
};