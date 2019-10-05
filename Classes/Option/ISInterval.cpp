#include <algorithm>

#include "Element\ElementNameType.h"
#include "Field\Field.h"
#include "Field\GameStatusType.h"

#include "ISInterval.h"

// Набор опций
namespace
{
    std::vector<std::shared_ptr<ISInterval>> items;
    std::vector<std::shared_ptr<ISInterval>> newItems;
}

void ISInterval::Register(std::shared_ptr<ISInterval> option)
{
    newItems.push_back(option);
}

void ISInterval::PassUpdate()
{
    for( auto& item : newItems )
        items.push_back( item );

    newItems.clear();

    auto eraser = std::remove_if( items.begin(), items.end(), []( std::shared_ptr<ISInterval> item )
    {
        return ( item->GetParent().GetDestroyStatus() );
    } );
    items.erase( eraser, items.end() );

	if (Field::GetCurrentGameStatus() == GameStatusType::Gaming)
	{
        for( auto& item : items )
            item->Update();
	}
	else
	{
        // Запуск анимации только для главного героя
        for( auto& item : items )
        {
            if( item->GetParent().GetName() == ElementNameType::Main )
                item->Update();
        }
	}
}