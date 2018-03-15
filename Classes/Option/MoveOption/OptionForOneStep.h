#pragma once

#include "Option\ISInterval.h"

// ����� ��� ����������� �� ���� ������
class OptionForOneStep : public ISInterval
{
public:
	// ������������� ����������
	OptionForOneStep(const Element & parent);

	// �������� �������� �����������
	int GetMoveSpeed() const { return moveSpeed; };
	// ������ �������� ����������
	void SetMoveSpeed(const int & value) { moveSpeed = value; };
	// �������� �������� ��������
	int GetRotateSpeed() const { return rotateSpeed; };
	// ������ ����������� ��������
	void SetRotateSpeed(const int & value) { rotateSpeed = value; };

	// ���������� ������
	virtual void Update() override;
	// ����������� �������
	virtual void MoveTo(const int & x, const int & y);
protected:
	// ������� �����������
	virtual void Standed() {};
	// ��������� ���������� �� ������������ ��������
	bool CheckAxesForNear(const int & x, const int & y) const;
private:
	// ������ ������������ ��������� ���������
	enum StatusType
	{
		// ����� �� �����
		Stand = 0,
		// ��������� ����� ��������
		AfterRotate,
		// ������������
		MoveLeft = 2,
		// ������������
		MoveUp = 4,
		// ������������
		MoveRight = 8,
		// ������������
		MoveDown = 16,
		// ������������
		Move = 30,
		// �������������� 
		RotateUpToLeft = 36,
		// ��������������
		RotateDownToLeft = 48,
		// �������������� 
		RotateLeftToUp = 66,
		// ��������������
		RotateRightToUp = 72,
		// ��������������
		RotateUpToRight = 132,
		// ��������������
		RotateDownToRight = 144,
		// ��������������
		RotateLeftToDown = 258,
		// ��������������
		RotateRightToDown = 264,
		// ��������������
		Rotate = 510
	};

	// �������� �����������
	int moveSpeed;
	// �������� ��������
	int rotateSpeed;

	// ������� ��������� �����
	StatusType currentStatus;
	// ����� ��������� �� ��� X
	int nextX;
	// ����� ��������� �� ��� Y
	int nextY;

	// ������� ��������
	int currentInterval;
	// ������������ ��������
	int maxInterval;
};