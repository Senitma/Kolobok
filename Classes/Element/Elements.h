#pragma once

// ����� ���������� ������� ��������
class Element;
// ������������ ��������� ����
enum class ElementNameType;
// ������������ ��������� �����
enum ClassType;
// ������������ ��������� �����������
enum SideType;

// ������ ���������� ����������
namespace Elements
{
	// �������� ��������
	Element Create(ElementNameType name, int x, int y);
	// �������� ��������
	Element Create(ElementNameType name, SideType side, int x, int y);
};