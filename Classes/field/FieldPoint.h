#pragma once

#include "headers.h"

// ����� �����
class FieldPoint : public cocos2d::Ref
{
public:
	// ������������� ����������
	FieldPoint() { x = 0; y = 0; tag = 0; };
	// ������������� ����������
	FieldPoint(int x, int y) { this->x = x, this->y = y, tag = 0; };
	// ������������� ����������
	FieldPoint(int x, int y, int tag) { this->x = x, this->y = y, this->tag = tag; };
	// �������� ���������� �� ��� X
	int GetX();
	// ������ ���������� �� ��� X
	void SetX(int value) { this->x = value; };
	// �������� ���������� �� ��� Y
	int GetY();
	// ������ ���������� �� ��� � Y
	void SetY(int value) { this->y = value; };

	// �������� �������������
	int GetTag() { return tag; };
	// �������� �������������
	void SetTag(int value) { tag = value; };

	// ��������������� ���������� X � ������ �����
	int ToLeft();
	// ��������������� ���������� Y � ������ ������
	int ToTop();

	// ��������������� ������� � ����������
	static int ConvertToX(int left);
	// ��������������� ������� � ����������
	static int ConvertToY(int top);
	// ��������������� �������� � ����������
	static FieldPoint * ConvertToXY(int left, int top);
	// ��������������� ���������� X � ������ �����
	static int ConvertToLeft(int x);
	// ��������������� ���������� Y � ������ ������
	static int ConvertToTop(int y);

	// �������� ������ ������
	static int GetCellWidth();
	// �������� ������ ������
	static int GetCellHeight();
protected:
	// ��������� �� ��� X
	int x;
	// ��������� �� ��� Y
	int y;
	// �������������
	int tag;
};