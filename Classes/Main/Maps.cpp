#include "Element\ElementNameType.h"
#include "Element\SideType.h"
#include "Element\Element.h"
#include "Element\Elements.h"
#include "Field\Field.h"
#include "Settings.h"
#include "EditSettings.h"

#include "Maps.h"

// Добавление внутренних функций к пространству имен
namespace Maps
{
	// Последняя загруженная карта
	MapIndexType lastIndex;

	// Загрузка карты примера
	void LoadExample();
	// Загрузка карты лабиринта
	void LoadLabyrinth();
	// Загрузка карты для тестирования алгоритма
	void LoadAlgorithmTesth();
	// Загрузка пустой карты
	void LoadEmpty();
	// Создать пол
	void GenerateFloor();
}

void Maps::Load()
{
	Load(Settings::DEFAULTMAP);
}
void Maps::Load(MapIndexType index)
{
	switch (index)
	{
		case MapIndexType::Example:
			Maps::LoadExample();
			break;
		case MapIndexType::Labyrinth:
			Maps::LoadLabyrinth();
			break;
		case MapIndexType::AlgorithmTest:
			Maps::LoadAlgorithmTesth();
			break;
		case MapIndexType::Empty:
			Maps::LoadEmpty();
			break;
		default:
			Maps::Load();
			break;
	}

	lastIndex = index;
}
void Maps::ReloadMap()
{
	Maps::Load(lastIndex);
}

void Maps::LoadExample()
{
	EditSettings::HORIZONTALCELLCOUNT = 20;
	EditSettings::VERTICALCELLCOUNT = 15;
	GenerateFloor();

	Elements::Create(ElementNameType::Main, SideType::Right, 0, 0);
	Elements::Create(ElementNameType::Finish, Settings::HORIZONTALCELLCOUNT - 1, Settings::VERTICALCELLCOUNT - 1);

	Element & patrol1 = Elements::Create(ElementNameType::Patrol, SideType::Right, 0, 5);
	patrol1.AddPoint(0, 5);
	patrol1.AddPoint(Settings::HORIZONTALCELLCOUNT - 1, 5);

	Element & patrol2 = Elements::Create(ElementNameType::Patrol, SideType::Right, 2, 0);
	patrol2.AddPoint(2, 0);
	patrol2.AddPoint(2, Settings::VERTICALCELLCOUNT - 1);

	Elements::Create(ElementNameType::Gun, SideType::Down, 5, 0);
	Elements::Create(ElementNameType::Gun, SideType::Down, 9, 0);
	Elements::Create(ElementNameType::Gun, SideType::Down, 12, 0);
	Elements::Create(ElementNameType::Gun, SideType::Up, 6, 14);
	Elements::Create(ElementNameType::Gun, SideType::Up, 10, 14);
	Elements::Create(ElementNameType::Gun, SideType::Up, 13, 14);
}
void Maps::LoadLabyrinth()
{
	EditSettings::HORIZONTALCELLCOUNT = 20;
	EditSettings::VERTICALCELLCOUNT = 15;
	GenerateFloor();

	Elements::Create(ElementNameType::Main, SideType::Right, 0, 0);
	Elements::Create(ElementNameType::Finish, Settings::HORIZONTALCELLCOUNT - 1, Settings::VERTICALCELLCOUNT - 1);

	Elements::Create(ElementNameType::Wall, SideType::Down, 0, 1);
	Elements::Create(ElementNameType::Wall, SideType::Down, 0, 2);
	Elements::Create(ElementNameType::Wall, SideType::Down, 0, 3);
	Elements::Create(ElementNameType::Wall, SideType::Down, 0, 4);
	Elements::Create(ElementNameType::Wall, SideType::Down, 0, 5);
	Elements::Create(ElementNameType::Wall, SideType::Down, 0, 6);
	Elements::Create(ElementNameType::Wall, SideType::Down, 0, 7);
	Elements::Create(ElementNameType::Wall, SideType::Down, 0, 8);
	Elements::Create(ElementNameType::Wall, SideType::Down, 0, 9);
	Elements::Create(ElementNameType::Wall, SideType::Down, 0, 10);
	Elements::Create(ElementNameType::Wall, SideType::Down, 0, 11);
	Elements::Create(ElementNameType::Wall, SideType::Down, 0, 12);
	Elements::Create(ElementNameType::Wall, SideType::Down, 0, 13);
	Elements::Create(ElementNameType::Wall, SideType::Down, 0, 14);

	Elements::Create(ElementNameType::Wall, SideType::Down, 1, 11);

	Elements::Create(ElementNameType::Wall, SideType::Down, 2, 0);
	Elements::Create(ElementNameType::Wall, SideType::Down, 2, 1);
	Elements::Create(ElementNameType::Wall, SideType::Down, 2, 2);
	Elements::Create(ElementNameType::Wall, SideType::Down, 2, 3);
	Elements::Create(ElementNameType::Wall, SideType::Down, 2, 4);
	Elements::Create(ElementNameType::Wall, SideType::Down, 2, 5);
	Elements::Create(ElementNameType::Wall, SideType::Down, 2, 6);
	Elements::Create(ElementNameType::Wall, SideType::Down, 2, 7);
	Elements::Create(ElementNameType::Wall, SideType::Down, 2, 8);
	Elements::Create(ElementNameType::Wall, SideType::Down, 2, 9);
	Elements::Create(ElementNameType::Wall, SideType::Down, 2, 11);
	Elements::Create(ElementNameType::Wall, SideType::Down, 2, 13);

	Elements::Create(ElementNameType::Wall, SideType::Down, 3, 11);
	Elements::Create(ElementNameType::Wall, SideType::Down, 3, 13);

	Elements::Create(ElementNameType::Wall, SideType::Down, 4, 1);
	Elements::Create(ElementNameType::Wall, SideType::Down, 4, 2);
	Elements::Create(ElementNameType::Wall, SideType::Down, 4, 3);
	Elements::Create(ElementNameType::Wall, SideType::Down, 4, 4);
	Elements::Create(ElementNameType::Wall, SideType::Down, 4, 5);
	Elements::Create(ElementNameType::Wall, SideType::Down, 4, 6);
	Elements::Create(ElementNameType::Wall, SideType::Down, 4, 7);
	Elements::Create(ElementNameType::Wall, SideType::Down, 4, 8);
	Elements::Create(ElementNameType::Wall, SideType::Down, 4, 9);
	Elements::Create(ElementNameType::Wall, SideType::Down, 4, 11);
	Elements::Create(ElementNameType::Wall, SideType::Down, 4, 13);

	Elements::Create(ElementNameType::Wall, SideType::Down, 5, 1);
	Elements::Create(ElementNameType::Wall, SideType::Down, 5, 11);
	Elements::Create(ElementNameType::Wall, SideType::Down, 5, 13);

	Elements::Create(ElementNameType::Wall, SideType::Down, 6, 1);
	Elements::Create(ElementNameType::Wall, SideType::Down, 6, 3);
	Elements::Create(ElementNameType::Wall, SideType::Down, 6, 4);
	Elements::Create(ElementNameType::Wall, SideType::Down, 6, 5);
	Elements::Create(ElementNameType::Wall, SideType::Down, 6, 6);
	Elements::Create(ElementNameType::Wall, SideType::Down, 6, 7);
	Elements::Create(ElementNameType::Wall, SideType::Down, 6, 8);
	Elements::Create(ElementNameType::Wall, SideType::Down, 6, 9);
	Elements::Create(ElementNameType::Wall, SideType::Down, 6, 10);
	Elements::Create(ElementNameType::Wall, SideType::Down, 6, 11);
	Elements::Create(ElementNameType::Wall, SideType::Down, 6, 13);

	Elements::Create(ElementNameType::Wall, SideType::Down, 7, 1);
	Elements::Create(ElementNameType::Wall, SideType::Down, 7, 11);
	Elements::Create(ElementNameType::Wall, SideType::Down, 7, 13);

	Elements::Create(ElementNameType::Wall, SideType::Down, 8, 1);
	Elements::Create(ElementNameType::Wall, SideType::Down, 8, 2);
	Elements::Create(ElementNameType::Wall, SideType::Down, 8, 3);
	Elements::Create(ElementNameType::Wall, SideType::Down, 8, 4);
	Elements::Create(ElementNameType::Wall, SideType::Down, 8, 5);
	Elements::Create(ElementNameType::Wall, SideType::Down, 8, 6);
	Elements::Create(ElementNameType::Wall, SideType::Down, 8, 7);
	Elements::Create(ElementNameType::Wall, SideType::Down, 8, 8);
	Elements::Create(ElementNameType::Wall, SideType::Down, 8, 9);
	Elements::Create(ElementNameType::Wall, SideType::Down, 8, 11);
	Elements::Create(ElementNameType::Wall, SideType::Down, 8, 13);

	Elements::Create(ElementNameType::Wall, SideType::Down, 9, 1);
	Elements::Create(ElementNameType::Wall, SideType::Down, 9, 11);
	Elements::Create(ElementNameType::Wall, SideType::Down, 9, 13);

	Elements::Create(ElementNameType::Wall, SideType::Down, 10, 1);
	Elements::Create(ElementNameType::Wall, SideType::Down, 10, 3);
	Elements::Create(ElementNameType::Wall, SideType::Down, 10, 4);
	Elements::Create(ElementNameType::Wall, SideType::Down, 10, 5);
	Elements::Create(ElementNameType::Wall, SideType::Down, 10, 6);
	Elements::Create(ElementNameType::Wall, SideType::Down, 10, 7);
	Elements::Create(ElementNameType::Wall, SideType::Down, 10, 8);
	Elements::Create(ElementNameType::Wall, SideType::Down, 10, 9);
	Elements::Create(ElementNameType::Wall, SideType::Down, 10, 10);
	Elements::Create(ElementNameType::Wall, SideType::Down, 10, 11);
	Elements::Create(ElementNameType::Wall, SideType::Down, 10, 13);

	Elements::Create(ElementNameType::Wall, SideType::Down, 11, 1);
	Elements::Create(ElementNameType::Wall, SideType::Down, 11, 11);
	Elements::Create(ElementNameType::Wall, SideType::Down, 11, 13);

	Elements::Create(ElementNameType::Wall, SideType::Down, 12, 1);
	Elements::Create(ElementNameType::Wall, SideType::Down, 12, 2);
	Elements::Create(ElementNameType::Wall, SideType::Down, 12, 3);
	Elements::Create(ElementNameType::Wall, SideType::Down, 12, 4);
	Elements::Create(ElementNameType::Wall, SideType::Down, 12, 5);
	Elements::Create(ElementNameType::Wall, SideType::Down, 12, 6);
	Elements::Create(ElementNameType::Wall, SideType::Down, 12, 7);
	Elements::Create(ElementNameType::Wall, SideType::Down, 12, 8);
	Elements::Create(ElementNameType::Wall, SideType::Down, 12, 9);
	Elements::Create(ElementNameType::Wall, SideType::Down, 12, 11);
	Elements::Create(ElementNameType::Wall, SideType::Down, 12, 13);

	Elements::Create(ElementNameType::Wall, SideType::Down, 13, 1);
	Elements::Create(ElementNameType::Wall, SideType::Down, 13, 11);
	Elements::Create(ElementNameType::Wall, SideType::Down, 13, 13);

	Elements::Create(ElementNameType::Wall, SideType::Down, 14, 1);
	Elements::Create(ElementNameType::Wall, SideType::Down, 14, 3);
	Elements::Create(ElementNameType::Wall, SideType::Down, 14, 4);
	Elements::Create(ElementNameType::Wall, SideType::Down, 14, 5);
	Elements::Create(ElementNameType::Wall, SideType::Down, 14, 6);
	Elements::Create(ElementNameType::Wall, SideType::Down, 14, 7);
	Elements::Create(ElementNameType::Wall, SideType::Down, 14, 8);
	Elements::Create(ElementNameType::Wall, SideType::Down, 14, 9);
	Elements::Create(ElementNameType::Wall, SideType::Down, 14, 10);
	Elements::Create(ElementNameType::Wall, SideType::Down, 14, 11);
	Elements::Create(ElementNameType::Wall, SideType::Down, 14, 13);

	Elements::Create(ElementNameType::Wall, SideType::Down, 15, 1);
	Elements::Create(ElementNameType::Wall, SideType::Down, 15, 11);
	Elements::Create(ElementNameType::Wall, SideType::Down, 15, 13);

	Elements::Create(ElementNameType::Wall, SideType::Down, 16, 1);
	Elements::Create(ElementNameType::Wall, SideType::Down, 16, 3);
	Elements::Create(ElementNameType::Wall, SideType::Down, 16, 4);
	Elements::Create(ElementNameType::Wall, SideType::Down, 16, 5);
	Elements::Create(ElementNameType::Wall, SideType::Down, 16, 6);
	Elements::Create(ElementNameType::Wall, SideType::Down, 16, 7);
	Elements::Create(ElementNameType::Wall, SideType::Down, 16, 8);
	Elements::Create(ElementNameType::Wall, SideType::Down, 16, 9);
	Elements::Create(ElementNameType::Wall, SideType::Down, 16, 11);
	Elements::Create(ElementNameType::Wall, SideType::Down, 16, 13);

	Elements::Create(ElementNameType::Wall, SideType::Down, 17, 1);
	Elements::Create(ElementNameType::Wall, SideType::Down, 17, 13);

	Elements::Create(ElementNameType::Wall, SideType::Down, 18, 1);
	Elements::Create(ElementNameType::Wall, SideType::Down, 18, 2);
	Elements::Create(ElementNameType::Wall, SideType::Down, 18, 3);
	Elements::Create(ElementNameType::Wall, SideType::Down, 18, 4);
	Elements::Create(ElementNameType::Wall, SideType::Down, 18, 5);
	Elements::Create(ElementNameType::Wall, SideType::Down, 18, 6);
	Elements::Create(ElementNameType::Wall, SideType::Down, 18, 7);
	Elements::Create(ElementNameType::Wall, SideType::Down, 18, 8);
	Elements::Create(ElementNameType::Wall, SideType::Down, 18, 9);
	Elements::Create(ElementNameType::Wall, SideType::Down, 18, 10);
	Elements::Create(ElementNameType::Wall, SideType::Down, 18, 11);
	Elements::Create(ElementNameType::Wall, SideType::Down, 18, 13);

	Elements::Create(ElementNameType::Wall, SideType::Down, 19, 13);
}
void Maps::LoadAlgorithmTesth()
{
	EditSettings::OFFSETX = 100;
	EditSettings::OFFSETY = -300;

	EditSettings::HORIZONTALCELLCOUNT = 16;
	EditSettings::VERTICALCELLCOUNT = 7;
	GenerateFloor();

	Elements::Create(ElementNameType::Main, SideType::Right, 1, 1);
	Elements::Create(ElementNameType::Finish, 14, 5);

	Elements::Create(ElementNameType::Wall, SideType::Down, 0, 0);
	Elements::Create(ElementNameType::Wall, SideType::Down, 0, 1);
	Elements::Create(ElementNameType::Wall, SideType::Down, 0, 2);
	Elements::Create(ElementNameType::Wall, SideType::Down, 0, 3);
	Elements::Create(ElementNameType::Wall, SideType::Down, 0, 4);
	Elements::Create(ElementNameType::Wall, SideType::Down, 0, 5);
	Elements::Create(ElementNameType::Wall, SideType::Down, 0, 6);

	Elements::Create(ElementNameType::Wall, SideType::Down, 1, 0);
	Elements::Create(ElementNameType::Wall, SideType::Down, 1, 6);

	Elements::Create(ElementNameType::Wall, SideType::Down, 2, 0);
	Elements::Create(ElementNameType::Wall, SideType::Down, 2, 4);
	Elements::Create(ElementNameType::Wall, SideType::Down, 2, 5);
	Elements::Create(ElementNameType::Wall, SideType::Down, 2, 6);

	Elements::Create(ElementNameType::Wall, SideType::Down, 3, 0);
	Elements::Create(ElementNameType::Wall, SideType::Down, 3, 1);
	Elements::Create(ElementNameType::Wall, SideType::Down, 3, 4);
	Elements::Create(ElementNameType::Wall, SideType::Down, 3, 5);
	Elements::Create(ElementNameType::Wall, SideType::Down, 3, 6);

	Elements::Create(ElementNameType::Wall, SideType::Down, 4, 0);
	Elements::Create(ElementNameType::Wall, SideType::Down, 4, 6);

	Elements::Create(ElementNameType::Wall, SideType::Down, 5, 0);
	Elements::Create(ElementNameType::Wall, SideType::Down, 5, 5);
	Elements::Create(ElementNameType::Wall, SideType::Down, 5, 6);

	Elements::Create(ElementNameType::Wall, SideType::Down, 6, 0);
	Elements::Create(ElementNameType::Wall, SideType::Down, 6, 6);

	Elements::Create(ElementNameType::Wall, SideType::Down, 7, 0);
	Elements::Create(ElementNameType::Wall, SideType::Down, 7, 6);

	Elements::Create(ElementNameType::Wall, SideType::Down, 8, 0);
	Elements::Create(ElementNameType::Wall, SideType::Down, 8, 1);
	Elements::Create(ElementNameType::Wall, SideType::Down, 8, 2);
	Elements::Create(ElementNameType::Wall, SideType::Down, 8, 3);
	Elements::Create(ElementNameType::Wall, SideType::Down, 8, 4);
	Elements::Create(ElementNameType::Wall, SideType::Down, 8, 6);

	Elements::Create(ElementNameType::Wall, SideType::Down, 9, 0);
	Elements::Create(ElementNameType::Wall, SideType::Down, 9, 6);

	Elements::Create(ElementNameType::Wall, SideType::Down, 10, 0);
	Elements::Create(ElementNameType::Wall, SideType::Down, 10, 3);
	Elements::Create(ElementNameType::Wall, SideType::Down, 10, 6);

	Elements::Create(ElementNameType::Wall, SideType::Down, 11, 0);
	Elements::Create(ElementNameType::Wall, SideType::Down, 11, 2);
	Elements::Create(ElementNameType::Wall, SideType::Down, 11, 3);
	Elements::Create(ElementNameType::Wall, SideType::Down, 11, 4);
	Elements::Create(ElementNameType::Wall, SideType::Down, 11, 6);

	Elements::Create(ElementNameType::Wall, SideType::Down, 12, 0);
	Elements::Create(ElementNameType::Wall, SideType::Down, 12, 3);
	Elements::Create(ElementNameType::Wall, SideType::Down, 12, 6);

	Elements::Create(ElementNameType::Wall, SideType::Down, 13, 0);
	Elements::Create(ElementNameType::Wall, SideType::Down, 13, 6);

	Elements::Create(ElementNameType::Wall, SideType::Down, 14, 0);
	Elements::Create(ElementNameType::Wall, SideType::Down, 14, 1);
	Elements::Create(ElementNameType::Wall, SideType::Down, 14, 2);
	Elements::Create(ElementNameType::Wall, SideType::Down, 14, 3);
	Elements::Create(ElementNameType::Wall, SideType::Down, 14, 4);
	Elements::Create(ElementNameType::Wall, SideType::Down, 14, 6);

	Elements::Create(ElementNameType::Wall, SideType::Down, 15, 0);
	Elements::Create(ElementNameType::Wall, SideType::Down, 15, 1);
	Elements::Create(ElementNameType::Wall, SideType::Down, 15, 2);
	Elements::Create(ElementNameType::Wall, SideType::Down, 15, 3);
	Elements::Create(ElementNameType::Wall, SideType::Down, 15, 4);
	Elements::Create(ElementNameType::Wall, SideType::Down, 15, 5);
	Elements::Create(ElementNameType::Wall, SideType::Down, 15, 6);
}
void Maps::LoadEmpty()
{
	GenerateFloor();

	Elements::Create(ElementNameType::Main, SideType::Right, 0, 0);
	Elements::Create(ElementNameType::Finish, Settings::HORIZONTALCELLCOUNT - 1, Settings::VERTICALCELLCOUNT - 1);
}

void Maps::GenerateFloor()
{
	Field::InitCells();

	for (int y = 0; y < Settings::VERTICALCELLCOUNT; y++)
	{
		for (int x = 0; x < Settings::HORIZONTALCELLCOUNT; x++)
		{
			Elements::Create(ElementNameType::Floor, x, y);
		}
	}
}
