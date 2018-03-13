#pragma once

#include "Element\Element.h"
#include "list"

// Перечисление возможных результатов
enum class ResultType;
// Класс хранения элементов
class Cell
{
public:
	// Инициализация переменных
	Cell(const int & x, const int & y);

	// Проверка возможности добавления элемента
	bool CanAddElement(const Element & item) const { return CanAddElement(item.GetType()); };
	// Проверка возможности добавления элемента
	bool CanAddElement(const ClassType & type) const;
	// Добавить элемент
	ResultType AddElement(Element & item);
	// Проверить наличие имени в списке элементов
	bool ContainName(const ElementNameType & nodename) const;
	// Проверить наличие имени в списке элементов
	bool ContainType(const ClassType & type) const;
	// Проверить наличие элемента
	bool ContainElement(const Element & item) const;
	// Удалить элемент
	ResultType RemoveElement(Element & item);
	// Удалить все элементы
	void RemoveElements() { Destroy(true); };
private:
	// Положение ячейки по оси X
	int x;
	// Положение ячейки по оси Y
	int y;
	// Набор элементов
	std::list<Element> items;

	// Проверить наличие повторяющихся элементов
	ClassType GetDoubleElements() const;
	// Сложить все типы в один
	int GetAllTypes() const;
	// Проверить взаимодействие типов
	ResultType CheckRelations();
	// Уничтожение элементов
	void Destroy() { Destroy(false); };
	// Уничтожение элементов
	void Destroy(const bool & allItems);

	// Удаление конструктора по умолчанию
	Cell() = delete;
};