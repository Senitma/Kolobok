#pragma once

// ������� ����� ��� ���� ���������
class BaseAxes
{
public:
	// ������������� ����������
	BaseAxes() : BaseAxes(0, 0) {};
	// ������������� ����������
	BaseAxes(const int &x, const int &y) { SetX(x); SetY(y); };

	// �������� ��������� �� ��� X
	virtual int GetX() const { return x; };
	// �������� ��������� �� ��� Y
	virtual int GetY() const { return y; };
	// �������� ��������� �� ��� X
	virtual void SetX(const int &value) { x = value; };
	// �������� ��������� �� ��� Y
	virtual void SetY(const int &value) { y = value; };

	//// ��������� ���� ���������
	//bool operator==(const BaseAxes &value) { return ((x == value.GetX()) && (y == value.GetY())); };
	//// ��������� ���� ���������
	//bool operator!=(const BaseAxes &value) { return ((x != value.GetX()) || (y != value.GetY())); };
protected:
	// ��������� �� ��� X
	int x;
	// ��������� �� ��� Y
	int y;
};