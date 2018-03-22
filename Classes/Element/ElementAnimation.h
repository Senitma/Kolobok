#pragma once

#include "cocos2d.h"

using namespace cocos2d;

// ������������ ��������� �����������
enum SideType;
// ������������ ��������� ��������
enum class AnimationType;

// �������� ��������
class ElementAnimation
{
public:
	// ������������� ���������
	ElementAnimation() {}

	// �������� ��������
	void LoadAnimation(Node * node, const float & interval, const int & frameCount, const int & width, const int & height, const SideType & startSide);
	// ������������ ��������
	void RunAnimation(AnimationType type);
private:
	// ������� ������ ��� ��������
	Sprite * mainSprite;

	// ������ ������ ��� ��������
	Vector<SpriteFrame *> leftupFrames;
	// ������ ������ ��� ��������
	Vector<SpriteFrame *> upleftFrames;
	// ������ ������ ��� ��������
	Vector<SpriteFrame *> uprightFrames;
	// ������ ������ ��� ��������
	Vector<SpriteFrame *> rightupFrames;
	// ������ ������ ��� ��������
	Vector<SpriteFrame *> rightdownFrames;
	// ������ ������ ��� ��������
	Vector<SpriteFrame *> downrightFrames;
	// ������ ������ ��� ��������
	Vector<SpriteFrame *> downleftFrames;
	// ������ ������ ��� ��������
	Vector<SpriteFrame *> leftdownFrames;
};