#include "Option\MouseType.h"
#include "Field\AxesInfo.h"

#include "OptionForMouseMove.h"

void OptionForMouseMove::MouseClick(const MouseType & type, const int & x, const int & y)
{
	if (type == MouseType::Left)
	{
		int calcX = AxesInfo::ConvertToX(x);
		int calcY = AxesInfo::ConvertToY(y);

		this->MoveTo(calcX, calcY);
	}
}
