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
	// FPS
	const float FPS = 60;

	// ������ ����������
	const int NODEWIDTH = 128;
	// ������ ����������
	const int NODEHEIGHT = 128;
	// ������ ������
	const int CELLWIDTH = 128;
	// ������ ������
	const int CELLHEIGHT = 70;

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
	const float MOVESPEED = 3.1F;
	// �������� �������� ���������
	const float ROTATESPEED = 4.5F;
	// ������ �������� �������
	const float CREATEFIREBALLINTERVAL = 240.0F;
	// �������� �������
	const float FIREBALLSPEED = 5.0F;

#pragma endregion
};