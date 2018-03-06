#pragma once

#include "BaseAxes.h"

// ����� ��������� �� ����
class FieldAxes : public BaseAxes
{
public:
	// ������������� ����������
	FieldAxes() : FieldAxes(0, 0) {};
	// ������������� ����������
	FieldAxes(const int &x, const int &y) : BaseAxes(x, y) {};

	// �������� ������������ ��������� �� ��� X
	int GetOriginalX() const { return originalX; };
	// �������� ������������ ��������� �� ��� Y
	int GetOriginalY() const { return originalY; };
	// �������� ������������� ������ �� ������� ���� 
	bool GetOutsideStatus() const { return CheckOutside(); };

	// �������� ��������� �� ��� X
	void SetX(const int &value) override;
	// �������� ��������� �� ��� Y
	void SetY(const int &value) override;

	// �������������� ��������� �� ��� X � �������� �����
	int ToLeft() const;
	// �������������� ��������� �� ��� Y � �������� ������
	int ToTop() const;
	// �������������� ���������� � ������
	cocos2d::Vec2 ToVec2() const;
private:
	// ������������ ��������� �� ��� X
	int originalX;
	// ������������ ��������� �� ��� Y
	int originalY;

	// ��������� ����� �� ���� ����
	bool CheckOutside() const;
};