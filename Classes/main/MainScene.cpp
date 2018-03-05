#include "MainScene.h"
#include "..\Field\Field.h"
#include "MapHandle.h"

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

	auto rootNode = CSLoader::createNode("MainScene.csb");
	Size size = Director::getInstance()->getVisibleSize();
	rootNode->setContentSize(size);
	ui::Helper::doLayout(rootNode);
	this->addChild(rootNode);

	this->addChild(Field::CreateBackground());
	MapHandle::LoadForIndex(Settings::MAPINDEX);

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