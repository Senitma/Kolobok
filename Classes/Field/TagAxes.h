#pragma once

#include "Axes.h"

// ����� ��������� � ���������������
class TagAxes : public Axes
{
public:
	// ������������� ����������
	TagAxes() : TagAxes(0, 0, 0) {};
	// ������������� ����������
	TagAxes(const int & x, const int & y) : TagAxes(x, y, 0) {};
	// ������������� ����������
	TagAxes(const int & x, const int & y, const int & tag) : Axes(x, y) { SetTag(tag); };
	// ������������� ����������
	TagAxes(const Axes & value) : TagAxes(value.GetX(), value.GetY(), 0) {};

	// �������� �������������
	int GetTag() const { return tag; };
	// �������� �������������
	void SetTag(int value) { tag = value; };

	// ������������ ������ ��������
	TagAxes operator=(const Axes & value) { return TagAxes(value); };
	// ��������� ���� ���������
	bool operator==(const TagAxes & value) const { return ((x == value.GetX()) && (y == value.GetY() && (tag == value.GetTag()))); };
	// ��������� ���� ���������
	bool operator!=(const TagAxes & value) const { return ((x != value.GetX()) || (y != value.GetY() || (tag != value.GetTag()))); };
private:
	// �������������
	int tag;
};