#pragma once

#include "cocos2d.h"
#include "Element\Element.h"

// Интерфейс опции
class ISOption : public cocos2d::Ref
{
public:
	// Инициализация переменных
	ISOption(Element & parent) : parent(parent) {};
	// Получить родителя опции
	Element & GetParent() { return parent; };
protected:
	// Родитель опции
	Element parent;
};