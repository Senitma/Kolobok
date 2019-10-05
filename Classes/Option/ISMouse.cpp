#include <algorithm>

#include "Field\Field.h"
#include "Field\GameStatusType.h"

#include "ISMouse.h"

// Набор опций
namespace
{
    std::vector<std::shared_ptr<ISMouse>> items;
    std::vector<std::shared_ptr<ISMouse>> newItems;
}

void ISMouse::Register(std::shared_ptr<ISMouse> option)
{
    newItems.push_back(option);
}

void ISMouse::PassMouseClick(const MouseType & type, const int & x, const int & y)
{
    for( auto& item : newItems )
        items.push_back( item );

    newItems.clear();

	if (Field::GetCurrentGameStatus() == GameStatusType::Gaming)
	{
        auto eraser = std::remove_if( items.begin(), items.end(), []( std::shared_ptr<ISMouse> item )
        {
            return ( item->GetParent().GetDestroyStatus() );
        } );
        items.erase( eraser, items.end() );

        for( auto& item : items )
            item->MouseClick( type, x, y );
	}
	else
	{
        items.clear();
		Field::Reload();
	}
}
