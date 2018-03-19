#pragma once

#include "Vertex.h"

class Vertex;
// �����
struct Edge
{
public:
	// ������������� ����������
	Edge() : secondStatus(false) {}

	// �������� ������ ������ �������
	bool GetSecondStatus() const { return secondStatus; }
	// �������� ������ �� ������ �������
	Vertex & GetSecondVertex() const { return *secondVertex; }
	// �������� ������ �� ������ �������
	void SetSecondVertex(Vertex & value) { secondVertex = &value; secondStatus = true; }
private:
	// ������ �������
	Vertex * secondVertex;
	// ������ ������ �������
	bool secondStatus;
};