#pragma once

#include "Axes.h"

// ����� �������� ���������
class AxesSettings : Axes
{
	// �������� ������������ ��������� �� ��� X
	static void SetMaxForX(const int &value) { maxForX = value; };
	// �������� ������������ ��������� �� ��� Y
	static void SetMaxForY(const int &value) { maxForY = value; };
};