#include "ElementData.h"

void ElementData::Destroy()
{
	if (isDestroy == false)
	{
		std::for_each(options.begin(), options.end(), [](ISInterval * item) 
		{
			item->Destroy();
			delete item;
		});

		node->getParent()->removeChild(node);
	}
}
