//#pragma once
//
//#include "OptionForMove.h"
//
//// ��������� ����� ��� ��������������
//class OptionForPatrol : public OptionForMove
//{
//public:
//	// �������� ������������� �������
//	bool GetPatrol() { return isPatrol; };
//	// ������ ������������� �������
//	void SetPatrol(bool value) { isPatrol = value; };
//	// �������� ������������� �������� �� �����
//	bool GetCircle() { return isCircle; };
//	// ������ ������������� �������� �� �����
//	void SetCircle(bool value) { isCircle = value; };
//	// �������� ������������� ��������������� � ����� ����
//	bool GetDestroyInEnd() { return isDestroyInEnd; };
//	// ������ ������������� ��������������� � ����� ����
//	void SetDestroyInEnd(bool value) { isDestroyInEnd = value; };
//
//	// ���������� ������
//	void Update() override;
//protected:
//	// ������������� ��������������
//	bool isPatrol;
//	// �������������� �� �����
//	bool isCircle;
//	// ��������������� � ����� ����
//	bool isDestroyInEnd;
//private:
//	// ������ ������� �������� �����
//	int currentIndex;
//	// ������������� ����������� (������� ���� � �������� �������)
//	bool isReturn;
//	// ��������� ����� ������
//	void CalcNewIndex();
//};