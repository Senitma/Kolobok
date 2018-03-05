#pragma once

#include "cocos2d.h"
#include "ClassType.h"
#include "ResultType.h"

// Расчет результата взаимодействия элементов
class ElementRelations : cocos2d::Ref
{
public:
	// Расчет взаимодействия двух типов одного и того же класса
	static ResultType DoubleCalc(ClassType type);
	// Расчет взаимодействия двух типов одного и того же класса
	static ResultType DoubleCalc(int type);
	// Расчет взаимодействия
	static ResultType Calc(int SumOfTypes);

	// Проверка возможности добавления
	static bool CanAdd(ClassType type, int sumOfTypes);
	// Проверка возможности добавления
	static bool CanAdd(int type, int sumOfTypes);
	// Проверка возможности добавления
	static bool CanAdd(ClassType type, int sumOfTypes, bool smart);
	// Проверка возможности добавления
	static bool CanAdd(int type, int sumOfTypes, bool smart);
	// Проверка возможности уничтожения
	static bool CanDestroy(ClassType type);
};
