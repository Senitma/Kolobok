#pragma once

#include "FieldAxes.h"

// ����� ��������� ����
class FieldSettings : FieldAxes
{
public:
	// �������� ������������ ��������� �� ��� X
	static void SetMaxForX(const int &value) { maxForX = value; };
	// �������� ������������ ��������� �� ��� Y
	static void SetMaxForY(const int &value) { maxForY = value; };

	// �������� ������ ������ ����
	static void SetNodeWidth(const int &value) { nodeWidth = value; };
	// �������� ������ ������ ����
	static void SetNodeHeight(const int &value) { nodeHeight = value;; };
	// �������� ������ ������ ������
	static void SetCellWidth(const int &value) { cellWidth = value; };
	// �������� ������ ������ ������
	static void SetCellHeight(const int &value) { cellHeight = value; };
	// �������� ������ ������� ������
	static void SetCellDepth(const int &value) { cellDepth = value; };
	// �������� ������ ������ ����
	static void SetFieldWidth(const int &value) { fieldWidth = value; };
	// �������� ������ ������ ����
	static void SetFieldHeight(const int &value) { fieldHeight = value; };
	// �������� ������ ������ ������
	static void SetGapWidth(const int &value) { gapWidth = value; };
	// �������� ������ ������ ������
	static void SetGapHeight(const int &value) { gapHeight = value; };
};