#pragma once

#include "memory"

namespace cocos2d
{
	// ���� ��� ����������
	class Node;
}
// ������ ��������
class ElementData;
// ������������ ��������� ����
enum class ElementNameType;
// ������������ ��������� �����
enum ClassType;
// ������������ ��������� �����������
enum class SideType;
// ���������� ��������
class Axes;

// ����� ���������� ������� ��������
class Element
{
public:
	// ������������� ����������
	Element(cocos2d::Node * node, ElementNameType name, ClassType type);
	// ����������� ��������
	Element(const Element&);
	// �������� ������
	~Element();
	// ��������� �������������� �������� ����������
	static void OffAutoDrawDelete();

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
	Axes GetAxes() const;

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
	// �������� ������ ��������
	bool GetDestroyStatus() const;
	// �������� ������ ��������
	void SetDestroyStatus(const bool & value);

	// �������� ����� ��� ��������������
	void AddPoint(const int & x, const int & y);
	// �������� ����� ��� ��������������
	Axes GetPoint(const int & index) const;
	// �������� ���������� ����� ��� ��������������
	int GetPointLength() const;

	// ����������� ��������
	Element operator= (const Element & value) const;
	// ��������� ���� ���������
	bool operator== (const Element & value) const;
	// ��������� ���� ���������
	bool operator!= (const Element & value) const;
private:
	// ������ ��������
	std::shared_ptr<ElementData> data;

	// �������� ��������� �� ��� X
	void SetX(const int & value);
	// �������� ��������� �� ��� Y
	void SetY(const int & value);
	// �������� ������� ����������� ����������
	void SetOrder(const int & value);

	// �������� ��������� ��������
	friend void SetAxes(Element & element, const int & x, const int & y);

	// �������� ������������ �� ���������
	Element() = delete;
};