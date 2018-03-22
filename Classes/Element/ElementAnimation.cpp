#include "string"

#include "SideType.h"
#include "AnimationType.h"

#include "ElementAnimation.h"

void ElementAnimation::LoadAnimation(Node * node, const float & interval, const int & frameCount, const int & width, const int & height, const SideType & startSide)
{
	// Функция создания списка с кадрами анимации
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
			mainSprite->setTexture(node->getChildByName<Sprite *>("left")->getTexture());
			break;
		case SideType::Up:
			mainSprite->setTexture(node->getChildByName<Sprite *>("up")->getTexture());
			break;
		case SideType::Right:
			mainSprite->setTexture(node->getChildByName<Sprite *>("right")->getTexture());
			break;
		case SideType::Down:
			mainSprite->setTexture(node->getChildByName<Sprite *>("down")->getTexture());
			break;
		default:
			// Действий не требуется
			break;
	}
}

void ElementAnimation::RunAnimation(AnimationType type)
{
	Vector<SpriteFrame *> frames;

	switch (type)
	{
		case AnimationType::RotateLeftToUp:
			frames = leftupFrames;
			break;
		case AnimationType::RotateUpToLeft:
			frames = upleftFrames;
			break;
		case AnimationType::RotateUpToRight:
			frames = uprightFrames;
			break;
		case AnimationType::RotateRightToUp:
			frames = rightupFrames;
			break;
		case AnimationType::RotateRightToDown:
			frames = rightdownFrames;
			break;
		case AnimationType::RotateDownToRight:
			frames = downrightFrames;
			break;
		case AnimationType::RotateDownToLeft:
			frames = downleftFrames;
			break;
		case AnimationType::RotateLeftToDown:
			frames = leftdownFrames;
			break;
		default:
			// Действий не требуется
			break;
	}

	auto animation = Animation::createWithSpriteFrames(frames, 0.05F);
	auto animate = Animate::create(animation);

	mainSprite->runAction(animate);
}
