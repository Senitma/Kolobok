#include "ISInterval.h"
#include "..\Field\Field.h"

// ����� ����� � �����������
static cocos2d::Vector<ISInterval *> items;

ISInterval::ISInterval()
{
	isUpdate = true;
	items.pushBack(this);
}
void ISInterval::Destroy()
{
	isUpdate == false;
	while (isActive == true)
	{
		// ����, ���� ������ �� �������� ���� ������
	}
	items.eraseObject(this);
}

void ISInterval::UpdateAll()
{
	if (Field::GetGameStatus() == GameStatusType::Gaming)
	{
		for (int index = 0; index < items.size(); index++)
		{
			if (items.at(index)->isUpdate == true)
			{
				items.at(index)->ActiveUpdate();
			}
		}
	}
}
void ISInterval::Clear()
{
	items.clear();
}

void ISInterval::ActiveUpdate()
{
	isActive == true;
	Update();
	isActive == false;
}