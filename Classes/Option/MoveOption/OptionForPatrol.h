#pragma once

#include "OptionForMove.h"

// ������������ ��������� ����� ��������
enum class PatrolType
{
	// �� �����
	None = 0,
	// �� �����
	Circle,
	// �� ��������
	RoundTrip,
	// ����������� � ����� ��������
	DestroyWay
};

// ��������� ����� ��� ��������������
class OptionForPatrol : public OptionForMove
{
public:
	// ������������� ����������
	OptionForPatrol(const Element & parent);

	// �������� ��� �������
	PatrolType GetPatrolType() const { return patrolType; };
	// ������ ��� �������
	void SetPatrolType(const PatrolType & value) { patrolType = value; };

	// ������� �����������
	virtual void MoveFinished() override;
private:
	// ��� �������
	PatrolType patrolType;
	// ������ �� ������ ����� ��� ������� � ��������
	std::queue<Axes> & patrolPoints;
};