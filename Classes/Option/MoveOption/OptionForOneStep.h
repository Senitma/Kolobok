#pragma once

#include "Option\BaseClass\ISOption.h"
#include "Option\BaseClass\ISInterval.h"

// ����� ��� ����������� �� ���� ������
class OptionForOneStep : public ISOption, ISInterval
{
public:
	// �������� �������� �����������
	int GetMoveSpeed() { return moveSpeed; };
	// ������ �������� ����������
	void SetMoveSpeed(int value) { moveSpeed = value; };
	// �������� ����������� ��������
	bool GetRotate() { return isRotate; };
	// ������ ����������� ��������
	void SetRotate(bool value) { isRotate = value; };
	// �������� �������� ��������
	int GetRotateSpeed() { return rotateSpeed; };
	// ������ ����������� ��������
	void SetRotateSpeed(int value) { rotateSpeed = value; };

	// ���������� ������
	virtual void Update() override;
	// ����������� �������
	virtual bool MoveTo(int x, int y);

	// ������ �������� �����
	virtual void SetParent(AdvancedElement * value) override { parent = value; parent->AddOption(this); };
protected:
	// �������� �����������
	int moveSpeed;
	// ������������� ����������� ��������
	bool isRotate;
	// �������� ��������
	int rotateSpeed;

	// ����� ���������� �� ��� X
	int x;
	// ����� ���������� �� ��� Y
	int y;
	// ������������� ���������
	bool isFreeze;
private:
	// ������ ���������� �� ��� X
	int oldX;
	// ������ ���������� �� ��� Y
	int oldY;

	// ������� ����� �����
	int currentLeft;
	// ������� ������ ������
	int currentTop;
	// ����� ������ �����
	int left;
	// ����� ������ ������
	int top;
	// ������ ������ ����
	int moveStepSize;
	// ���������� ������ �������� ��� �����������
	bool isMoveLock;

	// ����� �������
	SideType side;
	// ������� �������� ��������
	int currentRotate;
	// ����� �������� ��������
	int rotate;
	// ������ ������ ����
	int rotateStepSize;
	// ���������� ������ �������� ��� ��������
	bool isRotateLock;

	// ��������� ��� ������ ���������
	void FillVariableForNewPoint(int x, int y);
};