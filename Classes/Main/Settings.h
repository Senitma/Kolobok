#pragma once

// �������� ��������� ����������
namespace Settings
{
#pragma region ��������� ����

	// ������ ����
	const int FIELDWIDTHSIZE = 1280;
	// ������ ����
	const int FIELDHEIGHTSIZE = 960;
	// ������������� FPS
	const bool SHOWFPS = true;

	// ������ ����������
	const int NODEWIDTH = 64;
	// ������ ����������
	const int NODEHEIGHT = 64;
	// ������ ������
	const int CELLWIDTHSIZE = 0;
	// ������ ������
	const int CELLHEIGHTSIZE = 0;
	// ������� ������
	const int CELLDEPTHSIZE = 0;
	// ������ ������
	const int GAPWIDTHSIZE = 0;
	// ������ ������
	const int GAPHEIGHTSIZE = 0;

#pragma endregion
#pragma region ��������� ����

	// ���������� ������ �� �����������
	extern int HORIZONTALCELLCOUNT;
	// ���������� ������ �� ���������
	extern int VERTICALCELLCOUNT;

	// ������ ����� ��� ��������
	extern int MAPINDEX;
	// �������� ����������� ���������
	extern float MOVESPEED;
	// �������� �������� ���������
	extern float ROTATESPEED;
	// ������ �������� �������
	extern float CREATEFIREBALLINTERVAL;
	// �������� �������
	extern float FIREBALLSPEED;

#pragma endregion
};