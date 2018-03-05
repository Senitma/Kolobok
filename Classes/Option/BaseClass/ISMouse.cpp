#include "ISMouse.h"
#include "Field\Field.h"
#include "Main\Settings.h"

static cocos2d::Vector<ISMouse *> items;

ISMouse::ISMouse()
{
	items.pushBack(this);
}
ISMouse::~ISMouse()
{
	items.eraseObject(this);
}

void ISMouse::MouseClickAll(MouseType type, int x, int y)
{
	if (Field::GetGameStatus() == GameStatusType::Gaming)
	{
		for (int index = 0; index < items.size(); index++)
		{
			items.at(index)->MouseClick(type, x, Settings::HEIGHTSIZE - y);
		}
	}
	else
	{
		Field::Reload();
	}
}
void ISMouse::Clear()
{
	items.clear();
}