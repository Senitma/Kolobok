#pragma once

#include "vector"
#include "Edge.h"
#include "Field\Axes.h"

// ������������ ��������� �����������
enum SideType;

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
	Vertex() : Vertex(0, 0, Vertex::EMPTYINDEX) {}
	// ������������� ����������
	Vertex(const Axes & value) : Vertex(value.GetX(), value.GetY(), Vertex::EMPTYINDEX) {}
	// ������������� ����������
	Vertex(const int & x, const int & y) : Vertex(x, y, Vertex::EMPTYINDEX) {}
	// ������������� ����������
	Vertex(const int & x, const int & y, const int & counter);

	// �������� �������
	int GetCounter() const { return counter; }
	// �������� �������
	void SetCounter(const int & value) { counter = value; }
	// �������� ������� ��������
	int GetSideCounter() const { return sideCounter; }
	// �������� ������� ��������
	void SetSideCounter(const int & value) { sideCounter = value; }
	// �������� �������� ��������
	int GetOffsetCounter() const { return offsetCounter; }
	// �������� �������� ��������
	void SetOffsetCounter(const int & value) { offsetCounter = value; }
	// �������� ���
	int GetWeight() const { return weight; }
	// �������� ���
	void SetWeight(const int & value) { weight = value; }

	// �������� ������� ���������� �����
	Edge & GetMainPrevEdge() { return mainPrevEdge; }
	// �������� ������� ���������� �����
	Edge & GetAddPrevEdge() { return addPrevEdge; }
	// �������� ������������
	Edge & GetProgenitor() { return progenitor; }

	// �������� ����������� �������
	SideType GetSide() { return side; }
	// �������� ����������� �������
	void SetSide(const SideType & value) { side = value; }

	// �������� ����� ������� �����
	Edge & GetLeftNearEdge() { return leftNearEdge; }
	// �������� ������� ������� �����
	Edge & GetUpNearEdge() { return upNearEdge; }
	// �������� ������ ������� �����
	Edge & GetRightNearEdge() { return rightNearEdge; }
	// �������� ������ ������� �����
	Edge & GetDownNearEdge() { return downNearEdge; }

	// �������� ����� ������� �����
	Edge & GetLeftFarEdge() { return leftFarEdge; }
	// �������� ������� ������� �����
	Edge & GetUpFarEdge() { return upFarEdge; }
	// �������� ������ ������� �����
	Edge & GetRightFarEdge() { return rightFarEdge; }
	// �������� ������ ������� �����
	Edge & GetDownFarEdge() { return downFarEdge; }
private:
	// �������
	int counter;
	// ������� ��������
	int sideCounter;
	// �������� ��������
	int offsetCounter;
	// ���
	int weight;

	SideType side;

	// ������� ���������� �����
	Edge mainPrevEdge;
	// �������������� ���������� �����
	Edge addPrevEdge;
	// ��������������� �����
	Edge progenitor;
	
	// ����� ������� �����
	Edge leftNearEdge;
	// ������� ������� �����
	Edge upNearEdge;
	// ������ ������� �����
	Edge rightNearEdge;
	// ������ ������� �����
	Edge downNearEdge;

	// ����� ������� �����
	Edge leftFarEdge;
	// ������� ������� �����
	Edge upFarEdge;
	// ������ ������� �����
	Edge rightFarEdge;
	// ������ ������� �����
	Edge downFarEdge;
};