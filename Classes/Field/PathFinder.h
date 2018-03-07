#pragma once

#include "vector"

//������� ����� ���� ���������
class BaseAxes;
// ����� ��������� � ���������������
class TagAxes;
// ����� ������ ������������ ����
class PathFinder
{
public:
	// ������������� ����������
	PathFinder(std::vector<TagAxes> & map, const BaseAxes & start, const BaseAxes & finish);

	// �������� ����������� ����� �� ������
	static bool CanMoveTo(std::vector<TagAxes> & map, const BaseAxes & start, const BaseAxes & finish);
	// �������� ������� ����� �� ������
	static std::vector<BaseAxes> MoveTo(std::vector<TagAxes> & map, const BaseAxes & start, const BaseAxes & finish);
private:
	// ���������� ���������� �����
	int step;
	// ���������� ������ �� ��� X
	int startX;
	// ���������� ������ �� ��� Y
	int startY;
	// ���������� ������ �� ��� X
	int finishX;
	// ���������� ������ �� ��� Y
	int finishY;
	// ����� ��� �����������
	std::vector<TagAxes> map;

	// ��������� ������� �� ������
	bool FindFinish();
	// ����� ��������� ����� � ������ 
	bool FindNewFinish();
	// ������������ ����� ����� ��� �����������
	std::vector<BaseAxes> CreateMoveMap();
};