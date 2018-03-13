#pragma once

#include "Main\Maps.h"

// ������ �������� ����������
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
	extern const int & HORIZONTALCELLCOUNT;
	// ���������� ������ �� ���������
	extern const int & VERTICALCELLCOUNT;

	// ����� ��� �������� �� ���������
	const MapIndexType DEFAULTMAP = MapIndexType::Empty;

	// �������� ����������� ���������
	const float MOVESPEED = 4;
	// �������� �������� ���������
	const float ROTATESPEED = 4;
	// ������ �������� �������
	const float CREATEFIREBALLINTERVAL = 120;
	// �������� �������
	const float FIREBALLSPEED = 8;

#pragma endregion
};