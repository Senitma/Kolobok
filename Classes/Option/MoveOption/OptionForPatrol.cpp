#include "Field\Field.h"
#include "OptionForPatrol.h"

OptionForPatrol::OptionForPatrol(const Element & parent) : OptionForMove(parent) , patrolPoints(this->parent.GetPoints())
{
	patrolType = PatrolType::None;
}

void OptionForPatrol::MoveFinished()
{
	// Для повторной проверки маршрута координаты дублируются
	switch (patrolType)
	{
		case PatrolType::DestroyWay:
			if (patrolPoints.size() > 0)
			{
				OptionForMove::MoveTo(patrolPoints.front().GetX(), patrolPoints.front().GetY());
				patrolPoints.pop();
				patrolPoints.pop();
			}
			else
			{
				Field::RemoveElement(parent);
			}
			break;
		//case PatrolType::RoundTrip:
		//	break;
		case PatrolType::Circle:
			// Значение по умолчанию
		default:
			if (patrolPoints.size() > 0)
			{
				int nextX = patrolPoints.front().GetX();
				int nextY = patrolPoints.front().GetY();
				OptionForMove::MoveTo(nextX, nextY);
				patrolPoints.pop();
				patrolPoints.push(Axes(nextX, nextY));
			}
			break;
	}
}