#include "Option\MouseType.h"
#include "Field\AxesInfo.h"
#include "Settings.h"

#include "OptionForMouseMove.h"

void OptionForMouseMove::MouseClick(const MouseType & type, const int & left, const int & top)
{
	if (type == MouseType::Left)
	{
		Axes calcAxes = AxesInfo::ConvertToAxes(left, top);

		if ((calcAxes.GetX() >= 0) && (calcAxes.GetY() >= 0) && (calcAxes.GetX() < Settings::HORIZONTALCELLCOUNT) && (calcAxes.GetY() < Settings::VERTICALCELLCOUNT))
		{
			MoveTo(calcAxes.GetX(), calcAxes.GetY());
		}
	}
}
