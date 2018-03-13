#pragma once

#include "Element\Element.h"
#include "list"

// ������������ ��������� �����������
enum class ResultType;
// ����� �������� ���������
class Cell
{
public:
	// ������������� ����������
	Cell(const int & x, const int & y);

	// �������� ����������� ���������� ��������
	bool CanAddElement(const Element & item) const { return CanAddElement(item.GetType()); };
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