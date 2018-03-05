#pragma once

#include "cocos2d.h"
#include "Element\AdvancedElement.h"

// Интерфейс опции
class ISOption : public cocos2d::Ref
{
public:
	// Инициализация переменных
	ISOption() {};
	// Получить родителя опции
	AdvancedElement * GetParent() { return parent; };
	// Задать родителя опции
	virtual void SetParent(AdvancedElement * value) = 0;
protected:
	// Родитель опции
	AdvancedElement * parent;
};