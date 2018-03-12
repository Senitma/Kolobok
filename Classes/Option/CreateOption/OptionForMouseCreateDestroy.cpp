#include "OptionForMouseCreateDestroy.h"
#include "Field\Field.h"
#include "Main\MapHandle.h"
#include "Option\MouseType.h"
#include "Field\FieldPoint.h"
#include "Element\ClassType.h"

void OptionForMouseCreateDestroy::MouseClick(const MouseType & type, const int & x, const int & y)
{
	if (type == MouseType::Right)
	{
		int calcX = FieldPoint::ConvertToX(x);
		int calcY = FieldPoint::ConvertToY(y);

		this->SetOffsetX(calcX - ISOption::parent.GetX());
		this->SetOffsetY(calcY - ISOption::parent.GetY());

		if (Field::CanAddElement(ClassType::Block, calcX, calcY) == true)
		{
			this->Create();
			// ”ничтожение блока если он мешает дойти до финиша
			if (MapHandle::CheckPath() == false)
			{
				Field::Destroy(calcX, calcY);
			}
		}
		else
		{
			if (Field::ContainName(this->nodeName, calcX, calcY) == true)
			{
				Field::Destroy(calcX, calcY);
			}
		}
	}
}
