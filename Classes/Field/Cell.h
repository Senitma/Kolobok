#pragma once

#include "cocos2d.h"
#include "Element\AdvancedElement.h"
#include "list"

// ����� �������� ���������
struct Cell : public cocos2d::Ref
{
public:
	// �������� ����������� ���������� ��������
	bool CanAddElement(const AdvancedElement & item) const { return CanAddElement(item.GetType()); };
	// �������� ����������� ���������� ��������
	bool CanAddElement(const ClassType & type) const;
	// �������� �������
	void AddElement(AdvancedElement & item);
	// ��������� ������� ����� � ������ ���������
	bool ContainName(const ElementNameType & nodename) const;
	// ��������� ������� ����� � ������ ���������
	bool ContainType(const ClassType & type) const;
	// ��������� ������� ��������
	bool ContainElement(const AdvancedElement & item) const;
	// ������� �������
	void RemoveElement(AdvancedElement & item);
	// ������� ��� ��������
	void DestroyAll() { Destroy(true); };
private:
	// ����� ���������
	std::list<AdvancedElement> items;

	// ��������� ������� ������������� ���������
	ClassType GetDoubleElements();
	// ������� ��� ���� � ����
	int GetAllTypes() const;
	// ��������� �������������� �����
	void CheckRelations();
	// ����������� ���������
	void Destroy() { Destroy(false); };
	// ����������� ���������
	void Destroy(bool allItems);
};