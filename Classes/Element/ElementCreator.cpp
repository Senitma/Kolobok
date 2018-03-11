#include "cocostudio/CocoStudio.h"


#include "ElementCreator.h"
#include "Field\Field.h"
#include "Main\Settings.h"
#include "Field\FieldPoint.h"



#include "Option\CreateOption\OptionForCreate.h"
#include "Option\CreateOption\OptionForIntervalCreate.h"
#include "Option\CreateOption\OptionForMouseCreateDestroy.h"

#include "Option\MoveOption\MoveType.h"
#include "Option\MoveOption\OptionForMouseMove.h"
#include "Option\MoveOption\OptionForMove.h"
#include "Option\MoveOption\OptionForOneStep.h"
#include "Option\MoveOption\OptionForPatrol.h"

Element ElementCreator::Create(ElementNameType name, int x, int y)
{
	return ElementCreator::Create(name, SideType::Down, x, y);
}
Element ElementCreator::Create(ElementNameType name, SideType side, int x, int y)
{
	switch (name)
	{
	case ElementNameType::Ninja:
		return ElementCreator::CreateNinja(side, x, y);
	case ElementNameType::Finish:
		return ElementCreator::CreateFinish(side, x, y);
	case ElementNameType::Wall:
		return ElementCreator::CreateWall(side, x, y);
	case ElementNameType::Patrol:
		return ElementCreator::CreatePatrol(side, x, y);
	case ElementNameType::Gun:
		return ElementCreator::CreateGun(side, x, y);
	case ElementNameType::Fireball:
		return ElementCreator::CreateFireball(side, x, y);
	//default:
	//	// Error
	}
}

Element ElementCreator::CreateNinja(SideType side, int x, int y)
{
	Element newElement = Create("Ninja.csb", ElementNameType::Ninja, ClassType::Character, side, x, y);

	//OptionForMouseMove * moveOption = new OptionForMouseMove();
	//moveOption->SetParent(&newElement);
	//moveOption->SetMoveSpeed(Settings::MOVESPEED);
	//moveOption->SetRotateSpeed(Settings::ROTATESPEED);
	//moveOption->SetMoveType(MoveType::ToByPass);
	//moveOption->SetRotate(true);

	OptionForMouseCreateDestroy * createOption = new OptionForMouseCreateDestroy(newElement);
	createOption->SetName(ElementNameType::Wall);

	return newElement;
}
Element ElementCreator::CreateFinish(SideType side, int x, int y)
{
	return Create("Finish.csb", ElementNameType::Finish, ClassType::Finish, side, x, y);
}
Element ElementCreator::CreateWall(SideType side, int x, int y)
{
	return Create("Wall.csb", ElementNameType::Wall, ClassType::Block, side, x, y);
}
Element ElementCreator::CreatePatrol(SideType side, int x, int y)
{
	Element & newElement = Create("Patrol.csb", ElementNameType::Patrol, ClassType::Enemy, side, x, y);

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
Element ElementCreator::CreateGun(SideType side, int x, int y)
{
	Element & newElement = Create("Gun.csb", ElementNameType::Gun, ClassType::Block, side, x, y);

	//OptionForIntervalCreate * createOption = new OptionForIntervalCreate();
	//createOption->SetParent(&newElement);
	//createOption->SetName(ElementNameType::Fireball);
	//createOption->SetActive(true);
	//createOption->SetRotate(true);
	//createOption->SetOffsetY(1);
	//createOption->SetInterval(Settings::CREATEFIREBALLINTERVAL);

	return newElement;
}
Element ElementCreator::CreateFireball(SideType side, int x, int y)
{
	Element & newElement = Create("FireBall.csb", ElementNameType::Fireball, ClassType::Bullet, side, x, y);

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

Element ElementCreator::Create(char * nodeName, ElementNameType name, ClassType type, SideType side, int x, int y)
{
	// Создание прорисовка для отображения и прорисовки элемента
	auto nodeDraw = cocos2d::CSLoader::createNode(nodeName);
	// Масштабирование элемента под размеры клетки
	cocos2d::Size size = nodeDraw->getChildren().at(0)->getContentSize();
	float width = size.width;
	float height = size.height;
	float scaleWidth = FieldPoint::GetCellWidth() / width;
	float scaleHeight = FieldPoint::GetCellHeight() / height;

	nodeDraw->setScale(scaleWidth, scaleHeight);
	// Настройка элемента
	Element newElement(nodeDraw, name, type);
	newElement.SetX(x);
	newElement.SetY(y);

	newElement.SetPosition(FieldPoint::ConvertToLeft(x), FieldPoint::ConvertToTop(y));
	newElement.SetSide(side);

	switch (type)
	{
	case ClassType::Character:
		nodeDraw->setLocalZOrder(2);
		break;
	case ClassType::Finish:
		nodeDraw->setLocalZOrder(1);
		break;
	case ClassType::Block:
		nodeDraw->setLocalZOrder(4);
		break;
	case ClassType::Enemy:
		nodeDraw->setLocalZOrder(2);
		break;
	case ClassType::Bullet:
		nodeDraw->setLocalZOrder(3);
		break;
	}

	Field::DrawElement(nodeDraw);
	Field::AddElement(newElement);

	return newElement;
}