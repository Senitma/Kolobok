#include "ElementCreator.h"

Element * ElementCreator::Create(ElementNameType name, int x, int y)
{
	return ElementCreator::Create(name, SideType::Down, x, y);
}
Element * ElementCreator::Create(ElementNameType name, SideType side, int x, int y)
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
	default:
		return nullptr;
	}
}

AdvancedElement * ElementCreator::CreateNinja(SideType side, int x, int y)
{
	return Create("Ninja.csb", ElementNameType::Ninja, ClassType::Character, side, x, y);
}
AdvancedElement * ElementCreator::CreateFinish(SideType side, int x, int y)
{
	return Create("Finish.csb", ElementNameType::Finish, ClassType::Finish, side, x, y);
}
AdvancedElement * ElementCreator::CreateWall(SideType side, int x, int y)
{
	return Create("Wall.csb", ElementNameType::Wall, ClassType::Block, side, x, y);
}
AdvancedElement * ElementCreator::CreatePatrol(SideType side, int x, int y)
{
	return Create("Patrol.csb", ElementNameType::Patrol, ClassType::Enemy, side, x, y);
}
AdvancedElement * ElementCreator::CreateGun(SideType side, int x, int y)
{
	return Create("Gun.csb", ElementNameType::Gun, ClassType::Block, side, x, y);
}
AdvancedElement * ElementCreator::CreateFireball(SideType side, int x, int y)
{
	return Create("FireBall.csb", ElementNameType::Fireball, ClassType::Bullet, side, x, y);
}
AdvancedElement * ElementCreator::Create(char * nodeName, ElementNameType name, ClassType type, SideType side, int x, int y)
{
	// Создание прорисовка для отображения и прорисовки элемента
	auto nodeDraw = new cocos2d::Node();
	// Масштабирование элемента под размеры клетки
	cocos2d::Size size = nodeDraw->getChildren().at(0)->getContentSize();
	float width = size.width;
	float height = size.height;
	float scaleWidth = FieldPoint::GetCellWidth() / width;
	float scaleHeight = FieldPoint::GetCellHeight() / height;

	nodeDraw->setScale(scaleWidth, scaleHeight);
	// Настройка элемента
	AdvancedElement * newElement = new AdvancedElement(nodeDraw, name, type);

	newElement->SetPosition(cocos2d::Vec2(FieldPoint::ConvertToLeft(x), FieldPoint::ConvertToTop(y)));

	newElement->SetX(x);
	newElement->SetY(y);
	
	newElement->SetSide(side);
	
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

	return newElement;
}