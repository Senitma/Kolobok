#include "OptionForMouseCreateDestroy.h"
#include "Field\Field.h"
#include "Main\MapHandle.h"
#include "Option\BaseClass\MouseType.h"
#include "Field\FieldPoint.h"

void OptionForMouseCreateDestroy::MouseClick(MouseType type, int x, int y)
{
	if (type == MouseType::Right)
	{
		int calcX = FieldPoint::ConvertToX(x);
		int calcY = FieldPoint::ConvertToY(y);

		this->SetOffsetX(calcX - parent->GetX());
		this->SetOffsetY(calcY - parent->GetY());

		if (Field::CanAddElement(ClassType::Block, calcX, calcY) == true)
		{
			this->Create();
			// ”ничтожение блока если он мешает дойти до финиша
			if (MapHandle::CheckPath() == false)
			{
				Field::GetElement(nodeName, calcX, calcY)->Destroy();
			}
		}
		else
		{
			if (Field::ContainName(this->nodeName, calcX, calcY) == true)
			{
				Field::GetElement(nodeName, calcX, calcY)->Destroy();
			}
		}
	}
}
