#pragma once

// ������������ ��������� ����� ��������
enum class AnimationType
{
	// ��� �� �����
	None,
	// �������� �����������
	MoveToLeft,
	// �������� �����������
	MoveToUp,
	// �������� �����������
	MoveToRight,
	// �������� �����������
	MoveToDown,
	// �������� ��������
	RotateLeftToUp,
	// �������� ��������
	RotateUpToLeft,
	// �������� ��������
	RotateUpToRight,
	// �������� ��������
	RotateRightToUp,
	// �������� ��������
	RotateRightToDown,
	// �������� ��������
	RotateDownToRight,
	// �������� ��������
	RotateDownToLeft,
	// �������� ��������
	RotateLeftToDown
};