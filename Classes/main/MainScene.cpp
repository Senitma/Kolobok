#include "MainScene.h"

USING_NS_CC;

Scene* MainScene::createScene()
{
	auto scene = Scene::create();
	auto layer = MainScene::create();
	scene->addChild(layer);

	return scene;
}

bool MainScene::init()
{
	if (!Layer::init())
	{
		return false;
	}

	this->scheduleUpdate();

	return true;
}

void MainScene::onEnter()
{
	Layer::onEnter();
}
void MainScene::update(float delta)
{
	Layer::update(delta);
}