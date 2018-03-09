#pragma once

#include "BaseAxes.h"

// ����� ��������� � ���������������
class TagAxes : public BaseAxes
{
public:
	// ������������� ����������
	TagAxes() : TagAxes(0, 0, 0) {};
	// ������������� ����������
	TagAxes(const int &x, const int &y) : TagAxes(x, y, 0) {};
	// ������������� ����������
	TagAxes(const int &x, const int &y, const int &tag) : BaseAxes(x, y) { SetTag(tag); };
	// ������������� ����������
	TagAxes(BaseAxes &value) { operator=(value); };

	// �������� �������������
	int GetTag() const { return tag; };
	// �������� �������������
	void SetTag(int value) { tag = value; };

	// ������������ ������ ��������
	void operator=(const BaseAxes &value) { x = value.GetX(); y = value.GetY(); };
	// ��������� ���� ���������
	bool operator==(const TagAxes &value) { return ((x == value.GetX()) && (y == value.GetY() && (tag == value.GetTag()))); };
	// ��������� ���� ���������
	bool operator!=(const TagAxes &value) { return ((x != value.GetX()) || (y != value.GetY() || (tag != value.GetTag()))); };
private:
	// �������������
	int tag;
};