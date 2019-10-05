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
	Cell();
	// �������� ������
	~Cell();

	// �������� ��������� �� ��� X
	int GetX() const { return x; };
	// �������� ��������� �� ��� Y
	int GetY() const { return y; };
	// �������� ��������� ����� ������
	void SetIndex(const int & index);

	// �������� ����������� ���������� ��������
	bool CanAddElement(const ClassType & type) const;
	// ��������� ������� ����� � ������ ���������
	bool ContainName(const ElementNameType & nodename) const;
	// ��������� ������� ����� � ������ ���������
	bool ContainType(const ClassType & type) const;
	// ��������� ������� ��������
	bool ContainElement(const Element & item) const;
	// �������� �������
	ResultType AddElement(Element & item);
	// ������� �������
	ResultType RemoveElement(Element & item);
	// ������� ��� ��������
	void RemoveElements() { Destroy(true); };
private:
	// ����� ��������� ��������� ��������
	class MoveElement : public Element
	{
	public:
		// ������������� ����������
		MoveElement(const Element & value) : Element(value) {}
		// ��������� ��������� ��������
		void SetPosition(const int & x, const int & y, const int & order) { SetX(x); SetY(y); SetOrder(order); }

		// ��������� ���� ���������
		bool operator== (const Element & value) const { return GetID() == value.GetID(); }
		// ��������� ���� ���������
		bool operator!= (const Element & value) const { return GetID() != value.GetID(); }
	};

	// ��������� ������ �� ��� X
	int x;
	// ��������� ������ �� ��� Y
	int y;
	// ����� ���������
	std::vector<MoveElement> items;

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
};