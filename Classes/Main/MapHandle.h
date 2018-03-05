#pragma once

#include "Headers.h"

// ����� ���������� ������
class MapHandle : public cocos2d::Ref
{
public:
	// ��������� ����� �� ���������
	static void LoadDefault();
	// ��������� ����� �� �������
	static void LoadForIndex(int index);
	// ������������� �����
	static void ReloadMap();
	// ��������� ������� ���� �� �������� ��������� �� ������
	static bool CheckPath();
private:
	// ��������� ����� �� ������� 0
	static void LoadForIndex0();
	// ��������� ����� �� ������� 1
	static void LoadForIndex1();
	// ��������� ����� �� ������� 2
	static void LoadForIndex2();
};