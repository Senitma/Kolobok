#include "OptionForCreate.h"
#include "Element\ElementCreator.h"

void OptionForCreate::Create()
{
	int calcX;
	int calcY;

	if (isRotate == true && parent.GetSide() != SideType::None)
	{
		switch (parent.GetSide())
		{

			case SideType::Up:
				calcX = parent.GetX() - offsetX;
				calcY = parent.GetY() - offsetY;
				break;
			case SideType::Down:
				calcX = parent.GetX() + offsetX;
				calcY = parent.GetY() + offsetY;
				break;
			case SideType::Left:
				calcX = parent.GetX() - offsetX;
				calcY = parent.GetY() + offsetY;
				break;
			case SideType::Right:
				calcX = parent.GetX() + offsetX;
				calcY = parent.GetY() - offsetY;
				break;
		}
	}
	else
	{
		// Без учитывания поворота смещение происходит по SideType::Down методу
		calcX = parent.GetX() + offsetX;
		calcY = parent.GetY() + offsetY;
	}

	ElementCreator::Create(nodeName,parent.GetSide(), calcX, calcY);
}
