#pragma once

#include "Element\Element.h"

// Базовый интерфейс для всех опций
class ISOption
{
public:
	// Инициализация переменных
	ISOption(const Element & parent) : parent(parent) {};
	// Получить родителя опции
	Element & GetParent() { return parent; };
protected:
	// Родитель опции
	Element parent;
};