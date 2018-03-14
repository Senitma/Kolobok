#pragma once

#include "list"
#include "Element\Element.h"

// Перечисление возможных результатов
enum class ResultType;

// Класс хранения элементов
class Cell
{
public:
	// Инициализация переменных
	Cell();

	// Получить положение по оси X
	int GetX() const { return x; };
	// Получить положение по оси Y
	int GetY() const { return y; };
	// Изменить положение через индекс
	void SetIndex(const int & index);

	// Проверка возможности добавления элемента
	bool CanAddElement(const ClassType & type) const;
	// Проверить наличие имени в списке элементов
	bool ContainName(const ElementNameType & nodename) const;
	// Проверить наличие имени в списке элементов
	bool ContainType(const ClassType & type) const;
	// Проверить наличие элемента
	bool ContainElement(const Element & item) const;
	// Добавить элемент
	ResultType AddElement(Element & item);
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
};