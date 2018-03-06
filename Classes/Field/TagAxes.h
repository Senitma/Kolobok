#pragma once

#include "Axes.h"

// ����� ��������� � ���������������
class TagAxes : public Axes
{
public:
	// ������������� ����������
	TagAxes() : TagAxes(0, 0, 0) {};
	// ������������� ����������
	TagAxes(const int &x, const int &y) : TagAxes(x, y, 0) {};
	// ������������� ����������
	TagAxes(const int &x, const int &y, const int &tag) : Axes(x, y) { SetTag(tag); };
	// ������������� ����������
	TagAxes(Axes &value) { operator=(value); };

	// �������� �������������
	virtual int GetTag() const { return tag; };
	// �������� �������������
	virtual void SetTag(int value) { tag = value; };

	// ������������ ������ ��������
	void operator=(const Axes &value) { x = value.GetX(); y = value.GetY(); };
	// ��������� ���� ���������
	bool operator==(const TagAxes &value) { return ((x == value.GetX()) && (y == value.GetY() && (tag == value.GetTag()))); };
	// ��������� ���� ���������
	bool operator!=(const TagAxes &value) { return ((x != value.GetX()) || (y != value.GetY() || (tag != value.GetTag()))); };
protected:
	// �������������
	int tag;
};