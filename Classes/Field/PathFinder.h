#pragma once

#include "TagAxes.h"
#include "vector"

// ����� ������ ������������ ����
class PathFinder
{
public:
	// ������������� ����������
	PathFinder(std::vector<TagAxes> blockMap) { map = blockMap; };
	// �������� ����������� ����� �� ������
	static bool CanMoveTo(int startX, int startY, int finishX, int finishY, std::vector<TagAxes> blockMap);
	// �������� ������� ����� �� ������
	static std::vector<TagAxes> MoveTo(int startX, int startY, int finishX, int finishY, std::vector<TagAxes> blockMap);
private:
	// ���������� ���������� �����
	int step;
	// ���������� ������ �� ��� X
	int finishX;
	// ���������� ������ �� ��� Y
	int finishY;
	// ����� ��� �����������
	std::vector<TagAxes> map;

	// ��������� ������� �� ������
	bool FindFinish(int startX, int startY);
	// ������������ ����� ����� ��� �����������
	std::vector<TagAxes> CreateMoveMap();

	// ������������ ������ �� ���������
	static int GetIndex(int x, int y);
};