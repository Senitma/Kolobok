#pragma once

#include "vector"
#include "deque"
#include "queue"

// ���������� ��������
struct Axes;
// ����� �������
class Vertex;
// ��������� ������ �� �������
struct RefVertex;
// �������� ��������� ������ �� �������
struct ReverseRefVertex;
// ������������ ��������� �����������
enum SideType;

// ����� ������ ������������ ����
class MoveByPass
{
public:
	// ������������� ����������
	MoveByPass();
	// ������������� ����������
	MoveByPass(const std::vector<Vertex> & map);

	// �������� ����������� ����� �� ������
	static bool CanMoveTo(const Axes & start, const Axes & finish);
	// �������� ������� ����� �� ������
	static std::queue<Axes> MoveTo(const Axes & start, const SideType & side, const Axes & finish);
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
	// ����������� ������
	SideType side;
	// ����� ��� �����������
	std::vector<Vertex> vertexMap;

	// �������� ���������� �����
	int GetStep() const { return step; };
	//// �������� ���������� ������
	void SetStart(const Axes & value, SideType side);
	//// �������� ���������� ������
	void SetStart(const Axes & value);
	//// �������� ���������� ������
	void SetFinish(const Axes & value);

	// ��������� ������� �� ������
	bool FindFinish();
	// �������� ��������� ������ ������� ����
	void AddLinePathPreoritety();
	// ����� ��������� ����� � ������ 
	bool FindNewFinish();
	// ������������ ����� ����� ��� �����������
	std::deque<Axes> CreateMoveMap();
	// ������������ ����� ����� ��� �����������
	std::deque<Axes> CreateMoveMap(const int & finishX, const int & finishY, std::deque<Axes> path);
};