#include "MapHandle.h"
#include "Field\Field.h"
#include "Field\PathFinder.h"
#include "Element\Element.h"
#include "Element\ElementCreator.h"
#include "Main\Settings.h"

// Главный персонаж
static Element * ninja;
// Клетка финиша
static Element * finish;
// Последняя загруженная карта
static int lastIndex;

void MapHandle::LoadDefault()
{
	MapHandle::LoadForIndex(0);
}
void MapHandle::ReloadMap()
{
	MapHandle::LoadForIndex(lastIndex);
}

bool MapHandle::CheckPath()
{
	return PathFinder::CanMoveTo(ninja->GetX(), ninja->GetY(), finish->GetX(), finish->GetY(), Field::CreateBlockMap());
}

void MapHandle::LoadForIndex(int index)
{
	switch (index)
	{
		case 1:
			MapHandle::LoadForIndex1();
			break;
		case 2:
			MapHandle::LoadForIndex2();
			break;
		default:
			MapHandle::LoadForIndex0();
			break;
	}

	lastIndex = index;
}

void MapHandle::LoadForIndex0()
{
	ninja = ElementCreator::Create(ElementNameType::Ninja, SideType::Right, 0, 0);
	finish = ElementCreator::Create(ElementNameType::Finish, Settings::HORIZONTALCELLCOUNT - 1, Settings::VERTICALCELLCOUNT - 1);

	Element * patrol1 = ElementCreator::Create(ElementNameType::Patrol, SideType::Right, 0, 5);
	patrol1->AddPoint(new FieldPoint(0, 5));
	patrol1->AddPoint(new FieldPoint(Settings::HORIZONTALCELLCOUNT - 1, 5));

	Element * patrol2 = ElementCreator::Create(ElementNameType::Patrol, SideType::Right, 2, 0);
	patrol2->AddPoint(new FieldPoint(2, 0));
	patrol2->AddPoint(new FieldPoint(2, Settings::VERTICALCELLCOUNT - 1));

	ElementCreator::Create(ElementNameType::Gun, SideType::Down, 5, 0);
	ElementCreator::Create(ElementNameType::Gun, SideType::Down, 9, 0);
	ElementCreator::Create(ElementNameType::Gun, SideType::Down, 12, 0);
	ElementCreator::Create(ElementNameType::Gun, SideType::Up, 6, 14);
	ElementCreator::Create(ElementNameType::Gun, SideType::Up, 10, 14);
	ElementCreator::Create(ElementNameType::Gun, SideType::Up, 13, 14);
}

void MapHandle::LoadForIndex1()
{
	ninja = ElementCreator::Create(ElementNameType::Ninja, SideType::Right, 0, 0);
	finish = ElementCreator::Create(ElementNameType::Finish, Settings::HORIZONTALCELLCOUNT - 1, Settings::VERTICALCELLCOUNT - 1);

	ElementCreator::Create(ElementNameType::Wall, SideType::Down, 0, 1);
	ElementCreator::Create(ElementNameType::Wall, SideType::Down, 0, 2);
	ElementCreator::Create(ElementNameType::Wall, SideType::Down, 0, 3);
	ElementCreator::Create(ElementNameType::Wall, SideType::Down, 0, 4);
	ElementCreator::Create(ElementNameType::Wall, SideType::Down, 0, 5);
	ElementCreator::Create(ElementNameType::Wall, SideType::Down, 0, 6);
	ElementCreator::Create(ElementNameType::Wall, SideType::Down, 0, 7);
	ElementCreator::Create(ElementNameType::Wall, SideType::Down, 0, 8);
	ElementCreator::Create(ElementNameType::Wall, SideType::Down, 0, 9);
	ElementCreator::Create(ElementNameType::Wall, SideType::Down, 0, 10);
	ElementCreator::Create(ElementNameType::Wall, SideType::Down, 0, 11);
	ElementCreator::Create(ElementNameType::Wall, SideType::Down, 0, 12);
	ElementCreator::Create(ElementNameType::Wall, SideType::Down, 0, 13);
	ElementCreator::Create(ElementNameType::Wall, SideType::Down, 0, 14);

	ElementCreator::Create(ElementNameType::Wall, SideType::Down, 1, 11);

	ElementCreator::Create(ElementNameType::Wall, SideType::Down, 2, 0);
	ElementCreator::Create(ElementNameType::Wall, SideType::Down, 2, 1);
	ElementCreator::Create(ElementNameType::Wall, SideType::Down, 2, 2);
	ElementCreator::Create(ElementNameType::Wall, SideType::Down, 2, 3);
	ElementCreator::Create(ElementNameType::Wall, SideType::Down, 2, 4);
	ElementCreator::Create(ElementNameType::Wall, SideType::Down, 2, 5);
	ElementCreator::Create(ElementNameType::Wall, SideType::Down, 2, 6);
	ElementCreator::Create(ElementNameType::Wall, SideType::Down, 2, 7);
	ElementCreator::Create(ElementNameType::Wall, SideType::Down, 2, 8);
	ElementCreator::Create(ElementNameType::Wall, SideType::Down, 2, 9);
	ElementCreator::Create(ElementNameType::Wall, SideType::Down, 2, 11);
	ElementCreator::Create(ElementNameType::Wall, SideType::Down, 2, 13);

	ElementCreator::Create(ElementNameType::Wall, SideType::Down, 3, 11);
	ElementCreator::Create(ElementNameType::Wall, SideType::Down, 3, 13);

	ElementCreator::Create(ElementNameType::Wall, SideType::Down, 4, 1);
	ElementCreator::Create(ElementNameType::Wall, SideType::Down, 4, 2);
	ElementCreator::Create(ElementNameType::Wall, SideType::Down, 4, 3);
	ElementCreator::Create(ElementNameType::Wall, SideType::Down, 4, 4);
	ElementCreator::Create(ElementNameType::Wall, SideType::Down, 4, 5);
	ElementCreator::Create(ElementNameType::Wall, SideType::Down, 4, 6);
	ElementCreator::Create(ElementNameType::Wall, SideType::Down, 4, 7);
	ElementCreator::Create(ElementNameType::Wall, SideType::Down, 4, 8);
	ElementCreator::Create(ElementNameType::Wall, SideType::Down, 4, 9);
	ElementCreator::Create(ElementNameType::Wall, SideType::Down, 4, 11);
	ElementCreator::Create(ElementNameType::Wall, SideType::Down, 4, 13);

	ElementCreator::Create(ElementNameType::Wall, SideType::Down, 5, 1);
	ElementCreator::Create(ElementNameType::Wall, SideType::Down, 5, 11);
	ElementCreator::Create(ElementNameType::Wall, SideType::Down, 5, 13);

	ElementCreator::Create(ElementNameType::Wall, SideType::Down, 6, 1);
	ElementCreator::Create(ElementNameType::Wall, SideType::Down, 6, 3);
	ElementCreator::Create(ElementNameType::Wall, SideType::Down, 6, 4);
	ElementCreator::Create(ElementNameType::Wall, SideType::Down, 6, 5);
	ElementCreator::Create(ElementNameType::Wall, SideType::Down, 6, 6);
	ElementCreator::Create(ElementNameType::Wall, SideType::Down, 6, 7);
	ElementCreator::Create(ElementNameType::Wall, SideType::Down, 6, 8);
	ElementCreator::Create(ElementNameType::Wall, SideType::Down, 6, 9);
	ElementCreator::Create(ElementNameType::Wall, SideType::Down, 6, 10);
	ElementCreator::Create(ElementNameType::Wall, SideType::Down, 6, 11);
	ElementCreator::Create(ElementNameType::Wall, SideType::Down, 6, 13);

	ElementCreator::Create(ElementNameType::Wall, SideType::Down, 7, 1);
	ElementCreator::Create(ElementNameType::Wall, SideType::Down, 7, 11);
	ElementCreator::Create(ElementNameType::Wall, SideType::Down, 7, 13);

	ElementCreator::Create(ElementNameType::Wall, SideType::Down, 8, 1);
	ElementCreator::Create(ElementNameType::Wall, SideType::Down, 8, 2);
	ElementCreator::Create(ElementNameType::Wall, SideType::Down, 8, 3);
	ElementCreator::Create(ElementNameType::Wall, SideType::Down, 8, 4);
	ElementCreator::Create(ElementNameType::Wall, SideType::Down, 8, 5);
	ElementCreator::Create(ElementNameType::Wall, SideType::Down, 8, 6);
	ElementCreator::Create(ElementNameType::Wall, SideType::Down, 8, 7);
	ElementCreator::Create(ElementNameType::Wall, SideType::Down, 8, 8);
	ElementCreator::Create(ElementNameType::Wall, SideType::Down, 8, 9);
	ElementCreator::Create(ElementNameType::Wall, SideType::Down, 8, 11);
	ElementCreator::Create(ElementNameType::Wall, SideType::Down, 8, 13);

	ElementCreator::Create(ElementNameType::Wall, SideType::Down, 9, 1);
	ElementCreator::Create(ElementNameType::Wall, SideType::Down, 9, 11);
	ElementCreator::Create(ElementNameType::Wall, SideType::Down, 9, 13);

	ElementCreator::Create(ElementNameType::Wall, SideType::Down, 10, 1);
	ElementCreator::Create(ElementNameType::Wall, SideType::Down, 10, 3);
	ElementCreator::Create(ElementNameType::Wall, SideType::Down, 10, 4);
	ElementCreator::Create(ElementNameType::Wall, SideType::Down, 10, 5);
	ElementCreator::Create(ElementNameType::Wall, SideType::Down, 10, 6);
	ElementCreator::Create(ElementNameType::Wall, SideType::Down, 10, 7);
	ElementCreator::Create(ElementNameType::Wall, SideType::Down, 10, 8);
	ElementCreator::Create(ElementNameType::Wall, SideType::Down, 10, 9);
	ElementCreator::Create(ElementNameType::Wall, SideType::Down, 10, 10);
	ElementCreator::Create(ElementNameType::Wall, SideType::Down, 10, 11);
	ElementCreator::Create(ElementNameType::Wall, SideType::Down, 10, 13);

	ElementCreator::Create(ElementNameType::Wall, SideType::Down, 11, 1);
	ElementCreator::Create(ElementNameType::Wall, SideType::Down, 11, 11);
	ElementCreator::Create(ElementNameType::Wall, SideType::Down, 11, 13);

	ElementCreator::Create(ElementNameType::Wall, SideType::Down, 12, 1);
	ElementCreator::Create(ElementNameType::Wall, SideType::Down, 12, 2);
	ElementCreator::Create(ElementNameType::Wall, SideType::Down, 12, 3);
	ElementCreator::Create(ElementNameType::Wall, SideType::Down, 12, 4);
	ElementCreator::Create(ElementNameType::Wall, SideType::Down, 12, 5);
	ElementCreator::Create(ElementNameType::Wall, SideType::Down, 12, 6);
	ElementCreator::Create(ElementNameType::Wall, SideType::Down, 12, 7);
	ElementCreator::Create(ElementNameType::Wall, SideType::Down, 12, 8);
	ElementCreator::Create(ElementNameType::Wall, SideType::Down, 12, 9);
	ElementCreator::Create(ElementNameType::Wall, SideType::Down, 12, 11);
	ElementCreator::Create(ElementNameType::Wall, SideType::Down, 12, 13);

	ElementCreator::Create(ElementNameType::Wall, SideType::Down, 13, 1);
	ElementCreator::Create(ElementNameType::Wall, SideType::Down, 13, 11);
	ElementCreator::Create(ElementNameType::Wall, SideType::Down, 13, 13);

	ElementCreator::Create(ElementNameType::Wall, SideType::Down, 14, 1);
	ElementCreator::Create(ElementNameType::Wall, SideType::Down, 14, 3);
	ElementCreator::Create(ElementNameType::Wall, SideType::Down, 14, 4);
	ElementCreator::Create(ElementNameType::Wall, SideType::Down, 14, 5);
	ElementCreator::Create(ElementNameType::Wall, SideType::Down, 14, 6);
	ElementCreator::Create(ElementNameType::Wall, SideType::Down, 14, 7);
	ElementCreator::Create(ElementNameType::Wall, SideType::Down, 14, 8);
	ElementCreator::Create(ElementNameType::Wall, SideType::Down, 14, 9);
	ElementCreator::Create(ElementNameType::Wall, SideType::Down, 14, 10);
	ElementCreator::Create(ElementNameType::Wall, SideType::Down, 14, 11);
	ElementCreator::Create(ElementNameType::Wall, SideType::Down, 14, 13);

	ElementCreator::Create(ElementNameType::Wall, SideType::Down, 15, 1);
	ElementCreator::Create(ElementNameType::Wall, SideType::Down, 15, 11);
	ElementCreator::Create(ElementNameType::Wall, SideType::Down, 15, 13);

	ElementCreator::Create(ElementNameType::Wall, SideType::Down, 16, 1);
	ElementCreator::Create(ElementNameType::Wall, SideType::Down, 16, 3);
	ElementCreator::Create(ElementNameType::Wall, SideType::Down, 16, 4);
	ElementCreator::Create(ElementNameType::Wall, SideType::Down, 16, 5);
	ElementCreator::Create(ElementNameType::Wall, SideType::Down, 16, 6);
	ElementCreator::Create(ElementNameType::Wall, SideType::Down, 16, 7);
	ElementCreator::Create(ElementNameType::Wall, SideType::Down, 16, 8);
	ElementCreator::Create(ElementNameType::Wall, SideType::Down, 16, 9);
	ElementCreator::Create(ElementNameType::Wall, SideType::Down, 16, 11);
	ElementCreator::Create(ElementNameType::Wall, SideType::Down, 16, 13);

	ElementCreator::Create(ElementNameType::Wall, SideType::Down, 17, 1);
	ElementCreator::Create(ElementNameType::Wall, SideType::Down, 17, 13);

	ElementCreator::Create(ElementNameType::Wall, SideType::Down, 18, 1);
	ElementCreator::Create(ElementNameType::Wall, SideType::Down, 18, 2);
	ElementCreator::Create(ElementNameType::Wall, SideType::Down, 18, 3);
	ElementCreator::Create(ElementNameType::Wall, SideType::Down, 18, 4);
	ElementCreator::Create(ElementNameType::Wall, SideType::Down, 18, 5);
	ElementCreator::Create(ElementNameType::Wall, SideType::Down, 18, 6);
	ElementCreator::Create(ElementNameType::Wall, SideType::Down, 18, 7);
	ElementCreator::Create(ElementNameType::Wall, SideType::Down, 18, 8);
	ElementCreator::Create(ElementNameType::Wall, SideType::Down, 18, 9);
	ElementCreator::Create(ElementNameType::Wall, SideType::Down, 18, 10);
	ElementCreator::Create(ElementNameType::Wall, SideType::Down, 18, 11);
	ElementCreator::Create(ElementNameType::Wall, SideType::Down, 18, 13);

	ElementCreator::Create(ElementNameType::Wall, SideType::Down, 19, 13);
}

void MapHandle::LoadForIndex2()
{
	ninja = ElementCreator::Create(ElementNameType::Ninja, SideType::Right, 0, 0);
	finish = ElementCreator::Create(ElementNameType::Finish, Settings::HORIZONTALCELLCOUNT - 1, Settings::VERTICALCELLCOUNT - 1);
}
