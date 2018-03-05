#include "OptionForMouseMove.h"
#include "Headers.h"

void OptionForMouseMove::MouseClick(MouseType type, int x, int y)
{
	if (type == MouseType::Left)
	{
		int calcX = FieldPoint::ConvertToX(x);
		int calcY = FieldPoint::ConvertToY(y);

		this->MoveTo(calcX, calcY);
	}
}
