#pragma once

#include "OptionForMove.h"

// Перечисление возможных типов патрулей
enum class PatrolType
{
	// Не задан
	None = 0,
	// По кругу
	Circle,
	// По маршруту
	RoundTrip,
	// Уничтожение в конце маршрута
	DestroyWay
};

// Интерфейс опции для патрулирования
class OptionForPatrol : public OptionForMove
{
public:
	// Инициализация переменных
	OptionForPatrol(const Element & parent);

	// Получить тип патруля
	PatrolType GetPatrolType() const { return patrolType; };
	// Задать тип патруля
	void SetPatrolType(const PatrolType & value) { patrolType = value; };

	// Элемент остановился
	virtual void MoveFinished() override;
private:
	// Тип патруля
	PatrolType patrolType;
	// Ссылка на список точек для патруля в элементе
	std::queue<Axes> & patrolPoints;
};