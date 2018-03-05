#pragma once

#include "Element\Element.h"
#include "Option\BaseClass\ISInterval.h"

// Класс управления элементом
class AdvancedElement : public Element
{
public:
	// Инициализация переменных
	AdvancedElement() : Element() { isDestroy = true; };
	// Инициализация переменных
	AdvancedElement(cocos2d::Node * node, ElementNameType name, ClassType type) : Element(node, name, type) { isDestroy = false; };
	// Изменить координаты по оси X
	void SetX(int value) { currentPoint->SetX(value); };
	// Изменить координаты по оси Y
	void SetY(int value) { currentPoint->SetY(value); };
	// Изменить координаты
	void SetXY(FieldPoint value);
	// Изменить направление
	void SetSide(SideType value);

	// Получить смещение слева
	int GetLeft();
	// Получить смещение сверху
	int GetTop();
	// Изменить смещение
	void SetPosition(cocos2d::Vec2 value);
	// Получить угол вращения
	int GetRotation();
	// Измениь угол вращения
	void SetRotation(int value);

	// Добавить опцию
	void AddOption(ISInterval * option) { items.pushBack(option); };
	// Уничтожить элемент
	void Destroy() override;
private:
	// Защита от повторной очистки
	bool isDestroy;
	// Набор опций
	cocos2d::Vector<ISInterval *> items;
};