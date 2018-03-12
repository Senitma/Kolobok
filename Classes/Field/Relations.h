#pragma once

// ������������ ��������� �����
enum ClassType;
// ������������ ��������� �����������
enum class ResultType;
// ������ ������� ���������� �������������� ���������
namespace Relations
{
	// ������ �������������� ���� ����� ������ � ���� �� ������
	ResultType DoubleCalc(ClassType type);
	// ������ ��������������
	ResultType Calc(int SumOfTypes);

	// �������� ����������� ����������
	bool CanAdd(ClassType type, int sumOfTypes);
	// �������� ����������� �����������
	bool CanDestroy(ClassType type);
};