#include "OptionForPatrol.h"

void OptionForPatrol::Update()
{
	OptionForMove::Update();

	if (this->isPatrol == true && parent->GetPointLength() > 0)
	{
		if (parent->GetLeft() == FieldPoint::ConvertToLeft(parent->GetPoint(currentIndex).GetX()) &&
			parent->GetTop() == FieldPoint::ConvertToTop(parent->GetPoint(currentIndex).GetY()))
		{
			CalcNewIndex();
		}
		else
		{
			if (isFreeze == true)
			{
				if (this->MoveTo(parent->GetPoint(currentIndex).GetX(), parent->GetPoint(currentIndex).GetY()) == false)
				{
					CalcNewIndex();
				}
			}
		}
	}
}

void OptionForPatrol::CalcNewIndex()
{
	if (this->isReturn == false)
	{
		this->currentIndex++;
	}
	// ѕатруль идет в обратную сторону
	else
	{
		this->currentIndex--;
	}
	// ѕри isCircle = true патруль ходит по кругу, иначе туда-обратно
	if (this->currentIndex >= parent->GetPointLength())
	{
		if (isDestroyInEnd == true)
		{
			parent->Destroy();
		}
		if (isCircle == true)
		{
			currentIndex = 0;
		}
		else
		{
			currentIndex--;
			isReturn = true;
		}
	}
	if (this->currentIndex < 0)
	{
		currentIndex++;
		isReturn = false;
	}
}