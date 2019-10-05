#pragma once

// ������������ ��������� �����
enum ClassType;
// ����� ���������
struct Axes;

// ���������� ��� ���������
namespace AxesInfo
{
	// ��������������� ��������� � ������
	int ConvertToIndex(const Axes & value);
	// ��������������� ��������� � ������
	int ConvertToIndex(const int &x, const int &y);
	// ��������������� ������� � ����������
	Axes ConvertToAxes(const int &value);
	// �������������� �������� � ����������
	Axes ConvertToAxes(const int &left, const int &top);
	// �������������� ���������� � ��������
	Axes ConvertToOffset(const ClassType & type, const int & x, const int & y);

	extern int ANGLE;
};