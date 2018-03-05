#include "OptionForIntervalCreate.h"

void OptionForIntervalCreate::Update()
{
	if (isActive == true)
	{
		if (currentTime > this->interval)
		{
			currentTime = 0;
			Create();
		}
		else
		{
			currentTime++;
		}
	}
}
