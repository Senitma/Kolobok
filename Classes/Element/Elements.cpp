#include "string"

#include "ElementNameType.h"
#include "ClassType.h"
#include "SideType.h"
#include "Element.h"

#include "Field\Field.h"
#include "Field\AxesInfo.h"
#include "Option\Options.h"
#include "Option\MoveType.h"
#include "Settings.h"

#include "CCFileUtils.h"
#include "2d\CCNode.h"
#include "cocostudio\ActionTimeline\CSLoader.h"

#include "Elements.h"

// Добавление внутренних функций к пространству имен
namespace Elements
{
	// Добавление главного персонажа
	Element CreateMain(SideType side, int x, int y);
	// Добавление клетки финиша
	Element CreateFinish(SideType side, int x, int y);
	// Добавление клетки пола
	Element CreateFloor(SideType side, int x, int y);
	// Добавление стены
	Element CreateBlock(SideType side, int x, int y);
	// Добавление патруля
	Element CreatePatrol(SideType side, int x, int y);
	// Добавления пушки
	Element CreateGun(SideType side, int x, int y);
	// Добавление снаряда
	Element CreateFireball(SideType side, int x, int y);
	// Создание элемента
	Element Create(std::string nodeName, ElementNameType name, ClassType type, SideType side, int x, int y);
}

Element Elements::Create(ElementNameType name, int x, int y)
{
	return Elements::Create(name, SideType::None, x, y);
}
Element Elements::Create(ElementNameType name, SideType side, int x, int y)
{
	switch (name)
	{
	case ElementNameType::Main:
		return Elements::CreateMain(side, x, y);
	case ElementNameType::Finish:
		return Elements::CreateFinish(side, x, y);
	case ElementNameType::Floor:
		return Elements::CreateFloor(side, x, y);
	case ElementNameType::Patrol:
		return Elements::CreatePatrol(side, x, y);
	case ElementNameType::Gun:
		return Elements::CreateGun(side, x, y);
	case ElementNameType::Fireball:
		return Elements::CreateFireball(side, x, y);
	case ElementNameType::Block:
		// Значение по умолчанию
	default:
		return Elements::CreateBlock(side, x, y);
	}
}

Element Elements::CreateMain(SideType side, int x, int y)
{
	Element newElement = Elements::Create("Main.csb", ElementNameType::Main, ClassType::Character, side, x, y);

	auto & moveOption = Options::Create<OptionForMouseMove>(newElement);
	moveOption.SetMoveType(MoveType::ToByPass);
	moveOption.SetMoveSpeed(Settings::MOVESPEED);
	moveOption.SetRotateSpeed(Settings::ROTATESPEED);

	auto & createOption = Options::Create<OptionForMouseCreateDestroy>(newElement);
	createOption.SetName(ElementNameType::Block);

	return newElement;
}
Element Elements::CreateFinish(SideType side, int x, int y)
{
	return Elements::Create("Finish.csb", ElementNameType::Finish, ClassType::Finish, side, x, y);
}
Element Elements::CreateFloor(SideType side, int x, int y)
{
	return Elements::Create("Floor.csb", ElementNameType::Floor, ClassType::Empty, side, x, y);
}
Element Elements::CreateBlock(SideType side, int x, int y)
{
	return Elements::Create("Block.csb", ElementNameType::Block, ClassType::Block, side, x, y);
}
Element Elements::CreatePatrol(SideType side, int x, int y)
{
	Element & newElement = Elements::Create("Patrol.csb", ElementNameType::Patrol, ClassType::Enemy, side, x, y);

	auto & moveOption = Options::Create<OptionForPatrol>(newElement);
	moveOption.SetMoveSpeed(Settings::MOVESPEED);
	moveOption.SetRotateSpeed(Settings::ROTATESPEED);
	moveOption.SetMoveType(MoveType::ToByPass);
	moveOption.SetPatrolType(PatrolType::Circle);

	return newElement;
}
Element Elements::CreateGun(SideType side, int x, int y)
{
	Element & newElement = Elements::Create("Gun.csb", ElementNameType::Gun, ClassType::Block, SideType::None, x, y);

	auto & createOption = Options::Create<OptionForIntervalCreate>(newElement);
	createOption.SetName(ElementNameType::Fireball);
	createOption.SetSide(side);
	createOption.SetRotate(true);
	createOption.SetOffsetY(1);
	createOption.SetInterval(Settings::CREATEFIREBALLINTERVAL);
	createOption.SetActive(true);

	return newElement;
}
Element Elements::CreateFireball(SideType side, int x, int y)
{
	Element & newElement = Elements::Create("FireBall.csb", ElementNameType::Fireball, ClassType::Bullet, SideType::None, x, y);

	newElement.AddPoint(x, y);
	switch (side)
	{
	case SideType::Up:
		newElement.AddPoint(x, 0);
		break;
	case SideType::Down:
		newElement.AddPoint(x, Settings::VERTICALCELLCOUNT - 1);
		break;
	case SideType::Left:
		newElement.AddPoint(0, y);
		break;
	case SideType::Right:
		newElement.AddPoint(Settings::HORIZONTALCELLCOUNT - 1, y);
		break;
	}

	auto & moveOption = Options::Create<OptionForPatrol>(newElement);
	moveOption.SetMoveSpeed(Settings::FIREBALLSPEED);
	moveOption.SetMoveType(MoveType::ToLine);
	moveOption.SetPatrolType(PatrolType::DestroyWay);

	return newElement;
}

Element Elements::Create(std::string nodeName, ElementNameType name, ClassType type, SideType side, int x, int y)
{
	// Создание узла для отображения и прорисовки элемента
	auto node = cocos2d::CSLoader::createNode(nodeName);

	// Масштабирование элемента под размеры клетки
	cocos2d::Size size = node->getChildren().at(0)->getContentSize();
	float width = size.width;
	float height = size.height;
	float scaleWidth = Settings::NODEWIDTH / width;
	float scaleHeight = Settings::NODEHEIGHT / height;
	node->setScale(scaleWidth, scaleHeight);

	// Настройка элемента
	Element newElement(node, side, name, type);
	newElement.SetPosition(AxesInfo::ConvertToLeft(x), AxesInfo::ConvertToTop(y));

	// Регистрация компонента
	Field::DrawElement(node);
	Field::AddElement(newElement, x, y);

	return newElement;
}
