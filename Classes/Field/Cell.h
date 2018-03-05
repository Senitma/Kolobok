#pragma once

#include "cocos2d.h"
#include "Element\Element.h"

class Element;
// ����� �������� ���������
struct Cell : public cocos2d::Ref
{
public:
	// �������� ����������� ���������� ��������
	bool CanAddElement(Element * item);
	// �������� ����������� ���������� ��������
	bool CanAddElement(ClassType type);
	// �������� �������
	void AddElement(Element * item);
	// ��������� ������� ����� � ������ ���������
	bool ContainName(ElementNameType nodename);
	// ��������� ������� ����� � ������ ���������
	bool ContainType(ClassType type);
	// ��������� ������� ��������
	bool ContainElement(Element * item);
	// ������� �������
	void RemoveElement(Element * item);
	// ������� ������� �� �����
	void RemoveElement(ElementNameType nodeName);
	// �������� ������� �� �����
	Element * GetElement(ElementNameType nodename);
	// ������� ��� ��������
	void DestroyAll();
private:
	// ����� ���������
	cocos2d::Vector<Element *> items;

	// ��������� ������� ������������� ���������
	ClassType GetDoubleElements();
	// ������� ��� ���� � ����
	int GetAllTypes();
	// ��������� �������������� �����
	void CheckRelations();
	// ����������� ���������
	void Destroy();
	// ����������� ���������
	void Destroy(bool allItems);
};