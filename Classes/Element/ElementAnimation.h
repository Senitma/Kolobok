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
	// ������ ��������
	Animation * leftupAnimation;
	// ��������
	Animate * leftupAnimate;
	// ������ ������ ��� ��������
	Vector<SpriteFrame *> upleftFrames;
	// ������ ��������
	Animation * upleftAnimation;
	// ��������
	Animate * upleftAnimate;

	// ������ ������ ��� ��������
	Vector<SpriteFrame *> uprightFrames;
	// ������ ��������
	Animation * uprightAnimation;
	// ��������
	Animate * uprightAnimate;
	// ������ ������ ��� ��������
	Vector<SpriteFrame *> rightupFrames;
	// ������ ��������
	Animation * rightupAnimation;
	// ��������
	Animate * rightupAnimate;

	// ������ ������ ��� ��������
	Vector<SpriteFrame *> rightdownFrames;
	// ������ ��������
	Animation * rightdownAnimation;
	// ��������
	Animate * rightdownAnimate;
	// ������ ������ ��� ��������
	Vector<SpriteFrame *> downrightFrames;
	// ������ ��������
	Animation * downrightAnimation;
	// ��������
	Animate * downrightAnimate;

	// ������ ������ ��� ��������
	Vector<SpriteFrame *> downleftFrames;
	// ������ ��������
	Animation * downleftAnimation;
	// ��������
	Animate * downleftAnimate;
	// ������ ������ ��� ��������
	Vector<SpriteFrame *> leftdownFrames;
	// ������ ��������
	Animation * leftdownAnimation;
	// ��������
	Animate * leftdownAnimate;
};