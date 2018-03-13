#pragma once

// Класс управления данными элемента
class Element;
// Перечисление возможных имен
enum class ElementNameType;
// Перечисление возможных типов
enum ClassType;
// Перечисление возможных направлений
enum class SideType;

// Модуль управления элементами
namespace Elements
{
	// Создание элемента
	Element Create(ElementNameType name, int x, int y);
	// Создание элемента
	Element Create(ElementNameType name, SideType side, int x, int y);
};