#pragma once

#include "queue"
#include "memory"

namespace cocos2d
{
	// ���� ��� ����������
	class Node;
}
namespace cocostudio
{
	namespace timeline
	{
		// ��������
		class ActionTimeline;
	}
}
// ������ ��������
struct ElementData;
// ������������ ��������� ����
enum class ElementNameType;
// ������������ ��������� �����
enum ClassType;
// ������������ ��������� �����������
enum SideType;
// ������������ ��������� ����� ��������
enum class AnimationType;
// ���������� ��������
struct Axes;

// ����� ���������� ������� ��������
class Element
{
public:
	// ������������� ����������
	Element(cocos2d::Node * node, cocostudio::timeline::ActionTimeline * animation, ElementNameType name, ClassType type);
	// ����������� ��������
	Element(const Element & value);
	// �������� ������
	~Element();
	// ��������� �������������� �������� ����������
	static void OffAutoDrawDelete();

	// �������� ������������ �������������
	int GetID() const;
	// �������� ���
	ElementNameType GetName() const;
	// �������� ���
	ClassType GetType() const;
	// �������� ������� ��������
	SideType GetSide() const;
	// �������� �����������
	void SetSide(const SideType & value);

	// �������� ���������� �� ��� X
	int GetX() const;
	// �������� ���������� �� ��� Y
	int GetY() const;
	// �������� ����������
	Axes GetAxes() const;

	// �������� �������� �����
	int GetLeft() const;
	// �������� �������� ������
	int GetTop() const;
	// �������� ��������
	void SetPosition(const int & x, const int & y);
	// �������� ���� ��������
	int GetRotation() const;
	// ������� ���� ��������
	void SetRotation(const int & value);
	// �������� ������ ��������
	bool GetDestroyStatus() const;
	// �������� ������ ��������
	void SetDestroyStatus(const bool & value);

	// ������ ��������
	void RunAnimation(AnimationType type);

	// �������� ����� ��� ��������������
	void AddPoint(const int & x, const int & y);
	// �������� ����� ��� ��������������
	std::queue<Axes> & GetPoints();

	// ����������� ��������
	Element operator= (const Element & value) const;
	// ��������� ���� ���������
	bool operator== (const Element & value) const;
	// ��������� ���� ���������
	bool operator!= (const Element & value) const;
protected:
	// �������� ��������� �� ��� X
	void SetX(const int & value);
	// �������� ��������� �� ��� Y
	void SetY(const int & value);
	// �������� ������� ����������� ����������
	void SetOrder(const int & value);
private:
	// ������ ��������
	std::shared_ptr<ElementData> data;

	// �������� ������������ �� ���������
	Element() = delete;
};