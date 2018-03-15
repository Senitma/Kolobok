#include "OptionForCreate.h"
#include "Element\Elements.h"
#include "Element\SideType.h"

OptionForCreate::OptionForCreate(Element & parent) : ISOption(parent)
{
	nodeName = ElementNameType();

	offsetX = 0;
	offsetY = 0;
	isRotate = false;
}

void OptionForCreate::Create()
{
	int calcX;
	int calcY;
	SideType side;

	if (isRotate == true)
	{
		side = parent.GetSide();

		switch (side)
		{
			case SideType::Left:
				calcX = parent.GetX() - offsetX;
				calcY = parent.GetY() + offsetY;
				break;
			case SideType::Up:
				calcX = parent.GetX() - offsetX;
				calcY = parent.GetY() - offsetY;
				break;
			case SideType::Right:
				calcX = parent.GetX() + offsetX;
				calcY = parent.GetY() - offsetY;
				break;
			case SideType::Down:
				// «начение по умолчнию
			default:
				calcX = parent.GetX() + offsetX;
				calcY = parent.GetY() + offsetY;
				break;
		}
	}
	else
	{
		// Ѕез учитывани€ поворота смещение происходит по SideType::Down методу
		side = SideType::Down;
		calcX = parent.GetX() + offsetX;
		calcY = parent.GetY() + offsetY;
	}

	Elements::Create(nodeName, side, calcX, calcY);
}
