#include "ElementRelations.h"

ResultType ElementRelations::DoubleCalc(ClassType type)
{
	if (type == ClassType::Block)
	{
		return ResultType::Impossible;
	}
	else if (type == ClassType::Bullet)
	{
		return ResultType::Destroy;
	}
	// Нет взаимодействия
	else
	{
		return ResultType::Nothing;
	}
}
ResultType ElementRelations::DoubleCalc(int type)
{
	return ElementRelations::DoubleCalc((ClassType)type);
}
ResultType ElementRelations::Calc(int SumOfTypes)
{
	// Character + Finish = Win
	if ((SumOfTypes & 3) == 3)
	{
		return ResultType::Win;
	}
	else if ((SumOfTypes & 4) == 4)
	{
		// Block + Bullet = Destroy
		if (SumOfTypes == 20)
		{
			return ResultType::Destroy;
		}
		// Block + Empty = Block
		else if (SumOfTypes == 4)
		{
			return ResultType::Nothing;
		}
		// А вот других случаев быть не может
		else
		{
			return ResultType::Impossible;
		}
	}
	// Character + Enemy = Lose
	else if ((SumOfTypes & 9) == 9)
	{
		return ResultType::Lose;
	}
	// Character + Bullet = Lose
	else if ((SumOfTypes & 17) == 17)
	{
		return ResultType::Lose;
	}
	// Enemy + Bullet = Destroy
	else if ((SumOfTypes & 24) == 24)
	{
		return ResultType::Destroy;
	}
	// Нет взаимодействия
	else
	{
		return ResultType::Nothing;
	}
}
bool ElementRelations::CanAdd(int type, int sumOfTypes)
{
	return ElementRelations::CanAdd((ClassType)type, sumOfTypes);
}
bool ElementRelations::CanAdd(ClassType type, int sumOfTypes)
{
	bool smart;

	switch (type)
	{
		case ClassType::Character:
			smart = true;
			break;
		case ClassType::Finish:
			smart = false;
			break;
		case ClassType::Block:
			smart = false;
			break;
		case ClassType::Enemy:
			smart = true;
			break;
		case ClassType::Bullet:
			smart = false;
			break;
	}

	return ElementRelations::CanAdd((int)type, sumOfTypes, smart);
}
bool ElementRelations::CanAdd(ClassType type, int sumOfTypes, bool smart)
{
	return ElementRelations::CanAdd((int)type, sumOfTypes, smart);
}
bool ElementRelations::CanAdd(int type, int sumOfTypes, bool smart)
{
	ResultType resultCalc;

	if ((sumOfTypes & type) == type)
	{
		resultCalc = ElementRelations::DoubleCalc(type);
	}
	else
	{ 
		resultCalc = ElementRelations::Calc(sumOfTypes + type);
	}

	// Невозможные сочетания так же отметаются
	if (resultCalc == ResultType::Impossible)
	{
		return false;
	}
	// Только NPC имеют чувство самосохранения
	// снарядам все равно
	if ((smart == true) && (resultCalc == ResultType::Destroy))
	{
		return false;
	}

	// Во всех остальных случаях добавление элемента возможно
	return true;
}

bool ElementRelations::CanDestroy(ClassType type)
{
	switch (type)
	{
		case ClassType::Character:
			return true;
		case ClassType::Enemy:
			return true;
		case ClassType::Bullet:
			return true;
		default:
			return false;
	}
}
