#pragma once

#include "Element\Element.h"
#include "list"

// ������������ ��������� �����������
enum class ResultType;
// ����� �������� ���������
class Cell : public cocos2d::Ref
{
public:
	// �������� ����������� ���������� ��������
	bool CanAddElement(const Element & item) const { return CanAddElement(item.GetType()); };
	// �������� ����������� ���������� ��������
	bool CanAddElement(const ClassType & type) const;
	// �������� �������
	ResultType AddElement(const Element & item);
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
};