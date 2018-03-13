#include "cocostudio/CocoStudio.h"
#include "Field.h"
#include "Cell.h"
#include "Main\Settings.h"

#include "Main\MapHandle.h"
#include "Element\ClassType.h"
#include "AxesInfo.h"

// Фон
static cocos2d::Node * field;
// Набор клеток
static std::vector<Cell> items;
// Текущий статус в игре
static GameStatusType gameStatus;
// Изображение информации
static cocos2d::Sprite * infoMessage;

cocos2d::Node * Field::CreateBackground()
{
	// Формирование поля
	field = new cocos2d::Node();

	// Задний фон
	auto background = cocos2d::Sprite::create("Background.png", cocos2d::Rect(0, 0, Settings::FIELDWIDTHSIZE, Settings::FIELDHEIGHTSIZE));
	background->setAnchorPoint(cocos2d::Vec2(0.0f, 0.0f));
	field->addChild(background);

	// Создание клеток
	for (int y = 0; y < Settings::VERTICALCELLCOUNT; y++)
	{
		for (int x = 0; x < Settings::HORIZONTALCELLCOUNT; x++)
		{
			auto floor = cocos2d::Sprite::create("Floor.png", cocos2d::Rect(0, 0, Settings::FIELDWIDTHSIZE / Settings::HORIZONTALCELLCOUNT, Settings::FIELDHEIGHTSIZE / Settings::VERTICALCELLCOUNT));
			floor->setAnchorPoint(cocos2d::Vec2(0.0f, 1.0f));
			floor->setPosition(x * Settings::FIELDWIDTHSIZE / Settings::HORIZONTALCELLCOUNT, Settings::FIELDHEIGHTSIZE - y * Settings::FIELDHEIGHTSIZE / Settings::VERTICALCELLCOUNT);
			field->addChild(floor);

			items.push_back(Cell(x, y));
		}
	}

	return field;
}

void Field::DrawElement(cocos2d::Node * item)
{
	field->addChild(item);
}
void Field::WinGame()
{
	gameStatus = GameStatusType::Win;
	infoMessage = cocos2d::Sprite::create("Win.png", cocos2d::Rect(0, 0, 512, 256));
	infoMessage->setAnchorPoint(cocos2d::Vec2(0.0f, 1.0f));
	infoMessage->setPosition(Settings::FIELDWIDTHSIZE / 2 - 256, Settings::FIELDHEIGHTSIZE / 2 + 128);
	infoMessage->setLocalZOrder(5);
	field->addChild(infoMessage);
}
void Field::LoseGame()
{
	gameStatus = GameStatusType::Lose;
	infoMessage = cocos2d::Sprite::create("Lose.png", cocos2d::Rect(0, 0, 512, 256));
	infoMessage->setAnchorPoint(cocos2d::Vec2(0.0f, 1.0f));
	infoMessage->setPosition(Settings::FIELDWIDTHSIZE / 2 - 256, Settings::FIELDHEIGHTSIZE / 2 + 128);
	infoMessage->setLocalZOrder(5);
	field->addChild(infoMessage);
}
void Field::Reload()
{
	for (int index = 0; index < items.size(); index++)
	{
		items.at(index).RemoveElements();
	}
	MapHandle::ReloadMap();

	field->removeChild(infoMessage);
	gameStatus = GameStatusType::Gaming;
}
GameStatusType Field::GetGameStatus()
{
	return gameStatus;
}

bool Field::CanAddElement(Element & item)
{
	return items.at(AxesInfo::ConvertToIndex(item.GetAxes())).CanAddElement(item);
}
bool Field::CanAddElement(ClassType type, int x, int y)
{
	return items.at(AxesInfo::ConvertToIndex(x, y)).CanAddElement(type);
}
void Field::AddElement(Element & value, const int & x, const int & y)
{
	items.at(AxesInfo::ConvertToIndex(x, y)).AddElement(value);
}
void Field::MoveElement(Element & item, int x, int y)
{
	if (Field::ContainElement(item) == true)
	{
		int oldIndex = AxesInfo::ConvertToIndex(item.GetX(), item.GetY());

		items.at(AxesInfo::ConvertToIndex(x, y)).AddElement(item);
		items.at(oldIndex).RemoveElement(item);
	}
}
bool Field::ContainName(ElementNameType name, int x, int y)
{
	return items.at(AxesInfo::ConvertToIndex(x, y)).ContainName(name);
}
bool Field::ContainElement(Element & item)
{
	return items.at(AxesInfo::ConvertToIndex(item.GetAxes())).ContainElement(item);
}

void Field::RemoveElement(Element & item)
{
	items.at(AxesInfo::ConvertToIndex(item.GetAxes())).RemoveElement(item);
}

void Field::Destroy(int x, int y)
{
	items.at(AxesInfo::ConvertToIndex(x, y)).RemoveElements();
}

std::vector<TagAxes> Field::CreateBlockMap()
{
	std::vector<TagAxes> result;

	for (int index = 0; index < items.size(); index++)
	{
		TagAxes newPoint = AxesInfo::ConvertToAxes(index);

		if (items.at(index).ContainType(ClassType::Block) == true)
		{
			newPoint.SetTag(-3);
			result.push_back(newPoint);
		}
		else
		{
			newPoint.SetTag(-1);
			result.push_back(newPoint);
		}
	}

	return result;
}
bool Field::CheckPath()
{
	//return PathFinder::CanMoveTo(Field::CreateBlockMap(), Axes(ninja.GetX(), ninja.GetY()), Axes(finish.GetX(), finish.GetY()));
	return true;
}