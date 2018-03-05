#pragma once

#include "OptionForOneStep.h"
#include "MoveType.h"

// ����� ��� �������� ��������
class OptionForMove : public OptionForOneStep
{
public:
	// ������ �������� �����
	void SetParent(AdvancedElement * parent) override;
	// �������� ������������� ���� ��������
	MoveType GetMoveType() { return moveType; };
	// ������ ������������� ���� ��������
	void SetMoveType(MoveType value) { this->moveType = value; };

	// ���������� ������
	virtual void Update() override;
	// ����������� �������
	virtual bool MoveTo(int x, int y) override;
protected:
	// ��� �����������
	MoveType moveType;
private:
	// ������ ����� ��� ��������
	cocos2d::Vector<FieldPoint *> points;
	// �������� ����
	cocos2d::Vector <FieldPoint *> GeneratePath(MoveType type, int x, int y);
	// �������� ���� �� ������
	cocos2d::Vector <FieldPoint *> GenerateLinePath(int x, int y);
	// �������� ���� � ����� �����������
	cocos2d::Vector <FieldPoint *> GenerateByPassPath(int x, int y);

	// ����������� �������
	bool MoveTo(MoveType type, int x, int y);
};