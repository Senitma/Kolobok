#pragma once

// ������ �� ������ �������
struct RefVertex
{
	// ������������� ����������
	RefVertex(const int & x, const int & y, const int & counter)
	{
		this->x = x; 
		this->y = y; 
		this->counter = counter;
	}

	// ��������� �� ��� X
	int x;
	// ��������� �� ��� Y
	int y;
	// �������
	int counter;
};
// ��������� ���� ������
bool operator<(const RefVertex & left, const RefVertex & right) { return left.counter > right.counter; }