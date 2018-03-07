#pragma once

#include "cocos2d.h"
#include "Element\Element.h"
#include "Main\GameStatusType.h"

#include "TagAxes.h"
#include "vector"

class Field : private cocos2d::Ref
{
public:
	// ������� ���
	static cocos2d::Node * CreateBackground();

	// ���������� �������� �� ����
	static void DrawElement(cocos2d::Node * item);
	// ������
	static void WinGame();
	// �������
	static void LoseGame();
	// ������������� ����
	static void Reload();
	// �������� ������� ������ ����
	static GameStatusType GetGameStatus();

	// �������� ����������� ���������� ��������
	static bool CanAddElement(Element * item);
	// �������� ����������� ���������� ��������
	static bool CanAddElement(ClassType type, int x, int y);
	// �������� �������
	static void AddElement(Element *item);
	// ��������� ������� ����� � ������ ���������
	static bool ContainName(ElementNameType name, int x, int y);
	// ��������� ������� ��������
	static bool ContainElement(Element * item);
	// �������� ������� �� ������
	static Element * GetElement(ElementNameType name, int x, int y);
	// ������ �������
	static void RemoveElement(Element *item);
	// ������ ������� �� ��� �����
	static void RemoveElement(ElementNameType name, int x, int y);

	// ������� ����� � �������
	static std::vector<TagAxes> CreateBlockMap();
};