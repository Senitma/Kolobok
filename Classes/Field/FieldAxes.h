#pragma once

#include "Axes.h"

// ����� ��������� �� ����
class FieldAxes : public Axes
{
public:
	// ������������� ����������
	FieldAxes() : FieldAxes(0, 0) {};
	// ������������� ����������
	FieldAxes(const int &x, const int &y) : Axes(x, y) {};

	// �������� ������������ ��������� �� ��� X
	int GetOriginalX() const { return originalX; };
	// �������� ������������ ��������� �� ��� Y
	int GetOriginalY() const { return originalY; };
	// �������� ������������� ������ �� ������� ���� 
	bool GetOutsideStatus() const { return CheckOutside(); };

	// �������� ��������� �� ��� X
	void SetX(const int &value) override;
	// �������� ��������� �� ��� Y
	void SetY(const int &value) override;

	// �������������� ��������� �� ��� X � �������� �����
	int ToLeft() const { return ConvertToLeft(x); };
	// �������������� ��������� �� ��� Y � �������� ������
	int ToTop() const { return ConvertToLeft(y); };
	// �������������� ���������� � ������
	cocos2d::Vec2 ToVec2() const { ConvertToVec2(x, y); };

	// �������������� �������� � ����������
	static int ConvertToX(const int &value);
	// �������������� �������� � ����������
	static int ConvertToY(const int &value);
	// �������������� �������� � ����������
	static FieldAxes ConvertToXY(const int &left, const int &top) { return FieldAxes(ConvertToX(left), ConvertToY(top)); };
	// �������������� ���������� � ������
	static cocos2d::Vec2 ConvertToVec2(const int &x, const int &y);
	// �������������� ���������� X � �������� �����
	static int ConvertToLeft(const int &value);
	// �������������� ���������� Y � �������� ������
	static int ConvertToTop(const int &value);

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
protected:
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
private:
	// ������������ ��������� �� ��� X
	int originalX;
	// ������������ ��������� �� ��� Y
	int originalY;

	// ��������� ����� �� ���� ����
	bool CheckOutside() const;
};