#include "cocostudio/CocoStudio.h"
#include "Field.h"
#include "Cell.h"
#include "Main\Settings.h"

#include "Option\BaseClass\ISMouse.h"
#include "Option\BaseClass\ISInterval.h"
#include "Main\MapHandle.h"

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
		items.at(index)->DestroyAll();
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

bool Field::CanAddElement(Element * item)
{
	return items.at(ConvertToArrayIndex(item->GetXY()))->CanAddElement(item);
}
bool Field::CanAddElement(ClassType type, int x, int y)
{
	return items.at(ConvertToArrayIndex(x, y))->CanAddElement(type);
}
void Field::AddElement(Element * item)
{
	items.at(ConvertToArrayIndex(item->GetXY()))->AddElement(item);
}
bool Field::ContainName(ElementNameType name, int x, int y)
{
	return items.at(ConvertToArrayIndex(x, y))->ContainName(name);
}
bool Field::ContainElement(Element * item)
{
	return items.at(ConvertToArrayIndex(item->GetXY()))->ContainElement(item);
}
Element * Field::GetElement(ElementNameType name, int x, int y)
{
	return items.at(ConvertToArrayIndex(x, y))->GetElement(name);
}

void Field::RemoveElement(Element * item)
{
	items.at(ConvertToArrayIndex(item->GetXY()))->RemoveElement(item);
}
void Field::RemoveElement(ElementNameType nodeName, int x, int y)
{
	Element * item = items.at(ConvertToArrayIndex(x, y))->GetElement(nodeName);
	Field::RemoveElement(item);
}

std::vector<TagAxes> Field::CreateBlockMap()
{
	std::vector<TagAxes> result;

	for (int index = 0; index < items.size(); index++)
	{
		TagAxes newPoint = Field::ConvertToPoint(index);

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

int Field::ConvertToArrayIndex(FieldPoint value)
{
	return Field::ConvertToArrayIndex(value.GetX(), value.GetY());
}
int Field::ConvertToArrayIndex(int x, int y)
{
	return y * Settings::HORIZONTALCELLCOUNT + x;
}

TagAxes Field::ConvertToPoint(int index)
{
	int x = index % Settings::HORIZONTALCELLCOUNT;
	int y = index / Settings::HORIZONTALCELLCOUNT;

	return TagAxes(x, y);
}