#include "Element\SideType.h"
#include "Field\Field.h"
#include "Field\AxesInfo.h"
#include "Settings.h"

#include "OptionForOneStep.h"

// Значение полного оборота в двоичном виде (2^4)
const int CLOCKWIZEROTATION = 16;
// Четверть круга
const int QUADRANTOFCIRCLE = 90;

void OptionForOneStep::Update()
{
	// Метод для перемещения элемента
	auto MoveElement = [&](const int & offsetX, const int & offsetY) 
	{
		if (currentInterval < maxInterval) 
		{ 
			parent.SetPosition(parent.GetLeft() + offsetX, parent.GetTop() + offsetY);
			currentInterval += abs(offsetX + offsetY);
		}
		else
		{
			parent.SetPosition(AxesInfo::ConvertToLeft(parent.GetX()), AxesInfo::ConvertToTop(parent.GetY()));
			currentStatus = (FullStatusType)StatusType::Stand;
		}
	};
	// Метод для вращения элемента
	auto RotateElement = [&](const int & angle, const SideType & finishSide) 
	{
		if (currentInterval < maxInterval)
		{
			parent.SetRotation(parent.GetRotation() + angle);
			currentInterval += abs(angle);
		}
		else
		{
			parent.SetSide(finishSide);
			currentStatus = (FullStatusType)StatusType::Stand;
			MoveTo(nextX, nextY);
		}
	};

	switch (currentStatus)
	{
		// Операции перемещения
		case OptionForOneStep::MoveLeft:
			MoveElement(-moveSpeed, 0);
			break;
		case OptionForOneStep::MoveUp:
			MoveElement(0, moveSpeed);
			break;
		case OptionForOneStep::MoveRight:
			MoveElement(moveSpeed, 0);
			break;
		case OptionForOneStep::MoveDown:
			MoveElement(0, -moveSpeed);
			break;
		// Операции поворота
		case OptionForOneStep::RotateUpToLeft:
			RotateElement(-rotateSpeed, SideType::Left);
			break;
		case OptionForOneStep::RotateDownToLeft:
			RotateElement(rotateSpeed, SideType::Left);
			break;
		case OptionForOneStep::RotateLeftToUp:
			RotateElement(rotateSpeed, SideType::Up);
			break;
		case OptionForOneStep::RotateRightToUp:
			RotateElement(-rotateSpeed, SideType::Up);
			break;
		case OptionForOneStep::RotateUpToRight:
			RotateElement(rotateSpeed, SideType::Right);
			break;
		case OptionForOneStep::RotateDownToRight:
			RotateElement(-rotateSpeed, SideType::Right);
			break;
		case OptionForOneStep::RotateLeftToDown:
			RotateElement(-rotateSpeed, SideType::Down);
			break;
		case OptionForOneStep::RotateRightToDown:
			RotateElement(rotateSpeed, SideType::Down);
			break;
		default:
			// Ничего не делает
			break;
	}
}
void OptionForOneStep::MoveTo(const int & x, const int & y)
{
	// Элемент с нулевой скоростью не будет обрабатывать координаты перемещения
	// Элемент не может поменять траекторию во время движения
	if ((moveSpeed > 0 ) && (GetCurrentStatus() == StatusType::Stand))
	{
		int calcX = parent.GetX() - x;
		int calcY = parent.GetY() - y;

		// Опция предназначена только для соседних клеток
		if ((calcX * calcY == 0) && (calcX + calcY == -1 || calcX + calcY == 1))
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
					maxInterval = Settings::NODEHEIGHT - moveSpeed - 1;

					// Значение SideType совпадают с перемещением в FullStatusType
					currentStatus = (FullStatusType)parent.GetSide();
				}
			}
			else
			{
				nextX = x;
				nextY = y;

				// Направление поворота можно изменить только между четвертями
				if (GetCurrentStatus() != StatusType::Rotate)
				{
					currentInterval = 0;
					maxInterval = QUADRANTOFCIRCLE - rotateSpeed - 1;

					switch (parent.GetSide())
					{
						// Если сторона против часовой стрелки рядом, то поворачиваем к ней, иначе поворачиваем по часовой
					case SideType::Left:
						if (calcSide == SideType::Down) { currentStatus = (FullStatusType)(SideType::Left + SideType::Down * CLOCKWIZEROTATION); }
						else { currentStatus = (FullStatusType)(SideType::Left + SideType::Up * CLOCKWIZEROTATION); }
						break;
					case SideType::Up:
						if (calcSide == SideType::Left) { currentStatus = (FullStatusType)(SideType::Up + SideType::Left * CLOCKWIZEROTATION); }
						else { currentStatus = (FullStatusType)(SideType::Up + SideType::Right * CLOCKWIZEROTATION); }
						break;
					case SideType::Right:
						if (calcSide == SideType::Up) { currentStatus = (FullStatusType)(SideType::Right + SideType::Up * CLOCKWIZEROTATION); }
						else { currentStatus = (FullStatusType)(SideType::Right + SideType::Down * CLOCKWIZEROTATION); }
						break;
					case SideType::Down:
						// Значение по умолчанию
					default:
						if (calcSide == SideType::Right) { currentStatus = (FullStatusType)(SideType::Down + SideType::Right * CLOCKWIZEROTATION); }
						else { currentStatus = (FullStatusType)(SideType::Down + SideType::Left * CLOCKWIZEROTATION); }
						break;
					}
				}
			}
		}
	}
	// В процессе поворота можно менять координаты
	else if ((moveSpeed > 0) && (GetCurrentStatus() == StatusType::Rotate))
	{
		nextX = x;
		nextY = y;
	}
}

OptionForOneStep::StatusType OptionForOneStep::GetCurrentStatus() const
{
	if (currentStatus == StatusType::Stand)
	{
		return StatusType::Stand;
	}
	else if ((currentStatus | StatusType::Move) == StatusType::Move)
	{
		return StatusType::Move;
	}
	else if ((currentStatus | StatusType::Rotate) == StatusType::Rotate)
	{
		return StatusType::Rotate;
	}
	else
	{
		return StatusType::Stand;
	}
}
