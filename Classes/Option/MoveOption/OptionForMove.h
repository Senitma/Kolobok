#pragma once

#include "queue"
#include "OptionForOneStep.h"
#include "Field\Axes.h"

// ������������ ��������� ����� �����������
enum class MoveType;

// ����� ��� �������� ��������
class OptionForMove : public OptionForOneStep
{
public:
	// ������������� ����������
	OptionForMove(const Element & parent) : OptionForOneStep(parent) {}

	// �������� ������������� ���� ��������
	MoveType GetMoveType() { return moveType; };
	// ������ ������������� ���� ��������
	void SetMoveType(MoveType value) { moveType = value; };

	// ����������� �������
	virtual void MoveTo(const int & x, const int & y) override { MoveTo(moveType, x, y); };
protected:
	// ������� �����������
	virtual void Standed() override;
private:
	// ������� �� ����� ��� ��������
	std::queue<Axes> points;
	// ��� �����������
	MoveType moveType;
	// ����� ��������� �� ��� X
	int nextX;
	// ����� ��������� �� ��� Y
	int nextY;

	// �������� ����
	std::queue<Axes> OptionForMove::GeneratePath(const MoveType & type, const int & x, const int & y);
	// �������� ���� �� ������
	std::queue<Axes> OptionForMove::GenerateLinePath(const int & x, const int & y);
	// �������� ���� � ����� �����������
	std::queue<Axes> OptionForMove::GenerateByPassPath(const int & x, const int & y);

	// ����������� �������
	void MoveTo(const MoveType & type, const int & x, const int & y);
};