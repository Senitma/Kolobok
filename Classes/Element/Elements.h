#pragma once

// ����� ���������� ������� ��������
class Element;
// ������������ ��������� ����
enum class ElementNameType;
// ������������ ��������� �����
enum ClassType;
// ������������ ��������� �����������
enum class SideType;

// ������ ���������� ����������
namespace Elements
{
	// �������� ��������
	Element Create(ElementNameType name, int x, int y);
	// �������� ��������
	Element Create(ElementNameType name, SideType side, int x, int y);
};