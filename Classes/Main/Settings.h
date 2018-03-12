#pragma once

// �������� ��������� ����������
class Settings
{
public:

#pragma region ��������� ����

	// ������ ����
	static const int FIELDWIDTHSIZE = 1280;
	// ������ ����
	static const int FIELDHEIGHTSIZE = 960;
	// ������������� FPS
	static const bool SHOWFPS = true;

	// ������ ����������
	static const int NODEWIDTH = 64;
	// ������ ����������
	static const int NODEHEIGHT = 64;
	// ������ ������
	static const int CELLWIDTHSIZE = 0;
	// ������ ������
	static const int CELLHEIGHTSIZE = 0;
	// ������� ������
	static const int CELLDEPTHSIZE = 0;
	// ������ ������
	static const int GAPWIDTHSIZE = 0;
	// ������ ������
	static const int GAPHEIGHTSIZE = 0;

#pragma endregion
#pragma region ��������� ����

	// ���������� ������ �� �����������
	static int HORIZONTALCELLCOUNT;
	// ���������� ������ �� ���������
	static int VERTICALCELLCOUNT;

	// ������ ����� ��� ��������
	static int MAPINDEX;
	// �������� ����������� ���������
	static float MOVESPEED;
	// �������� �������� ���������
	static float ROTATESPEED;
	// ������ �������� �������
	static float CREATEFIREBALLINTERVAL;
	// �������� �������
	static float FIREBALLSPEED;

#pragma endregion
};