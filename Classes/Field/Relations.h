#pragma once

// Перечисление возможных типов
enum ClassType;
// Перечисление возможных результатов
enum class ResultType;
// Модуль расчета результата взаимодействия элементов
namespace Relations
{
	// Расчет взаимодействия двух типов одного и того же класса
	ResultType DoubleCalc(ClassType type);
	// Расчет взаимодействия
	ResultType Calc(int SumOfTypes);

	// Проверка возможности добавления
	bool CanAdd(ClassType type, int sumOfTypes);
	// Проверка возможности уничтожения
	bool CanDestroy(ClassType type);
};