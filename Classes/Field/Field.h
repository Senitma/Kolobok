#pragma once

#include "vector"
#include "Element\Element.h"

// Перечисление возможных состояний игры
enum class GameStatusType;
// Класс вершин
class Vertex;

// Модуль управления полем
namespace Field
{
	// Выгрыш
	void WinGame();
	// Проигыш
	void LoseGame();
	// Перезагрузить поле
	void Reload();
	// Получить текущее состояние игры
	GameStatusType GetCurrentGameStatus();

	// Получить ссылку на прорисовку
	cocos2d::Node * GetInstance();
	// Инициализировать ячейки
	void InitCells();
	// Прорисовка элемента на поле
	void DrawElement(cocos2d::Node * item);

	// Проверка возможности добавления элемента
	bool CanAddElement(const ClassType & type, const int & x, const int & y);
	// Проверить наличие имени в списке элементов
	bool ContainName(const ElementNameType & name, const int & x, const int & y);
	// Добавить элемент
	void AddElement(Element & value, const int & x, const int & y);
	// Переместить элемента
	void MoveElement(Element & item, const int & x, const int & y);
	// Убрать элемент
	void RemoveElement(Element & item);
	// Удалить элементы
	void Destroy(const int & x, const int & y);

	// Создать карту с блоками
	std::vector<Vertex> CreateBlockMap();
	// Проверить наличие пути от главного персонажа до финиша
	bool CheckPath();
};