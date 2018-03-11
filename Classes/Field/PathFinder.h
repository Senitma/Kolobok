#pragma once

#include "vector"

//������� ����� ���� ���������
class Axes;
// ����� ��������� � ���������������
class TagAxes;
// ����� ������ ������������ ����
class PathFinder
{
public:
	// ������������� ����������
	PathFinder(std::vector<TagAxes> & map);

	// �������� ����������� ����� �� ������
	static bool CanMoveTo(std::vector<TagAxes> & map, const Axes & start, const Axes & finish);
	// �������� ������� ����� �� ������
	static std::vector<Axes> MoveTo(std::vector<TagAxes> & map, const Axes & start, const Axes & finish, const bool & extendedCheck);
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

	// �������� ���������� �����
	int GetStep() const { return step; };
	// �������� ���������� ������
	Axes GetStart() const;
	// �������� ���������� ������
	Axes GetFinish() const;
	// �������� ���������� ������
	void SetStart(const Axes & value);
	// �������� ���������� ������
	void SetFinish(const Axes & value);

	// ��������� ������� �� ������
	bool FindFinish(const bool & rotateCheck);
	// ����� ��������� ����� � ������ 
	bool FindNewFinish();
	// ������������ ����� ����� ��� �����������
	std::vector<Axes> CreateMoveMap();

	// �������� ������ �� �������� ������
	TagAxes & GetChild(const TagAxes & parent, const int & offsetX, const int & offsetY);
	// ������� ������� � �����
	void Clear();
};