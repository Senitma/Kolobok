#pragma once

#include "cocos2d.h"
#include "Element\Element.h"

class Element;
// Класс хранения элементов
struct Cell : public cocos2d::Ref
{
public:
	// Проверка возможности добавления элемента
	bool CanAddElement(Element * item);
	// Проверка возможности добавления элемента
	bool CanAddElement(ClassType type);
	// Добавить элемент
	void AddElement(Element * item);
	// Проверить наличие имени в списке элементов
	bool ContainName(ElementNameType nodename);
	// Проверить наличие имени в списке элементов
	bool ContainType(ClassType type);
	// Проверить наличие элемента
	bool ContainElement(Element * item);
	// Удалить элемент
	void RemoveElement(Element * item);
	// Удалить элемент по имени
	void RemoveElement(ElementNameType nodeName);
	// Получить элемент по имени
	Element * GetElement(ElementNameType nodename);
	// Удалить все элементы
	void DestroyAll();
private:
	// Набор элементов
	cocos2d::Vector<Element *> items;

	// Проверить наличие повторяющихся элементов
	ClassType GetDoubleElements();
	// Сложить все типы в один
	int GetAllTypes();
	// Проверить взаимодействие типов
	void CheckRelations();
	// Уничтожение элементов
	void Destroy();
	// Уничтожение элементов
	void Destroy(bool allItems);
};