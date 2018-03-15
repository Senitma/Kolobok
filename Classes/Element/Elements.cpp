#include "ElementNameType.h"
#include "ClassType.h"
#include "SideType.h"
#include "Element.h"

#include "Field\Field.h"
#include "Field\AxesInfo.h"
#include "Option\Options.h"
#include "Option\MoveType.h"
#include "Settings.h"

#include "cocos2d.h"
#include "cocostudio\CocoStudio.h"

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
	Element CreateWall(SideType side, int x, int y);
	// Добавление патруля
	Element CreatePatrol(SideType side, int x, int y);
	// Добавления пушки
	Element CreateGun(SideType side, int x, int y);
	// Добавление снаряда
	Element CreateFireball(SideType side, int x, int y);
	// Создание элемента
	Element Create(char * nodeName, ElementNameType name, ClassType type, SideType side, int x, int y);
}

Element Elements::Create(ElementNameType name, int x, int y)
{
	return Elements::Create(name, SideType::Down, x, y);
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
	case ElementNameType::Wall:
		return Elements::CreateWall(side, x, y);
	case ElementNameType::Patrol:
		return Elements::CreatePatrol(side, x, y);
	case ElementNameType::Gun:
		return Elements::CreateGun(side, x, y);
	case ElementNameType::Fireball:
		return Elements::CreateFireball(side, x, y);
	default:
		throw "Имя элемента не найдено";
	}
}

Element Elements::CreateMain(SideType side, int x, int y)
{
	Element newElement = Elements::Create("Ninja.csb", ElementNameType::Main, ClassType::Character, side, x, y);

	auto & moveOption = Options::Create<OptionForMouseMove>(newElement);
	moveOption.SetMoveType(MoveType::ToByPass);
	moveOption.SetMoveSpeed(Settings::MOVESPEED);
	moveOption.SetRotateSpeed(Settings::ROTATESPEED);

	auto & createOption = Options::Create<OptionForMouseCreateDestroy>(newElement);
	createOption.SetName(ElementNameType::Wall);

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
Element Elements::CreateWall(SideType side, int x, int y)
{
	return Elements::Create("Wall.csb", ElementNameType::Wall, ClassType::Block, side, x, y);
}
Element Elements::CreatePatrol(SideType side, int x, int y)
{
	Element & newElement = Elements::Create("Patrol.csb", ElementNameType::Patrol, ClassType::Enemy, side, x, y);

	//OptionForPatrol * patrolOption = new OptionForPatrol();
	//patrolOption->SetParent(&newElement);
	//patrolOption->SetRotateSpeed(Settings::ROTATESPEED);
	//patrolOption->SetMoveSpeed(Settings::MOVESPEED);
	//patrolOption->SetMoveType(MoveType::ToByPass);
	//patrolOption->SetRotate(true);
	//patrolOption->SetPatrol(true);
	////patrolOption->SetCircle(true);

	return newElement;
}
Element Elements::CreateGun(SideType side, int x, int y)
{
	Element & newElement = Elements::Create("Gun.csb", ElementNameType::Gun, ClassType::Block, side, x, y);

	//OptionForIntervalCreate * createOption = new OptionForIntervalCreate();
	//createOption->SetParent(&newElement);
	//createOption->SetName(ElementNameType::Fireball);
	//createOption->SetActive(true);
	//createOption->SetRotate(true);
	//createOption->SetOffsetY(1);
	//createOption->SetInterval(Settings::CREATEFIREBALLINTERVAL);

	return newElement;
}
Element Elements::CreateFireball(SideType side, int x, int y)
{
	Element & newElement = Elements::Create("FireBall.csb", ElementNameType::Fireball, ClassType::Bullet, side, x, y);

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

	//OptionForPatrol * patrolOption = new OptionForPatrol();
	//patrolOption->SetParent(&newElement);
	//patrolOption->SetMoveSpeed(Settings::FIREBALLSPEED);
	//patrolOption->SetMoveType(MoveType::ToLine);
	//patrolOption->SetPatrol(true);
	//patrolOption->SetDestroyInEnd(true);

	return newElement;
}

Element Elements::Create(char * nodeName, ElementNameType name, ClassType type, SideType side, int x, int y)
{
	// Создание прорисовка для отображения и прорисовки элемента
	auto nodeDraw = cocos2d::CSLoader::createNode(nodeName);
	// Масштабирование элемента под размеры клетки
	cocos2d::Size size = nodeDraw->getChildren().at(0)->getContentSize();
	float width = size.width;
	float height = size.height;
	float scaleWidth = Settings::NODEWIDTH / width;
	float scaleHeight = Settings::NODEHEIGHT / height;

	nodeDraw->setScale(scaleWidth, scaleHeight);
	// Настройка элемента
	Element newElement(nodeDraw, name, type);
	newElement.SetPosition(AxesInfo::ConvertToLeft(x), AxesInfo::ConvertToTop(y));
	newElement.SetSide(side);
	// Регистрация компонента
	Field::DrawElement(nodeDraw);
	Field::AddElement(newElement, x, y);

	return newElement;
}
