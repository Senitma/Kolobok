#include "Cell.h"
#include "AxesInfo.h"
#include "Element\ClassType.h"
#include "Main\Maps.h"
#include "Option\MoveOption\Vertex.h"
#include "Settings.h"

#include "cocostudio/CocoStudio.h"

#include "Field.h"

// Фон
cocos2d::Node * field = cocos2d::Node::create();
// Изображение информации
cocos2d::Sprite * infoMessage;

// Набор клеток
std::vector<Cell> cells;

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
	cells.clear();
	Maps::ReloadMap();

	field->removeChild(infoMessage);
}

cocos2d::Node * Field::GetInstance()
{
	// Заливка фона
	auto background = cocos2d::Sprite::create("Background.png", cocos2d::Rect(0, 0, Settings::FIELDWIDTHSIZE, Settings::FIELDHEIGHTSIZE));
	background->setAnchorPoint(cocos2d::Vec2(0.0f, 0.0f));
	background->setColor(cocos2d::Color3B(153, 205, 205));
	background->setLocalZOrder(-1);

	field->addChild(background);
	return field;
}
void Field::InitCells()
{
	cells = std::vector<Cell>(Settings::VERTICALCELLCOUNT * Settings::HORIZONTALCELLCOUNT);
	int index = 0;

	std::for_each(cells.begin(), cells.end(), [&](Cell & item) 
	{
		item.SetIndex(index);
		index++;
	});
}
void Field::DrawElement(cocos2d::Node * item)
{
	field->addChild(item);
}

bool Field::CanAddElement(const ClassType & type, const int & x, const int & y)
{
	return cells.at(AxesInfo::ConvertToIndex(x, y)).CanAddElement(type);
}
bool Field::ContainName(const ElementNameType & name, const int & x, const int & y)
{
	return cells.at(AxesInfo::ConvertToIndex(x, y)).ContainName(name);
}

void Field::AddElement(Element & value, const int & x, const int & y)
{
	cells.at(AxesInfo::ConvertToIndex(x, y)).AddElement(value);
}
void Field::MoveElement(Element & item, const int & x, const int & y)
{
	//if (Field::ContainElement(item) == true)
	//{
		int oldIndex = AxesInfo::ConvertToIndex(item.GetX(), item.GetY());

		cells.at(AxesInfo::ConvertToIndex(x, y)).AddElement(item);
		cells.at(oldIndex).RemoveElement(item);
	//}
}
void Field::RemoveElement(Element & item)
{
	item.SetDestroyStatus(true);
	cells.at(AxesInfo::ConvertToIndex(item.GetAxes())).RemoveElement(item);
}
void Field::Destroy(const int & x, const int & y)
{
	cells.at(AxesInfo::ConvertToIndex(x, y)).RemoveElements();
}

std::vector<Vertex> Field::CreateBlockMap()
{
	std::vector<Vertex> result;

	// Заполнение блоков
	std::for_each(cells.begin(), cells.end(), [&](const Cell & item) 
	{
		Vertex newPoint = Vertex(item.GetX(), item.GetY());

		if (item.ContainType(ClassType::Block) == true)
		{
			newPoint.SetCounter(Vertex::BLOCKINDEX);
			result.push_back(newPoint);
		}
		else
		{
			newPoint.SetCounter(Vertex::EMPTYINDEX);
			newPoint.SetWeight(1);
			result.push_back(newPoint);
		}
	});

	return result;
}
bool Field::CheckPath()
{
	//return MoveByPass::CanMoveTo(Field::CreateBlockMap(), Axes(ninja.GetX(), ninja.GetY()), Axes(finish.GetX(), finish.GetY()));
	return true;
}