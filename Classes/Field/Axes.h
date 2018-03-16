#pragma once

// ���������� ��������
struct Axes
{
public:
	// ������������� ����������
	Axes() : Axes(0, 0) {};
	// ������������� ����������
	Axes(const int & x, const int & y) { SetX(x); SetY(y); };

	// �������� ��������� �� ��� X
	int GetX() const { return x; };
	// �������� ��������� �� ��� Y
	int GetY() const { return y; };
	// �������� ��������� �� ��� X
	void SetX(const int & value) { x = value; };
	// �������� ��������� �� ��� Y
	void SetY(const int & value) { y = value; };
protected:
	// ��������� �� ��� X
	int x;
	// ��������� �� ��� Y
	int y;
};