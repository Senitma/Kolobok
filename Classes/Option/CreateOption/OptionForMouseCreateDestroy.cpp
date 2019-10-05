#include "Element\ClassType.h"
#include "Field\Axes.h"
#include "Field\Field.h"
#include "Field\AxesInfo.h"
#include "Option\MouseType.h"
#include "Settings.h"

#include "OptionForMouseCreateDestroy.h"

void OptionForMouseCreateDestroy::MouseClick(const MouseType & type, const int & x, const int & y)
{
	if (type == MouseType::Right)
	{
		Axes calcAxes = AxesInfo::ConvertToAxes(x, y);

		if ((calcAxes.GetX() >= 0) && (calcAxes.GetY() >= 0) && (calcAxes.GetX() < Settings::HORIZONTALCELLCOUNT) && (calcAxes.GetY() < Settings::VERTICALCELLCOUNT))
		{

			SetOffsetX(calcAxes.GetX() - ISOption::parent.GetX());
			SetOffsetY(calcAxes.GetY() - ISOption::parent.GetY());

			if (Field::CanAddElement(ClassType::Block, calcAxes.GetX(), calcAxes.GetY()) == true)
			{
				Create();
				// ”ничтожение блока если он мешает дойти до финиша
				if (Field::CheckPath() == false)
				{
					Field::Destroy(calcAxes.GetX(), calcAxes.GetY());
				}
			}
			else
			{
				if (Field::ContainName(nodeName, calcAxes.GetX(), calcAxes.GetY()) == true)
				{
					Field::Destroy(calcAxes.GetX(), calcAxes.GetY());
				}
			}
		}
	}
}
