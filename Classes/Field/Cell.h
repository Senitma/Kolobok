#pragma once

#include "cocos2d.h"
#include "Element\AdvancedElement.h"
#include "list"

// Класс хранения элементов
struct Cell : public cocos2d::Ref
{
public:
	// Проверка возможности добавления элемента
	bool CanAddElement(const AdvancedElement & item) const { return CanAddElement(item.GetType()); };
	// Проверка возможности добавления элемента
	bool CanAddElement(const ClassType & type) const;
	// Добавить элемент
	void AddElement(AdvancedElement & item);
	// Проверить наличие имени в списке элементов
	bool ContainName(const ElementNameType & nodename) const;
	// Проверить наличие имени в списке элементов
	bool ContainType(const ClassType & type) const;
	// Проверить наличие элемента
	bool ContainElement(const AdvancedElement & item) const;
	// Удалить элемент
	void RemoveElement(AdvancedElement & item);
	// Удалить все элементы
	void DestroyAll() { Destroy(true); };
private:
	// Набор элементов
	std::list<AdvancedElement> items;

	// Проверить наличие повторяющихся элементов
	ClassType GetDoubleElements();
	// Сложить все типы в один
	int GetAllTypes() const;
	// Проверить взаимодействие типов
	void CheckRelations();
	// Уничтожение элементов
	void Destroy() { Destroy(false); };
	// Уничтожение элементов
	void Destroy(bool allItems);
};