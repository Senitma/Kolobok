#pragma once

#include "cocos2d.h"
#include "Element.h"
#include "ElementNameType.h"
#include "ClassType.h"
#include "SideType.h"

// Класс создания элементов
class ElementCreator : private cocos2d::Ref
{
public:
	// Создание элемента
	static Element Create(ElementNameType name, int x, int y);
	// Создание элемента
	static Element Create(ElementNameType name, SideType side, int x, int y);
private:
	// Создание главного персонажа
	static Element CreateNinja(SideType side, int x, int y);
	// Создание финишной клетки
	static Element CreateFinish(SideType side, int x, int y);
	// Создание стены
	static Element CreateWall(SideType side, int x, int y);
	// Создание патруля
	static Element CreatePatrol(SideType side, int x, int y);
	// Создания пушки
	static Element CreateGun(SideType side, int x, int y);
	// Создание огненного шара
	static Element CreateFireball(SideType side, int x, int y);

	// Создание элемента
	static Element Create(char * nodeName, ElementNameType name, ClassType type, SideType side, int x, int y);
};