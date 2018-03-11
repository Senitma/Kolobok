#pragma once

// ����� ���������
class Axes
{
public:
	// ������������� ����������
	Axes() : Axes(0, 0) {};
	// ������������� ����������
	Axes(const int & x, const int & y) { SetX(x); SetY(y); };

	// �������� ��������� �� ��� X
	virtual int GetX() const { return x; };
	// �������� ��������� �� ��� Y
	virtual int GetY() const { return y; };
	// �������� ��������� �� ��� X
	virtual void SetX(const int & value) { x = value; };
	// �������� ��������� �� ��� Y
	virtual void SetY(const int & value) { y = value; };
protected:
	// ��������� �� ��� X
	int x;
	// ��������� �� ��� Y
	int y;
};