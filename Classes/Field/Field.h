#pragma once

#include "vector"
#include "Element\Element.h"

// ������������ ��������� ��������� ����
enum class GameStatusType;
// ����� ������
class Vertex;

// ������ ���������� �����
namespace Field
{
	// ������
	void WinGame();
	// �������
	void LoseGame();
	// ������������� ����
	void Reload();
	// �������� ������� ��������� ����
	GameStatusType GetCurrentGameStatus();

	// �������� ������ �� ����������
	cocos2d::Node * GetInstance();
	// ���������������� ������
	void InitCells();
	// ���������� �������� �� ����
	void DrawElement(cocos2d::Node * item);

	// �������� ����������� ���������� ��������
	bool CanAddElement(const ClassType & type, const int & x, const int & y);
	// ��������� ������� ����� � ������ ���������
	bool ContainName(const ElementNameType & name, const int & x, const int & y);
	// �������� �������
	void AddElement(Element & value, const int & x, const int & y);
	// ����������� ��������
	void MoveElement(Element & item, const int & x, const int & y);
	// ������ �������
	void RemoveElement(Element & item);
	// ������� ��������
	void Destroy(const int & x, const int & y);

	// ������� ����� � �������
	std::vector<Vertex> CreateBlockMap();
	// ��������� ������� ���� �� �������� ��������� �� ������
	bool CheckPath();
};