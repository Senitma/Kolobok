#pragma once

// ������������ ��������� �����
enum ClassType;
// ������������ ��������� �����������
enum class ResultType;
// ������ ���������� �������������� ���������
static class Relations
{
public:
	// ������ �������������� ���� ����� ������ � ���� �� ������
	static ResultType DoubleCalc(ClassType type);
	// ������ ��������������
	static ResultType Calc(int SumOfTypes);

	// �������� ����������� ����������
	static bool CanAdd(ClassType type, int sumOfTypes);
	// �������� ����������� �����������
	static bool CanDestroy(ClassType type);
};