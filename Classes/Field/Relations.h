#pragma once

// Перечисление возможных типов
enum ClassType;
// Перечисление возможных результатов
enum class ResultType;
// Расчет результата взаимодействия элементов
static class Relations
{
public:
	// Расчет взаимодействия двух типов одного и того же класса
	static ResultType DoubleCalc(ClassType type);
	// Расчет взаимодействия
	static ResultType Calc(int SumOfTypes);

	// Проверка возможности добавления
	static bool CanAdd(ClassType type, int sumOfTypes);
	// Проверка возможности уничтожения
	static bool CanDestroy(ClassType type);
};