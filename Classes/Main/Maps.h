#pragma once

// ������������ ��������� ����
enum class MapIndexType
{
	Example,
	Labyrinth,
	AlgorithmTest,
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