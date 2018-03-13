#include "OptionForIntervalCreate.h"

OptionForIntervalCreate::OptionForIntervalCreate(Element & parent) : OptionForCreate(parent), ISInterval(parent)
{
	isActive = false;
	interval = 0;
	currentTime = 0;
}

void OptionForIntervalCreate::Update()
{
	if (isActive == true)
	{
		if (currentTime > interval)
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
