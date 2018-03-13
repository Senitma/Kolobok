#pragma once

#include "Option\ISOption.h"

// ����� �������� ��������
class OptionForCreate : public ISOption
{
public:

	// ������������� ����������
	OptionForCreate(Element & parent);

	// �������� ��� ������������ ��������
	ElementNameType GetName() { return nodeName; };
	// ������ ��� ������������ ��������
	void SetName(ElementNameType value) { nodeName = value; };
	// �������� �������� �� ��� X
	int GetOffsetX() { return offsetX; };
	// ������ �������� �� ��� X
	void SetOffsetX(int value) { offsetX = value; };
	// �������� �������� �� ��� Y
	int GetOffsetY() { return offsetY; };
	// ������ �������� �� ��� Y
	void SetOffsetY(int value) { offsetY = value; };
	// �������� ���������� ��������
	bool GetRotate() { return isRotate; };
	//������ ���������� ��������
	void SetRotate(bool value) { isRotate = value; };

	// �������� ��������
	void Create();

protected:

	// ��� ������������ ��������
	ElementNameType nodeName;
	// �������� �� ��� X
	int offsetX;
	// �������� �� ��� Y
	int offsetY;
	// ������������� ���������� ��������
	bool isRotate;
};