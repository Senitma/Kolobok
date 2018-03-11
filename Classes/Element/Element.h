#pragma once

#include "cocos2d.h"

// ������ ��������
class ElementData;
// ������������ ��������� ����
enum class ElementNameType;
// ������������ ��������� �����
enum ClassType;
// ������������ ��������� �����������
enum class SideType;
// ���������� ��������
class BaseAxes;

// ����� ���������� ���������
class Element
{
public:
	// ������������� ����������
	Element(cocos2d::Node * node, ElementNameType name, ClassType type);
	// ����������� ��������
	Element(const Element&);

	// �������� ���
	ElementNameType GetName() const;
	// �������� ���
	ClassType GetType() const;
	// �������� ������� ��������
	SideType GetSide() const;
	// �������� �����������
	void SetSide(const SideType & value);

	// �������� ���������� �� ��� X
	int GetX() const;
	// �������� ���������� �� ��� Y
	int GetY() const;
	// �������� ����������
	BaseAxes GetAxes() const;
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
	void SetPosition(const int x, const int y);
	// �������� ���� ��������
	int GetRotation() const;
	// ������� ���� ��������
	void SetRotation(const int & value);
	// �������� ������ ��������
	bool GetDestroyStatus() const;
	// �������� ������ ��������
	void SetDestroyStatus(const bool & value);

	// �������� ����� ��� ��������������
	void AddPoint(const int & x, const int & y);
	// �������� ����� ��� ��������������
	BaseAxes GetPoint(const int & index) const;
	// �������� ���������� ����� ��� ��������������
	int GetPointLength() const;

	// ����������� ��������
	Element operator= (const Element & value) const;
	// ��������� ���� ���������
	bool operator== (const Element & value) const;
	// ��������� ���� ���������
	bool operator!= (const Element & value) const;

	// �������� ������
	~Element();
private:
	// ������ ��������
	std::shared_ptr<ElementData> data;

	// �������� ������������ �� ���������
	Element() = delete;
};