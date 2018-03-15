#pragma once

#include "Option\ISInterval.h"

// Опция для перемещения на одну клетку
class OptionForOneStep : public ISInterval
{
public:
	// Инициализация переменных
	OptionForOneStep(const Element & parent);

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
	// Элемент остановился
	virtual void Standed() {};
	// Проверить координаты на соответствие соседним
	bool CheckAxesForNear(const int & x, const int & y) const;
private:
	// Полное перечисление возможных состояний
	enum StatusType
	{
		// Стоит на месте
		Stand = 0,
		// Состояние после поворота
		AfterRotate,
		// Перемещается
		MoveLeft = 2,
		// Перемещается
		MoveUp = 4,
		// Перемещается
		MoveRight = 8,
		// Перемещается
		MoveDown = 16,
		// Перемещается
		Move = 30,
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
		// Поворачивается
		Rotate = 510
	};

	// Скорость перемещения
	int moveSpeed;
	// Скорость поворота
	int rotateSpeed;

	// Текущее состояние опции
	StatusType currentStatus;
	// Новое положение по оси X
	int nextX;
	// Новое положение по оси Y
	int nextY;

	// Текущий интервал
	int currentInterval;
	// максимальный интервал
	int maxInterval;
};