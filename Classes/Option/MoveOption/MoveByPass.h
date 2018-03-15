#pragma once

#include "vector"
#include "deque"
#include "queue"

//������� ����� ���� ���������
class Axes;
// ����� ��������� � ���������������
class TagAxes;

// ����� ������ ������������ ����
class MoveByPass
{
public:
	// ������������� ����������
	MoveByPass();
	// ������������� ����������
	MoveByPass(const std::vector<TagAxes> & map);

	// �������� ����� ��� �����������
	const std::vector<TagAxes> & GetMap() const { return map; };

	// �������� ����������� ����� �� ������
	static bool CanMoveTo(const Axes & start, const Axes & finish);
	// �������� ������� ����� �� ������
	static std::queue<Axes> MoveTo(const Axes & start, const Axes & finish, const bool & extendedCheck);
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
	std::deque<Axes> CreateMoveMap();

	// �������� ������ �� �������� ������
	TagAxes & GetChild(const TagAxes & parent, const int & offsetX, const int & offsetY);
	// ������� ������� � �����
	void Clear();
};