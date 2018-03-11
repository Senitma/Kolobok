#include "cocostudio/CocoStudio.h"
#include "Field.h"
#include "Cell.h"
#include "Main\Settings.h"

#include "Option\BaseClass\ISMouse.h"
#include "Option\BaseClass\ISInterval.h"
#include "Main\MapHandle.h"
#include "Element\ClassType.h"
#include "Axes.h"

USING_NS_CC;

// Фон
static Node * field;
// Набор клеток
static Vector<Cell*> items;
// Текущий статус в игре
static GameStatusType gameStatus;
// Изображение информации
static Sprite * infoMessage;

Node * Field::CreateBackground()
{
	// Формирование поля
	field = new Node();

	// Задний фон
	auto background = Sprite::create("Background.png", Rect(0, 0, Settings::WIDTHSIZE, Settings::HEIGHTSIZE));
	background->setAnchorPoint(Vec2(0.0f, 0.0f));
	field->addChild(background);

	// Создание клеток
	for (int x = 0; x < Settings::HORIZONTALCELLCOUNT; x++)
	{
		for (int y = 0; y < Settings::VERTICALCELLCOUNT; y++)
		{
			auto floor = Sprite::create("Floor.png", Rect(0, 0, FieldPoint::GetCellWidth(), FieldPoint::GetCellHeight()));
			floor->setAnchorPoint(Vec2(0.0f, 1.0f));
			floor->setPosition(x * FieldPoint::GetCellWidth(), Settings::HEIGHTSIZE - y * FieldPoint::GetCellHeight());
			field->addChild(floor);

			items.pushBack(new Cell());
		}
	}

	return field;
}

void Field::DrawElement(Node * item)
{
	field->addChild(item);
}
void Field::WinGame()
{
	gameStatus = GameStatusType::Win;
	infoMessage = Sprite::create("Win.png", Rect(0, 0, 512, 256));
	infoMessage->setAnchorPoint(Vec2(0.0f, 1.0f));
	infoMessage->setPosition(Settings::WIDTHSIZE / 2 - 256, Settings::HEIGHTSIZE / 2 + 128);
	infoMessage->setLocalZOrder(5);
	field->addChild(infoMessage);
}
void Field::LoseGame()
{
	gameStatus = GameStatusType::Lose;
	infoMessage = Sprite::create("Lose.png", Rect(0, 0, 512, 256));
	infoMessage->setAnchorPoint(Vec2(0.0f, 1.0f));
	infoMessage->setPosition(Settings::WIDTHSIZE / 2 - 256, Settings::HEIGHTSIZE / 2 + 128);
	infoMessage->setLocalZOrder(5);
	field->addChild(infoMessage);
}
void Field::Reload()
{
	for (int index = 0; index < items.size(); index++)
	{
		items.at(index)->RemoveElements();
	}
	ISMouse::Clear();
	ISInterval::Clear();
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
	return items.at(Axes::ConvertToIndex(item.GetAxes()))->CanAddElement(item);
}
bool Field::CanAddElement(ClassType type, int x, int y)
{
	return items.at(Axes::ConvertToIndex(x, y))->CanAddElement(type);
}
void Field::AddElement(Element & value)
{
	items.at(Axes::ConvertToIndex(value.GetAxes()))->AddElement(value);
}
void Field::MoveElement(Element & item, int x, int y)
{
	if (Field::ContainElement(item) == true)
	{
		items.at(Axes::ConvertToIndex(x, y))->AddElement(item);
		items.at(Axes::ConvertToIndex(item.GetAxes()))->RemoveElement(item);
		item.SetX(x);
		item.SetY(y);
	}
}
bool Field::ContainName(ElementNameType name, int x, int y)
{
	return items.at(Axes::ConvertToIndex(x, y))->ContainName(name);
}
bool Field::ContainElement(Element & item)
{
	return items.at(Axes::ConvertToIndex(item.GetAxes()))->ContainElement(item);
}

void Field::RemoveElement(Element & item)
{
	items.at(Axes::ConvertToIndex(item.GetAxes()))->RemoveElement(item);
}

void Field::Destroy(int x, int y)
{
	items.at(Axes::ConvertToIndex(x, y))->RemoveElements();
}

std::vector<TagAxes> Field::CreateBlockMap()
{
	std::vector<TagAxes> result;

	for (int index = 0; index < items.size(); index++)
	{
		TagAxes newPoint = Axes::ConvertToAxes(index);

		if (items.at(index)->ContainType(ClassType::Block) == true)
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