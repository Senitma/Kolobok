#pragma once

// �������� ������ �������
struct BaseVertex
{
public:
	// ������������� ����������
	BaseVertex(const int & x, const int & y) : BaseVertex(x, y, 0) {}
	// ������������� ����������
	BaseVertex(const int & x, const int & y, const int & counter)
	{
		this->x = x;
		this->y = y;
		this->counter = counter;

		index = GetIndex(x, y);
	}

	// �������� ��������� �� ��� X
	int GetX() const { return x; }
	// �������� ��������� �� ��� Y
	int GetY() const { return y; }
	// �������� ������ � �������
	int GetIndex() const { return index; }
	// �������� �������
	int GetCounter() const { return counter; }
	// ������� �������
	void SetCounter(const int & value) { counter = value; }

	// �������� ������ � �������
	static int GetIndex(const int & x, const int & y) { return y * maxX + x; }
	// �������� ������������ ��������
	static void SetMaxX(const int & value) { maxX = value; }
private:
	// �������
	int counter;

	// ��������� �� ��� X
	int x;
	// ��������� �� ��� Y
	int y;
	// ������ � �������
	int index;

	// ������������ ��������� �� ��� X
	static int maxX;
};