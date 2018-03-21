#pragma once

#include "Option\ISOption.h"

// ������������ ��������� �����������
enum SideType;

// ����� �������� ��������
class OptionForCreate : public ISOption
{
public:
	// ������������� ����������
	OptionForCreate(Element & parent);

	// �������� ��� ������������ ��������
	ElementNameType GetName() const { return nodeName; }
	// ������ ��� ������������ ��������
	void SetName(ElementNameType value) { nodeName = value; }
	// �������� ����������� ��������
	SideType GetSide() const { return side; }
	// ������� ����������� ��������
	void SetSide(const SideType & value) { side = value; }

	// �������� �������� �� ��� X
	int GetOffsetX() const { return offsetX; }
	// ������ �������� �� ��� X
	void SetOffsetX(const int & value) { offsetX = value; }
	// �������� �������� �� ��� Y
	int GetOffsetY() const { return offsetY; };
	// ������ �������� �� ��� Y
	void SetOffsetY(const int & value) { offsetY = value; }
	// �������� ���������� ��������
	bool GetRotate() const { return isRotate; };
	//������ ���������� ��������
	void SetRotate(const bool & value) { isRotate = value; }

	// �������� ��������
	void Create();
protected:
	// ��� ������������ ��������
	ElementNameType nodeName;
	// ����������� ��������
	SideType side;

	// �������� �� ��� X
	int offsetX;
	// �������� �� ��� Y
	int offsetY;
	// ������������� ���������� ��������
	bool isRotate;
};