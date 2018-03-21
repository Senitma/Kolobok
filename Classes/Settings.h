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
	const int CELLWIDTH = 64;
	// ������ ������
	const int CELLHEIGHT = 64;

#pragma endregion
#pragma region ��������� ����

	// �������� ����������� �� ��� X
	extern const int & OFFSETX;
	// �������� ����������� �� ��� Y
	extern const int & OFFSETY;

	// ���������� ������ �� �����������
	extern const int & HORIZONTALCELLCOUNT;
	// ���������� ������ �� ���������
	extern const int & VERTICALCELLCOUNT;

	// ����� ��� �������� �� ���������
	const MapIndexType DEFAULTMAP = MapIndexType::Example;

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