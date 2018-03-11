#pragma once

#include "cocos2d.h"
#include "Element\Element.h"
#include "Main\GameStatusType.h"

#include "TagAxes.h"
#include "vector"

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
	static bool CanAddElement(Element & item);
	// Проверка возможности добавления элемента
	static bool CanAddElement(ClassType type, int x, int y);
	// Добавить элемент
	static void AddElement(Element & value);
	// Переместить элемента
	static void MoveElement(Element & item, int x, int y);
	// Проверить наличие имени в списке элементов
	static bool ContainName(ElementNameType name, int x, int y);
	// Проверить наличие элемента
	static bool ContainElement(Element & item);
	// Убрать элемент
	static void RemoveElement(Element & item);
	// Удалить элементы
	static void Destroy(int x, int y);

	// Создать карту с блоками
	static std::vector<TagAxes> CreateBlockMap();
};