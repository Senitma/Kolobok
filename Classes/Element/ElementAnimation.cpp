#include "string"

#include "SideType.h"
#include "AnimationType.h"

#include "ElementAnimation.h"

void ElementAnimation::LoadAnimation(Node * node, const float & interval, const int & frameCount, const int & width, const int & height, const SideType & startSide)
{
	// ������� �������� ������ � ������� ��������
	auto CreateFrames = [&](const std::string & firstSide, const std::string & secondSide, const bool rotate = false) 
	{
		Vector<SpriteFrame *> frames;

		int currentIndex = 1;
		int maxIndex = frameCount;
		int oneStep = 1;

		if (rotate == false)
		{
			frames.pushBack(cocos2d::SpriteFrame::createWithTexture(node->getChildByName<Sprite *>(firstSide)->getTexture(), Rect(0, 0, width, height)));
		}
		else
		{
			frames.pushBack(cocos2d::SpriteFrame::createWithTexture(node->getChildByName<Sprite *>(secondSide)->getTexture(), Rect(0, 0, width, height)));
			currentIndex = frameCount;
			maxIndex = 1;
			oneStep = -1;
		}

		do
		{
			std::string frameName = firstSide + secondSide + std::to_string(currentIndex);
			frames.pushBack(SpriteFrame::createWithTexture(node->getChildByName<Sprite *>(frameName)->getTexture(), Rect(0, 0, width, height)));

			currentIndex += oneStep;
		} while (currentIndex != maxIndex + oneStep);

		if (rotate == false)
		{
			frames.pushBack(cocos2d::SpriteFrame::createWithTexture(node->getChildByName<Sprite *>(secondSide)->getTexture(), Rect(0, 0, width, height)));
		}
		else
		{
			frames.pushBack(cocos2d::SpriteFrame::createWithTexture(node->getChildByName<Sprite *>(firstSide)->getTexture(), Rect(0, 0, width, height)));
		}

		return frames;
	};

	mainSprite = node->getChildByName<Sprite *>("main");

	leftupFrames = CreateFrames("left", "up");
	upleftFrames = CreateFrames("left", "up", true);
	uprightFrames = CreateFrames("up", "right");
	rightupFrames = CreateFrames("up", "right", true);
	rightdownFrames = CreateFrames("right", "down");
	downrightFrames = CreateFrames("right", "down", true);
	downleftFrames = CreateFrames("down", "left");
	leftdownFrames = CreateFrames("down", "left", true);

	switch (startSide)
	{
		case SideType::Left:
			mainSprite->setTexture(node->getChildByName<Sprite *>("right")->getTexture());
			break;
		case SideType::Up:
			mainSprite->setTexture(node->getChildByName<Sprite *>("up")->getTexture());
			break;
		case SideType::Right:
			mainSprite->setTexture(node->getChildByName<Sprite *>("left")->getTexture());
			break;
		case SideType::Down:
			mainSprite->setTexture(node->getChildByName<Sprite *>("down")->getTexture());
			break;
		default:
			// �������� �� ���������
			break;
	}
}

void ElementAnimation::RunAnimation(AnimationType type)
{
	Animation * animation;

	switch (type)
	{
		case AnimationType::RotateLeftToUp:
			animation = Animation::createWithSpriteFrames(rightupFrames, 0.05F);
			break;
		case AnimationType::RotateUpToLeft:
			animation = Animation::createWithSpriteFrames(uprightFrames, 0.05F);
			break;
		case AnimationType::RotateUpToRight:
			animation = Animation::createWithSpriteFrames(upleftFrames, 0.05F);
			break;
		case AnimationType::RotateRightToUp:
			animation = Animation::createWithSpriteFrames(leftupFrames, 0.05F);
			break;
		case AnimationType::RotateRightToDown:
			animation = Animation::createWithSpriteFrames(leftdownFrames, 0.05F);
			break;
		case AnimationType::RotateDownToRight:
			animation = Animation::createWithSpriteFrames(downleftFrames, 0.05F);
			break;
		case AnimationType::RotateDownToLeft:
			animation = Animation::createWithSpriteFrames(downrightFrames, 0.05F);
			break;
		case AnimationType::RotateLeftToDown:
			animation = Animation::createWithSpriteFrames(rightdownFrames, 0.05F);
			break;
		default:
			// �������� �� ���������
			break;
	}

	auto animate = Animate::create(animation);

	mainSprite->runAction(animate);
}
