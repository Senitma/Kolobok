#include "Element\Element.h"
#include "Field\Field.h"
#include "Option\ISMouse.h"
#include "Option\ISInterval.h"
#include "Maps.h"
#include "Settings.h"

#include "ui\CocosGUI.h"
#include "cocostudio\ActionTimeline\CSLoader.h"

#include "MainScene.h"

cocos2d::Scene* MainScene::createScene()
{
	auto scene = cocos2d::Scene::create();
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

	auto rootNode = cocos2d::CSLoader::createNode("MainScene.csb");
	cocos2d::Size size = cocos2d::Director::getInstance()->getVisibleSize();
	rootNode->setContentSize(size);
	cocos2d::ui::Helper::doLayout(rootNode);
	this->addChild(rootNode);

	Maps::Load();
	this->addChild(Field::GetInstance());

	this->scheduleUpdate();

	return true;
}

void MainScene::onEnter()
{
	Layer::onEnter();

	auto touchListener = cocos2d::EventListenerMouse::create();

	touchListener->onMouseDown = [](cocos2d::Event* event)
	{
		cocos2d::EventMouse* mouseEvent = dynamic_cast<cocos2d::EventMouse*>(event);

		cocos2d::Vec2 currentLocation = mouseEvent->getLocation();
		ISMouse::PassMouseClick((MouseType)mouseEvent->getMouseButton(), currentLocation.x, Settings::FIELDHEIGHTSIZE - currentLocation.y);

		return true;
	};

	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(touchListener, this);
}
void MainScene::update(float delta)
{
	Layer::update(delta);

	ISInterval::PassUpdate();
}