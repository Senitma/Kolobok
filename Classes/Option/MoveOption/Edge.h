#pragma once

#include "Vertex.h"

// ������������ ��������� �����������
enum SideType;
// �������
class Vertex;

// �����
class Edge
{
public:
	// ������������� ����������
	Edge() : enable(false) {}

	// �������� ������ ������ �������
	bool GetEnable() const { return enable; }

	// �������� ��������� �� ��� X
	int GetX() const;
	// �������� ��������� �� ��� Y
	int GetY() const;
	// �������� ������ � �������
	int GetIndex() const;
	// �������� �������
	int GetCounter() const;
	// �������� �������
	void SetCounter(const int & value);

	// �������� ������� ��������
	int GetSideCounter() const;
	// �������� ������� ��������
	void SetSideCounter(const int & value);
	// �������� ���
	int GetWeight() const;
	// �������� ���
	void SetWeight(const int & value);
	// �������� �����������
	SideType GetSide();
	// �������� �����������
	void SetSide(const SideType & value);

	// �������� ������� ������������ �����
	Edge & GetMainPrevEdge();
	// �������� ������� ������������ �����
	Edge & GetAddPrevEdge();

	// �������� ����� �����
	Edge & GetLeftEdge();
	// �������� ������� �����
	Edge & GetUpEdge();
	// �������� ������ �����
	Edge & GetRightEdge();
	// �������� ������ �����
	Edge & GetDownEdge();

	// �������� ������ �� ������ �������
	Vertex & GetVertex() const { return *vertex; }
	// �������� ������ �� ������ �������
	void SetVertex(Vertex & value) { vertex = &value; enable = true; }
private:
	// ������ �������
	bool enable;
	// ������ �� �������
	Vertex * vertex;
};