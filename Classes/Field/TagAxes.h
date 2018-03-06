#pragma once

#include "Axes.h"

// ����� ��������� � ���������������
class TagAxes : Axes
{
public:
	// ������������� ����������
	TagAxes() {};
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