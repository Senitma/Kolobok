#pragma once

#include "Option\ISInterval.h"

// Опция для перемещения на одну клетку
class OptionForOneStep : public ISInterval
{
public:
	// Инициализация переменных
	OptionForOneStep(const Element & parent) : ISInterval(parent) {}

	// Получить скорость перемещения
	int GetMoveSpeed() const { return moveSpeed; };
	// Задать скорость пермещения
	void SetMoveSpeed(const int & value) { moveSpeed = value; };
	// Получить скорость вращения
	int GetRotateSpeed() const { return rotateSpeed; };
	// Задать возможность вращения
	void SetRotateSpeed(const int & value) { rotateSpeed = value; };

	// Обновление данных
	virtual void Update() override;
	// Передвинуть элемент
	virtual void MoveTo(const int & x, const int & y);
protected:
	// Краткое перечисление возможных состояний
	enum StatusType
	{
		// Стоит на месте
		Stand = 0,
		// Перемещается
		Move = 30,
		// Поворачивается
		Rotate = 510
	};

	// Получить текущий статус
	StatusType GetCurrentStatus() const;
private:
	// Полное перечисление возможных состояний
	enum FullStatusType
	{
		// Перемещается
		MoveLeft = 2,
		// Перемещается
		MoveUp = 4,
		// Перемещается
		MoveRight = 8,
		// Перемещается
		MoveDown = 16,
		// Поворачивается 
		RotateUpToLeft = 36,
		// Поворачивается
		RotateDownToLeft = 48,
		// Поворачивается 
		RotateLeftToUp = 66,
		// Поворачивается
		RotateRightToUp = 72,
		// Поворачивается
		RotateUpToRight = 132,
		// Поворачивается
		RotateDownToRight = 144,
		// Поворачивается
		RotateLeftToDown = 258,
		// Поворачивается
		RotateRightToDown = 264,
	};

	// Скорость перемещения
	int moveSpeed;
	// Скорость поворота
	int rotateSpeed;

	// Текущее состояние опции
	FullStatusType currentStatus;
	// Новое положение по оси X
	int nextX;
	// Новое положение по оси Y
	int nextY;

	// Текущий интервал
	int currentInterval;
	// максимальный интервал
	int maxInterval;
};