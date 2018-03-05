#include "OptionForOneStep.h"
#include "..\Field\Field.h"

void OptionForOneStep::Update()
{
	// ����������� � ������� �������� * 2 ����� ��� �������������� ������������ �������� / ��������
	if (this->isRotateLock == true)
	{
		isFreeze = false;

		if (currentRotate - this->rotateSpeed > this->rotate || this->rotate > currentRotate + this->rotateSpeed)
		{
			currentRotate += rotateStepSize;
			if (currentRotate >= 360)
			{
				currentRotate -= 360;
			}
			else if (currentRotate <= 0)
			{
				currentRotate += 360;
			}
			parent->SetRotation(currentRotate);
		}
		else
		{
			parent->SetSide(this->side);
			isRotateLock = false;

			MoveTo(x, y);
		}
	}
	// ������ ����� ���������� �������� ����� �������� ��������
	else if (this->isMoveLock == true)
	{
		isFreeze = false;

		if (this->currentLeft - this->moveSpeed > this->left || this->left > this->currentLeft + this->moveSpeed)
		{
			this->currentLeft += this->moveStepSize;
			parent->SetPosition(cocos2d::Vec2(currentLeft, top));
		}
		else if (this->currentTop - this->moveSpeed > this->top || this->top > this->currentTop + this->moveSpeed)
		{
			this->currentTop += this->moveStepSize;
			parent->SetPosition(cocos2d::Vec2(left, currentTop));
		}
		else
		{
			parent->SetPosition(cocos2d::Vec2(left, top));
			
			this->isMoveLock = false;
		}
	}
	else
	{
		isFreeze = true;
	}
}

bool OptionForOneStep::MoveTo(int x, int y)
{
	// ������� �� ����� �������� ���������� �� ����� ��������
	if (isMoveLock == false)
	{

		int calcX = parent->GetX() - x;
		int calcY = parent->GetY() - y;

		// ��� ���������� ����� �� �������� ������ ���� �������� top ��������� �����������
		if ((calcX * calcY == 0) && (calcX + calcY == -1 || calcX + calcY == 1))
		{
			if (Field::CanAddElement(parent->GetType(), x, y) == true)
			{
				if (calcX == 1)
				{
					this->side = SideType::Left;
					this->moveStepSize = this->moveSpeed * -1;
				}
				else if (calcX == -1)
				{
					this->side = SideType::Right;
					this->moveStepSize =this->moveSpeed;
				}
				else if (calcY == 1)
				{
					this->side = SideType::Up;
					this->moveStepSize = this->moveSpeed;
				}
				else if (calcY == -1)
				{
					this->side = SideType::Down;
					this->moveStepSize = this->moveSpeed * -1;
				}

				
				// ����� ������� �������� ������� ����� ��������� � ������ ������� (���� �� ����� ��������������)
				if ((this->isRotate == false) || (this->side == parent->GetSide()))
				{
					FillVariableForNewPoint(x, y);
					this->isMoveLock = true;
				}
				else
				{
					// ���������� ��������� ��� �������� ����� ��������
					this->x = x;
					this->y = y;
					// ������� ����� �������� ������� �������� �� ����� ��������
					this->currentRotate = parent->GetRotation();
					
					switch (this->side)
					{
					case SideType::Left:
						this->rotate = 90;
						break;
					case SideType::Right:
						this->rotate = 270;
						break;
					case SideType::Up:
						this->rotate = 180;
						break;
					default:
						this->rotate = 0;
						break;
					}

					if (this->rotate - this->currentRotate > 180)
					{
						rotateStepSize = rotateSpeed * -1;
					}
					else if (this->rotate - this->currentRotate < -180)
					{
						rotateStepSize = rotateSpeed;
					}
					else if (this->rotate - this->currentRotate > 0)
					{
						rotateStepSize = rotateSpeed;
					}
					else
					{
						rotateStepSize = rotateSpeed * -1;
					}

					parent->SetSide(SideType::None);
					this->isRotateLock = true;
				}
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}
	else if (x == oldX && y == oldY)
	{
		// ������� � �������� ����� ��������� � ���� �������������� ������ �� �������� ��������
		// ��������� �������

		moveStepSize *= -1;
		FillVariableForNewPoint(x, y);
	}

	return true;
}

void OptionForOneStep::FillVariableForNewPoint(int x, int y)
{
	this->x = x;
	this->y = y;

	oldX = parent->GetX();
	oldY = parent->GetY();
	parent->SetXY(FieldPoint(x, y));

	this->left = FieldPoint::ConvertToLeft(x);
	this->top = FieldPoint::ConvertToTop(y);

	this->currentLeft = parent->GetLeft();
	this->currentTop = parent->GetTop();
}