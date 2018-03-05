#include "MainScene.h"
#include "Field\Field.h"
#include "MapHandle.h"

#include "Option\BaseClass\ISMouse.h"
#include "Option\BaseClass\ISInterval.h"

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

	auto touchListener = EventListenerMouse::create();

	touchListener->onMouseDown = [](cocos2d::Event* event)
	{
		EventMouse* mouseEvent = dynamic_cast<EventMouse*>(event);

		Vec2 currentLocation = mouseEvent->getLocation();
		ISMouse::MouseClickAll((MouseType)mouseEvent->getMouseButton(), currentLocation.x, currentLocation.y);

		return true;
	};

	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(touchListener, this);
}
void MainScene::update(float delta)
{
	Layer::update(delta);

	ISInterval::UpdateAll();
}