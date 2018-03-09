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
	PathFinder(std::vector<TagAxes> & map);

	// �������� ����������� ����� �� ������
	static bool CanMoveTo(std::vector<TagAxes> & map, const BaseAxes & start, const BaseAxes & finish);
	// �������� ������� ����� �� ������
	static std::vector<BaseAxes> MoveTo(std::vector<TagAxes> & map, const BaseAxes & start, const BaseAxes & finish, const bool & extendedCheck);
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
	BaseAxes GetStart() const;
	// �������� ���������� ������
	BaseAxes GetFinish() const;
	// �������� ���������� ������
	void SetStart(const BaseAxes & value);
	// �������� ���������� ������
	void SetFinish(const BaseAxes & value);

	// ��������� ������� �� ������
	bool FindFinish(const bool & rotateCheck);
	// ����� ��������� ����� � ������ 
	bool FindNewFinish();
	// ������������ ����� ����� ��� �����������
	std::vector<BaseAxes> CreateMoveMap();

	// �������� ������ �� �������� ������
	TagAxes & GetChild(const TagAxes & parent, const int & offsetX, const int & offsetY);
	// ������� ������� � �����
	void Clear();
};