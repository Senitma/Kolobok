#include "OptionForMouseCreateDestroy.h"
#include "Element\ClassType.h"
#include "Field\Field.h"
#include "Field\AxesInfo.h"
#include "Option\MouseType.h"

void OptionForMouseCreateDestroy::MouseClick(const MouseType & type, const int & x, const int & y)
{
	if (type == MouseType::Right)
	{
		int calcX = AxesInfo::ConvertToX(x);
		int calcY = AxesInfo::ConvertToY(y);

		this->SetOffsetX(calcX - ISOption::parent.GetX());
		this->SetOffsetY(calcY - ISOption::parent.GetY());

		if (Field::CanAddElement(ClassType::Block, calcX, calcY) == true)
		{
			this->Create();
			// ����������� ����� ���� �� ������ ����� �� ������
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
