#pragma once

#include "BaseVertex.h"
#include "Edge.h"

// ������������ ��������� �����������
enum SideType;

// ����� �������
class Vertex : public BaseVertex
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
	Vertex(const int & x, const int & y) : Vertex(x, y, Vertex::EMPTYINDEX) {}
	// ������������� ����������
	Vertex(const int & x, const int & y, const int & counter);

	// �������� ������� ��������
	int GetSideCounter() const { return sideCounter; }
	// �������� ������� ��������
	void SetSideCounter(const int & value) { sideCounter = value; }
	// �������� ���
	int GetWeight() const { return weight; }
	// �������� ���
	void SetWeight(const int & value) { weight = value; }
	// �������� �����������
	SideType GetSide() { return side; }
	// �������� �����������
	void SetSide(const SideType & value) { side = value; }

	// �������� ������� ������������ �����
	Edge & GetMainPrevEdge() { return mainPrevEdge; }
	// �������� ������� ������������ �����
	Edge & GetAddPrevEdge() { return addPrevEdge; }

	// �������� ����� �����
	Edge & GetLeftEdge() { return leftEdge; }
	// �������� ������� �����
	Edge & GetUpEdge() { return upEdge; }
	// �������� ������ �����
	Edge & GetRightEdge() { return rightEdge; }
	// �������� ������ �����
	Edge & GetDownEdge() { return downEdge; }
private:
	// ������� ��������
	int sideCounter;
	// ���
	int weight;
	// �����������
	SideType side;

	// ������� ������������ �����
	Edge mainPrevEdge;
	// �������������� ������������ �����
	Edge addPrevEdge;
	
	// ����� �����
	Edge leftEdge;
	// ������� �����
	Edge upEdge;
	// ������ �����
	Edge rightEdge;
	// ������ �����
	Edge downEdge;
};