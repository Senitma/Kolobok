#pragma once

// ������������ ��������� ����
enum class ElementNameType;
// ������������ ��������� �����
enum class ClassType;
// ������������� ��������� �����������
enum class SideType;
// ����� ������ ��� ��������
class ElementData;
// ����� ���������
class BaseAxes;

// ���������� � ��������
class ElementInfo
{
public:
	// �������� ��� ��������
	ElementNameType GetName() const;
	// �������� ��� ��������
	ClassType GetType() const;
	// �������� ����������� ��������
	SideType GetSide() const;
	// �������� ��������� �� ��� X
	int GetX() const;
	// �������� ��������� �� ��� Y
	int GetY() const;
	// �������� ���������� ��������
	BaseAxes getAxes() const;

	// �������� ������
	void Destroy();

	// �������� ��������
	bool operator== (const ElementInfo & value);
	// �������� ��������
	bool operator!= (const ElementInfo & value);
	// �������� ������
	virtual ~ElementInfo() { Destroy(); };
protected:
	// ����� ������ ��� ��������
	ElementData * data;
};