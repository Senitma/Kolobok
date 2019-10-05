#include "ResultType.h"
#include "Element\ClassType.h"

#include "Relations.h"

ResultType Relations::DoubleCalc(ClassType type)
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
		return ResultType::None;
	}
}
ResultType Relations::Calc(int SumOfTypes)
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
			return ResultType::None;
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
		return ResultType::None;
	}
}
bool Relations::CanAdd(ClassType type, int sumOfTypes)
{
	ResultType resultCalc;

	if ((sumOfTypes & type) == type)
	{
		resultCalc = DoubleCalc(type);
	}
	else
	{
		resultCalc = Calc(sumOfTypes + type);
	}

	// Невозможные сочетания отметаются
	if (resultCalc == ResultType::Impossible)
	{
		return false;
	}

	// Добавление элемента возможно
	return true;
}

bool Relations::CanDestroy(ClassType type)
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

int Relations::GetOrderDelta(ClassType type)
{
	switch (type)
	{
	case Character:
		return 3;
	case Finish:
		return 1;
	case Block:
		return 5;
	case Enemy:
		return 2;
	case Bullet:
		return 4;
	default:
		return 1;
	}
}
