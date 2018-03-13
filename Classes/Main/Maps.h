#pragma once

// ������������ ��������� ����
enum class MapIndexType
{
	Example,
	Labyrinth,
	Empty
};

// ������ ���������� �������
namespace Maps
{
	// ��������� ����� �� ���������
	void Load();
	// ��������� ����� �� �������
	void Load(MapIndexType index);
	// ������������� �����
	void ReloadMap();
};