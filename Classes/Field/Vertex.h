#pragma once

#include "Axes.h"

// ����� �������
class Vertex : public Axes
{
public:
	// �������� ������ � ������
	static const int BLOCKINDEX = -3;
	// �������� ������ ������
	static const int FINISHINDEX = -2;
	// �������� ������ ������
	static const int EMPTYINDEX = -1;
	// �������� ������ ������ 
	static const int STARTINDEX = 0;

	// ������������� ����������
	Vertex() : Vertex(0, 0, 0) {}
	// ������������� ����������
	Vertex(const int & x, const int & y) : Vertex(x, y, 0) {}
	// ������������� ����������
	Vertex(const int & x, const int & y, const int & pathCounter) : Axes(x, y) { this->pathCounter = pathCounter; }
	// ������������� ����������
	Vertex(const Axes & value) : Vertex(value.GetX(), value.GetY(), 0) {}

	// �������� ������� ����
	int GetPathCounter() const { return pathCounter; };
	// �������� ������� ����
	void SetPathCounter(const int & value) { pathCounter = value; };

	// ������������ ������ ��������
	Vertex operator=(const Axes & value) const { return Vertex(value); };
	// ��������� ���� ���������
	bool operator==(const Vertex & value) const { return ((x == value.GetX()) && (y == value.GetY() && (pathCounter == value.GetPathCounter()))); };
	// ��������� ���� ���������
	bool operator!=(const Vertex & value) const { return ((x != value.GetX()) || (y != value.GetY() || (pathCounter != value.GetPathCounter()))); };
private:
	// ������� ����
	int pathCounter;
};