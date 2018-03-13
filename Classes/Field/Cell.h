#pragma once

#include "list"
#include "Element\Element.h"

// ������������ ��������� �����������
enum class ResultType;

// ����� �������� ���������
class Cell
{
public:
	// ������������� ����������
	Cell(const int & x, const int & y);

	// �������� ��������� �� ��� X
	int GetX() const { return x; };
	// �������� ��������� �� ��� Y
	int GetY() const { return y; };

	// �������� ����������� ���������� ��������
	bool CanAddElement(const ClassType & type) const;
	// �������� �������
	ResultType AddElement(Element & item);
	// ��������� ������� ����� � ������ ���������
	bool ContainName(const ElementNameType & nodename) const;
	// ��������� ������� ����� � ������ ���������
	bool ContainType(const ClassType & type) const;
	// ��������� ������� ��������
	bool ContainElement(const Element & item) const;
	// ������� �������
	ResultType RemoveElement(Element & item);
	// ������� ��� ��������
	void RemoveElements() { Destroy(true); };
private:
	// ��������� ������ �� ��� X
	int x;
	// ��������� ������ �� ��� Y
	int y;
	// ����� ���������
	std::list<Element> items;

	// ��������� ������� ������������� ���������
	ClassType GetDoubleElements() const;
	// ������� ��� ���� � ����
	int GetAllTypes() const;
	// ��������� �������������� �����
	ResultType CheckRelations();
	// ����������� ���������
	void Destroy() { Destroy(false); };
	// ����������� ���������
	void Destroy(const bool & allItems);

	// �������� ������������ �� ���������
	Cell() = delete;
};