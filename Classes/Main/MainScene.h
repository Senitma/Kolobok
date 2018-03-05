#pragma once

#include "cocos2d.h"

class MainScene : public cocos2d::Layer
{
public:
	CREATE_FUNC(MainScene);

	static cocos2d::Scene* createScene();

	virtual bool init();

private:
	void onEnter() override;
	void update(float delta) override;
};