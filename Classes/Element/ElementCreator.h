#pragma once

// Класс управления данными элемента
class Element;
// Перечисление возможных имен
enum class ElementNameType;
// Перечисление возможных типов
enum ClassType;
// Перечисление возможных направлений
enum class SideType;

// Модуль элементов
class ElementCreator
{
public:
	// Создание элемента
	static Element Create(ElementNameType name, int x, int y);
	// Создание элемента
	static Element Create(ElementNameType name, SideType side, int x, int y);
private:
	// Создание главного персонажа
	static Element CreateNinja(SideType side, int x, int y);
	// Создание финишной клетки
	static Element CreateFinish(SideType side, int x, int y);
	// Создание стены
	static Element CreateWall(SideType side, int x, int y);
	// Создание патруля
	static Element CreatePatrol(SideType side, int x, int y);
	// Создания пушки
	static Element CreateGun(SideType side, int x, int y);
	// Создание огненного шара
	static Element CreateFireball(SideType side, int x, int y);

	// Создание элемента
	static Element Create(char * nodeName, ElementNameType name, ClassType type, SideType side, int x, int y);
};