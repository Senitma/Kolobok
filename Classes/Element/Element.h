#pragma once

#include "cocos2d.h"
#include "ElementInfo.h"

// ��������� ���������
class ISInterval;

// ����������� ����� ��������
class Element : ElementInfo
{
public:
	// ������������� ����������
	Element(cocos2d::Node * node, ElementNameType name, ClassType type);

	// �������� �����������
	void SetSide(const SideType & value);
	// �������� ���������� �� ��� X
	void SetX(const int & value);
	// �������� ���������� �� ��� Y
	void SetY(const int & value);
	// �������� ����������
	void SetAxes(const int & x, const int & y);

	// �������� �������� �����
	int GetLeft() const;
	// �������� �������� ������
	int GetTop() const;
	// �������� ��������
	void SetPosition(const int & x, const int & y);
	// �������� ���� ��������
	int GetRotation() const;
	// ������� ���� ��������
	void SetRotation(const int & value);

	// �������� ����� ��� ��������������
	void AddPoint(const int & x, const int & y);
	// �������� ����� ��� ��������������
	BaseAxes GetPoint(const int & index);
	// �������� ���������� ����� ��� ��������������
	int GetPointLength() const;

	// �������� �����
	void AddOption(ISInterval * option);

	// �������� ��������
	bool operator== (const Element & value);
	// �������� ��������
	bool operator!= (const Element & value);
private:
	// �������� ������������ �� ���������
	Element() = delete;
};