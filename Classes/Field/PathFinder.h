#pragma once

#include "TagAxes.h"

// ����� ������ ������������ ����
class PathFinder : private cocos2d::Ref
{
public:
	// �������� ����������� ����� �� ������
	static bool CanMoveTo(int startX, int startY, int finishX, int finishY, cocos2d::Vector<TagAxes *> blockMap);
	// �������� ������� ����� �� ������
	static cocos2d::Vector<TagAxes *> MoveTo(int startX, int startY, int finishX, int finishY, cocos2d::Vector<TagAxes *> blockMap);
private:
	// ���������� ���������� �����
	int step;
	// ���������� ������ �� ��� X
	int finishX;
	// ���������� ������ �� ��� Y
	int finishY;

	// ��������� ������� �� ������
	bool FindFinish(int startX, int startY, cocos2d::Vector<TagAxes *> blockMap);
	// ������������ ����� ����� ��� �����������
	cocos2d::Vector<TagAxes *> CreateMoveMap(cocos2d::Vector<TagAxes *> blockMap);

	// ������������ ������ �� ���������
	static int GetIndex(int x, int y);
};