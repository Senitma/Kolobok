#pragma once

#include "cocos2d.h"
#include "ClassType.h"
#include "ResultType.h"

// ������ ���������� �������������� ���������
class ElementRelations : cocos2d::Ref
{
public:
	// ������ �������������� ���� ����� ������ � ���� �� ������
	static ResultType DoubleCalc(ClassType type);
	// ������ �������������� ���� ����� ������ � ���� �� ������
	static ResultType DoubleCalc(int type);
	// ������ ��������������
	static ResultType Calc(int SumOfTypes);

	// �������� ����������� ����������
	static bool CanAdd(ClassType type, int sumOfTypes);
	// �������� ����������� ����������
	static bool CanAdd(int type, int sumOfTypes);
	// �������� ����������� ����������
	static bool CanAdd(ClassType type, int sumOfTypes, bool smart);
	// �������� ����������� ����������
	static bool CanAdd(int type, int sumOfTypes, bool smart);
	// �������� ����������� �����������
	static bool CanDestroy(ClassType type);
};
