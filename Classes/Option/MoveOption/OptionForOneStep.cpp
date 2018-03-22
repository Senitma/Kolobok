#include "Element\SideType.h"
#include "Element\AnimationType.h"
#include "Field\Field.h"
#include "Field\AxesInfo.h"
#include "Settings.h"

#include "OptionForOneStep.h"

// Значение полного оборота в двоичном виде (2^4)
const int CLOCKWIZEROTATION = 16;
// Четверть круга
const int QUADRANTOFCIRCLE = 90;

OptionForOneStep::OptionForOneStep(const Element & parent) : ISInterval(parent)
{
	moveSpeed = 0;
	rotateSpeed = 0;

	nextX = 0;
	nextY = 0;
	currentInterval = 0;
	maxInterval = 0;

	currentStatus = StatusType::Stand;
}

void OptionForOneStep::Update()
{
	// Метод для перемещения элемента
	auto MoveElement = [&](const float & speed, AnimationType type) 
	{
		if (currentInterval == 0)
		{
			parent.RunAnimation(type);
			currentInterval += speed;
		}
		else if (currentInterval < maxInterval) 
		{ 
			currentInterval += speed;
		}
		else
		{
			parent.SetPosition(AxesInfo::ConvertToLeft(parent.GetX()), AxesInfo::ConvertToTop(parent.GetY()));
			currentStatus = StatusType::Stand;
			Standed();
		}
	};
	// Метод для вращения элемента
	auto RotateElement = [&](const int & angle, AnimationType type, const SideType & finishSide) 
	{
		if (currentInterval == 0)
		{
			parent.RunAnimation(type);
			currentInterval += rotateSpeed;
		}
		else if (currentInterval < maxInterval)
		{
			currentInterval += rotateSpeed;
		}
		else
		{
			parent.SetSide(finishSide);
			currentStatus = StatusType::AfterRotate;
			MoveTo(nextX, nextY);
		}
	};

	switch (currentStatus)
	{
		// Операции перемещения
		case OptionForOneStep::MoveLeft:
			MoveElement(moveSpeed, AnimationType::MoveToLeft);
			break;
		case OptionForOneStep::MoveUp:
			MoveElement(moveSpeed, AnimationType::MoveToUp);
			break;
		case OptionForOneStep::MoveRight:
			MoveElement(moveSpeed, AnimationType::MoveToRight);
			break;
		case OptionForOneStep::MoveDown:
			MoveElement(moveSpeed, AnimationType::MoveToDown);
			break;
		// Операции поворота
		case OptionForOneStep::RotateLeftToUp:
			RotateElement(rotateSpeed, AnimationType::RotateLeftToUp, SideType::Up);
			break;
		case OptionForOneStep::RotateUpToLeft:
			RotateElement(rotateSpeed, AnimationType::RotateUpToLeft, SideType::Left);
			break;
		case OptionForOneStep::RotateUpToRight:
			RotateElement(rotateSpeed, AnimationType::RotateUpToRight, SideType::Right);
			break;
		case OptionForOneStep::RotateRightToUp:
			RotateElement(rotateSpeed, AnimationType::RotateRightToUp, SideType::Up);
			break;
		case OptionForOneStep::RotateRightToDown:
			RotateElement(rotateSpeed, AnimationType::RotateRightToDown, SideType::Down);
			break;
		case OptionForOneStep::RotateDownToRight:
			RotateElement(rotateSpeed, AnimationType::RotateDownToRight, SideType::Right);
			break;
		case OptionForOneStep::RotateDownToLeft:
			RotateElement(rotateSpeed, AnimationType::RotateDownToLeft, SideType::Left);
			break;
		case OptionForOneStep::RotateLeftToDown:
			RotateElement(rotateSpeed, AnimationType::RotateLeftToDown, SideType::Down);
			break;
		default:
			Standed();
			break;
	}
}
void OptionForOneStep::MoveTo(const int & x, const int & y)
{
	// Элемент с нулевой скоростью не будет обрабатывать координаты перемещения
	// Элемент не может поменять траекторию во время движения
	if ((moveSpeed > 0 ) && ((currentStatus == StatusType::Stand) || (currentStatus == StatusType::AfterRotate)))
	{
		int calcX = parent.GetX() - x;
		int calcY = parent.GetY() - y;

		// Опция предназначена только для соседних клеток
		if (CheckAxesForNear(calcX, calcY) == true)
		{
			SideType calcSide;
			if (calcX == 1) { calcSide = SideType::Left; }
			else if (calcY == 1) { calcSide = SideType::Up; }
			else if (calcX == -1) { calcSide = SideType::Right; }
			else { calcSide = SideType::Down; }

			// Объекты с нулевой скоростью вращения перемещаются без поворота
			if ((rotateSpeed == 0) || (calcSide == parent.GetSide()))
			{
				if (Field::CanAddElement(parent.GetType(), x, y) == true)
				{
					Field::MoveElement(parent, x, y);

					currentInterval = 0;
					maxInterval = Settings::CELLHEIGHT - moveSpeed - 1;

					// Значение SideType совпадают с перемещением в FullStatusType
					currentStatus = (StatusType)calcSide;
				}
				else if (currentStatus == StatusType::AfterRotate)
				{
					currentStatus = StatusType::Stand;
					Standed();
				}
			}
			else
			{
				nextX = x;
				nextY = y;

				currentInterval = 0;
				maxInterval = QUADRANTOFCIRCLE - rotateSpeed - 1;

				switch (parent.GetSide())
				{
					// Если сторона против часовой стрелки рядом, то поворачиваем к ней, иначе поворачиваем по часовой
				case SideType::Left:
					if (calcSide == SideType::Down) { currentStatus = (StatusType)(SideType::Left + SideType::Down * CLOCKWIZEROTATION); }
					else { currentStatus = (StatusType)(SideType::Left + SideType::Up * CLOCKWIZEROTATION); }
					break;
				case SideType::Up:
					if (calcSide == SideType::Left) { currentStatus = (StatusType)(SideType::Up + SideType::Left * CLOCKWIZEROTATION); }
					else { currentStatus = (StatusType)(SideType::Up + SideType::Right * CLOCKWIZEROTATION); }
					break;
				case SideType::Right:
					if (calcSide == SideType::Up) { currentStatus = (StatusType)(SideType::Right + SideType::Up * CLOCKWIZEROTATION); }
					else { currentStatus = (StatusType)(SideType::Right + SideType::Down * CLOCKWIZEROTATION); }
					break;
				case SideType::Down:
					// Значение по умолчанию
				default:
					if (calcSide == SideType::Right) { currentStatus = (StatusType)(SideType::Down + SideType::Right * CLOCKWIZEROTATION); }
					else { currentStatus = (StatusType)(SideType::Down + SideType::Left * CLOCKWIZEROTATION); }
					break;
				}
			}
		}
	}
	// В процессе поворота можно менять координаты
	else if ((moveSpeed > 0) && ((currentStatus | StatusType::Rotate) == StatusType::Rotate))
	{
		nextX = x;
		nextY = y;
	}
}

bool OptionForOneStep::CheckAxesForNear(const int & x, const int & y) const
{
	int sum = x + y;
	return ((x == 0) || (y == 0)) && (sum == -1 || sum == 1);
}
