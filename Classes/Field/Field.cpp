#include "Cell.h"
#include "AxesInfo.h"
#include "Element\ClassType.h"
#include "Main\Maps.h"
#include "Settings.h"

#include "cocostudio/CocoStudio.h"

#include "Field.h"

// Фон
cocos2d::Node * field;
// Изображение информации
cocos2d::Sprite * infoMessage;

// Набор клеток
std::vector<Cell> items;

void Field::WinGame()
{
	infoMessage = cocos2d::Sprite::create("Win.png", cocos2d::Rect(0, 0, 512, 256));
	infoMessage->setAnchorPoint(cocos2d::Vec2(0.0f, 1.0f));
	infoMessage->setPosition(Settings::FIELDWIDTHSIZE / 2 - 256, Settings::FIELDHEIGHTSIZE / 2 + 128);
	infoMessage->setLocalZOrder(5);
	field->addChild(infoMessage);
}
void Field::LoseGame()
{
	infoMessage = cocos2d::Sprite::create("Lose.png", cocos2d::Rect(0, 0, 512, 256));
	infoMessage->setAnchorPoint(cocos2d::Vec2(0.0f, 1.0f));
	infoMessage->setPosition(Settings::FIELDWIDTHSIZE / 2 - 256, Settings::FIELDHEIGHTSIZE / 2 + 128);
	infoMessage->setLocalZOrder(5);
	field->addChild(infoMessage);
}
void Field::Reload()
{
	items.clear();
	Maps::ReloadMap();

	field->removeChild(infoMessage);
}

void Field::DrawElement(cocos2d::Node * item)
{
	field->addChild(item);
}
cocos2d::Node * Field::CreateBackground()
{
	// Формирование поля
	field = new cocos2d::Node();

	// Задний фон
	auto background = cocos2d::Sprite::create("Background.png", cocos2d::Rect(0, 0, Settings::FIELDWIDTHSIZE, Settings::FIELDHEIGHTSIZE));
	background->setAnchorPoint(cocos2d::Vec2(0.0f, 0.0f));
	field->addChild(background);

	// Создание клеток
	int width = Settings::FIELDWIDTHSIZE / Settings::HORIZONTALCELLCOUNT;
	int height = Settings::FIELDHEIGHTSIZE / Settings::VERTICALCELLCOUNT;

	for (int y = 0; y < Settings::VERTICALCELLCOUNT; y++)
	{
		for (int x = 0; x < Settings::HORIZONTALCELLCOUNT; x++)
		{
			auto floor = cocos2d::Sprite::create("Floor.png", cocos2d::Rect(0, 0, width, height));
			floor->setAnchorPoint(cocos2d::Vec2(0.0f, 1.0f));
			floor->setPosition(x * width, Settings::FIELDHEIGHTSIZE - y * height);
			field->addChild(floor);

			items.push_back(Cell(x, y));
		}
	}

	return field;
}

bool Field::CanAddElement(const ClassType & type, const int & x, const int & y)
{
	return items.at(AxesInfo::ConvertToIndex(x, y)).CanAddElement(type);
}
bool Field::ContainName(const ElementNameType & name, const int & x, const int & y)
{
	return items.at(AxesInfo::ConvertToIndex(x, y)).ContainName(name);
}

void Field::AddElement(Element & value, const int & x, const int & y)
{
	items.at(AxesInfo::ConvertToIndex(x, y)).AddElement(value);
}
void Field::MoveElement(Element & item, const int & x, const int & y)
{
	//if (Field::ContainElement(item) == true)
	//{
		int oldIndex = AxesInfo::ConvertToIndex(item.GetX(), item.GetY());

		items.at(AxesInfo::ConvertToIndex(x, y)).AddElement(item);
		items.at(oldIndex).RemoveElement(item);
	//}
}
void Field::RemoveElement(Element & item)
{
	items.at(AxesInfo::ConvertToIndex(item.GetAxes())).RemoveElement(item);
}
void Field::Destroy(const int & x, const int & y)
{
	items.at(AxesInfo::ConvertToIndex(x, y)).RemoveElements();
}

std::vector<TagAxes> Field::CreateBlockMap()
{
	std::vector<TagAxes> result;

	std::for_each(items.begin(), items.end(), [&](const Cell & item) 
	{
		TagAxes newPoint = AxesInfo::ConvertToAxes(item.GetX(), item.GetY());

		if (item.ContainType(ClassType::Block) == true)
		{
			newPoint.SetTag(-3);
			result.push_back(newPoint);
		}
		else
		{
			newPoint.SetTag(-1);
			result.push_back(newPoint);
		}
	});

	return result;
}
bool Field::CheckPath()
{
	//return PathFinder::CanMoveTo(Field::CreateBlockMap(), Axes(ninja.GetX(), ninja.GetY()), Axes(finish.GetX(), finish.GetY()));
	return true;
}