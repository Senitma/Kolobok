#pragma once

#include "cocos2d.h"
#include "Element\Element.h"
#include "Main\GameStatusType.h"

class Field : private cocos2d::Ref
{
public:
	// Создать фон
	static cocos2d::Node * CreateBackground();

	// Прорисовка элемента на поле
	static void DrawElement(cocos2d::Node * item);
	// Выгрыш
	static void WinGame();
	// Проигыш
	static void LoseGame();
	// Перезагрузить поле
	static void Reload();
	// Получить текущий статус игры
	static GameStatusType GetGameStatus();

	// Проверка возможности добавления элемента
	static bool CanAddElement(Element * item);
	// Проверка возможности добавления элемента
	static bool CanAddElement(ClassType type, int x, int y);
	// Добавить элемент
	static void AddElement(Element *item);
	// Проверить наличие имени в списке элементов
	static bool ContainName(ElementNameType name, int x, int y);
	// Проверить наличие элемента
	static bool ContainElement(Element * item);
	// Получить элемент из списка
	static Element * GetElement(ElementNameType name, int x, int y);
	// Убрать элемент
	static void RemoveElement(Element *item);
	// Убрать элемент по его имени
	static void RemoveElement(ElementNameType name, int x, int y);

	// Создать карту с блоками
	static cocos2d::Vector<FieldPoint *> CreateBlockMap();
private:
	// Крнвертрование координат в индекс массива
	static int ConvertToArrayIndex(FieldPoint value);
	// Крнвертрование координат в индекс массива
	static int ConvertToArrayIndex(int x, int y);
	// Крнвертрование индекса массива в координаты
	static FieldPoint * ConvertToPoint(int index);
};