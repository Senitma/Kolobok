#pragma once

#include "cocos2d.h"

// ����� ���������
class Axes : public cocos2d::Ref
{
public:
	// ������������� ����������
	Axes() : Axes(0, 0) {};
	// ������������� ����������
	Axes(const int &x, const int &y) { SetX(x); SetY(y); };

	// �������� ��������� �� ��� X
	virtual int GetX() const { return x; };
	// �������� ��������� �� ��� Y
	virtual int GetY() const { return y; };
	// �������� ��������� �� ��� X
	virtual void SetX(const int &value) { x = value; };
	// �������� ��������� �� ��� Y
	virtual void SetY(const int &value) { y = value; };

	// �������� ������������ ��������� �� ��� X
	static int GetMaxForX() { return maxForX; };
	// �������� ������������ ��������� �� ��� Y
	static int GetMaxForY() { return maxForY; };

	// �������������� � int
	operator int() const { return y * maxForX + x; };
	// ��������� ���� ���������
	bool operator==(const Axes &value) { return ((x == value.GetX()) && (y == value.GetY())); };
	// ��������� ���� ���������
	bool operator!=(const Axes &value) { return ((x != value.GetX()) || (y != value.GetY())); };
protected:
	// ��������� �� ��� X
	int x;
	// ��������� �� ��� Y
	int y;
	// ������������ ��������� �� ��� X
	static int maxForX;
	// ������������ ��������� �� ��� Y
	static int maxForY;
};