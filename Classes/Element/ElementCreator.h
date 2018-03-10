#pragma once

#include "cocos2d.h"
#include "AdvancedElement.h"
#include "ElementNameType.h"
#include "ClassType.h"
#include "SideType.h"

// Класс создания элементов
class ElementCreator : private cocos2d::Ref
{
public:
	// Создание элемента
	static AdvancedElement * Create(ElementNameType name, int x, int y);
	// Создание элемента
	static AdvancedElement * Create(ElementNameType name, SideType side, int x, int y);
private:
	// Создание главного персонажа
	static AdvancedElement * CreateNinja(SideType side, int x, int y);
	// Создание финишной клетки
	static AdvancedElement * CreateFinish(SideType side, int x, int y);
	// Создание стены
	static AdvancedElement * CreateWall(SideType side, int x, int y);
	// Создание патруля
	static AdvancedElement * CreatePatrol(SideType side, int x, int y);
	// Создания пушки
	static AdvancedElement * CreateGun(SideType side, int x, int y);
	// Создание огненного шара
	static AdvancedElement * CreateFireball(SideType side, int x, int y);

	// Создание элемента
	static AdvancedElement * Create(char * nodeName, ElementNameType name, ClassType type, SideType side, int x, int y);
};