#pragma once

#include "cocos2d.h"
#include "Element\AdvancedElement.h"
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
	static bool CanAddElement(AdvancedElement * item);
	// �������� ����������� ���������� ��������
	static bool CanAddElement(ClassType type, int x, int y);
	// �������� �������
	static void AddElement(AdvancedElement & item);
	// ��������� ������� ����� � ������ ���������
	static bool ContainName(ElementNameType name, int x, int y);
	// ��������� ������� ��������
	static bool ContainElement(AdvancedElement * item);
	// ������ �������
	static void RemoveElement(AdvancedElement & item);
	// ������� ��������
	static void Destroy(int x, int y);

	// ������� ����� � �������
	static std::vector<TagAxes> CreateBlockMap();
};