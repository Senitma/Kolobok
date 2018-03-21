#include "Element\ClassType.h"
#include "Field\Field.h"
#include "Field\AxesInfo.h"
#include "Option\MouseType.h"
#include "Settings.h"

#include "OptionForMouseCreateDestroy.h"

void OptionForMouseCreateDestroy::MouseClick(const MouseType & type, const int & x, const int & y)
{
	if (type == MouseType::Right)
	{
		int calcX = AxesInfo::ConvertToX(x);
		int calcY = AxesInfo::ConvertToY(y);

		if ((calcX >= 0) && (calcY >= 0) && (calcX < Settings::HORIZONTALCELLCOUNT) && (calcY < Settings::VERTICALCELLCOUNT))
		{

			SetOffsetX(calcX - ISOption::parent.GetX());
			SetOffsetY(calcY - ISOption::parent.GetY());

			if (Field::CanAddElement(ClassType::Block, calcX, calcY) == true)
			{
				Create();
				// ”ничтожение блока если он мешает дойти до финиша
				if (Field::CheckPath() == false)
				{
					Field::Destroy(calcX, calcY);
				}
			}
			else
			{
				if (Field::ContainName(nodeName, calcX, calcY) == true)
				{
					Field::Destroy(calcX, calcY);
				}
			}
		}
	}
}
