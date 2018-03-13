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

	if ((isRotate == true) && (parent.GetSide() != SideType::None))
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

	Elements::Create(nodeName, parent.GetSide(), calcX, calcY);
}
