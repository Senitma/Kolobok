#include "Element\SideType.h"
#include "Field\Field.h"
#include "Field\AxesInfo.h"
#include "Settings.h"

#include "OptionForOneStep.h"

// �������� ������� ������� � �������� ���� (2^4)
const int CLOCKWIZEROTATION = 16;
// �������� �����
const int QUADRANTOFCIRCLE = 90;

void OptionForOneStep::Update()
{
	// ����� ��� ����������� ��������
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
	// ����� ��� �������� ��������
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
		// �������� �����������
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
		// �������� ��������
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
			// ������ �� ������
			break;
	}
}
void OptionForOneStep::MoveTo(const int & x, const int & y)
{
	// ������� � ������� ��������� �� ����� ������������ ���������� �����������
	// ������� �� ����� �������� ���������� �� ����� ��������
	if ((moveSpeed > 0 ) && (GetCurrentStatus() == StatusType::Stand))
	{
		int calcX = parent.GetX() - x;
		int calcY = parent.GetY() - y;

		// ����� ������������� ������ ��� �������� ������
		if ((calcX * calcY == 0) && (calcX + calcY == -1 || calcX + calcY == 1))
		{
			SideType calcSide;
			if (calcX == 1) { calcSide = SideType::Left; }
			else if (calcY == 1) { calcSide = SideType::Up; }
			else if (calcX == -1) { calcSide = SideType::Right; }
			else { calcSide = SideType::Down; }

			// ������� � ������� ��������� �������� ������������ ��� ��������
			if ((rotateSpeed == 0) || (calcSide == parent.GetSide()))
			{
				if (Field::CanAddElement(parent.GetType(), x, y) == true)
				{
					Field::MoveElement(parent, x, y);

					currentInterval = 0;
					maxInterval = Settings::NODEHEIGHT - moveSpeed - 1;

					// �������� SideType ��������� � ������������ � FullStatusType
					currentStatus = (FullStatusType)parent.GetSide();
				}
			}
			else
			{
				nextX = x;
				nextY = y;

				// ����������� �������� ����� �������� ������ ����� ����������
				if (GetCurrentStatus() != StatusType::Rotate)
				{
					currentInterval = 0;
					maxInterval = QUADRANTOFCIRCLE - rotateSpeed - 1;

					switch (parent.GetSide())
					{
						// ���� ������� ������ ������� ������� �����, �� ������������ � ���, ����� ������������ �� �������
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
						// �������� �� ���������
					default:
						if (calcSide == SideType::Right) { currentStatus = (FullStatusType)(SideType::Down + SideType::Right * CLOCKWIZEROTATION); }
						else { currentStatus = (FullStatusType)(SideType::Down + SideType::Left * CLOCKWIZEROTATION); }
						break;
					}
				}
			}
		}
	}
	// � �������� �������� ����� ������ ����������
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
