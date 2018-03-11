#pragma once

// ����� ���������
class Axes;
// ����� ��� �������� � �������� �������� ���������
class AxesInfo
{
public:
	// �������� ������������ ��������� �� ��� X
	static int GetMaxForX() { return maxForX; };
	// �������� ������������ ��������� �� ��� Y
	static int GetMaxForY() { return maxForY; };
	// �������� ������ ������ ����
	static int GetNodeWidth() { return nodeWidth; };
	// �������� ������ ������ ����
	static int GetNodeHeight() { return nodeHeight; };
	// �������� ������ ������ ������
	static int GetCellWidth() { return cellWidth; };
	// �������� ������ ������ ������
	static int GetCellHeight() { return cellHeight; };
	// �������� ������ ������� ������
	static int GetCellDepth() { return cellDepth; };
	// �������� ������ ������ ����
	static int GetFieldWidth() { return fieldWidth; };
	// �������� ������ ������ ����
	static int GetFieldHeight() { return fieldHeight; };
	// �������� ������ ������ ������
	static int GetGapWidth() { return gapWidth; };
	// �������� ������ ������ ������
	static int GetGapHeight() { return gapHeight; };

	// ��������������� ��������� � ������
	static int ConvertToIndex(const Axes & value);
	// ��������������� ��������� � ������
	static int ConvertToIndex(const int &x, const int &y) { return y * maxForX + x; };
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
protected:
	// ������������ ��������� �� ��� X
	static int maxForX;
	// ������������ ��������� �� ��� Y
	static int maxForY;

	// ������ ����
	static int nodeWidth;
	// ������ ����
	static int nodeHeight;
	// ������ ������
	static int cellWidth;
	// ������ ������
	static int cellHeight;
	// ������� ������
	static int cellDepth;
	// ������ ����
	static int fieldWidth;
	// ������ ����
	static int fieldHeight;
	// ������ ������
	static int gapWidth;
	// ������ ������
	static int gapHeight;
};