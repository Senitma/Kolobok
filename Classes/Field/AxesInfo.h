#pragma once

// ����� ���������
struct Axes;

// ����� ���������� ��� ���������
class AxesInfo
{
public:

	// ��������������� ��������� � ������
	static int ConvertToIndex(const Axes & value);
	// ��������������� ��������� � ������
	static int ConvertToIndex(const int &x, const int &y);
	// �������������� �������� � ����������
	static int ConvertToX(const int &value);
	// �������������� �������� � ����������
	static int ConvertToY(const int &value);
	// ��������������� ������� � ����������
	static Axes ConvertToAxes(const int &value);
	// �������������� �������� � ����������
	static Axes ConvertToAxes(const int &left, const int &top);
	// �������������� ���������� X � �������� �����
	static int ConvertToLeft(const int &value);
	// �������������� ���������� Y � �������� ������
	static int ConvertToTop(const int &value);

};