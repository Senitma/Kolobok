#pragma once

#include "Option\BaseClass\ISOption.h"
#include "Option\BaseClass\ISInterval.h"

// Опция для перемещения на одну клетку
class OptionForOneStep : public ISOption, ISInterval
{
public:
	// Получить скорость перемещения
	int GetMoveSpeed() { return moveSpeed; };
	// Задать скорость пермещения
	void SetMoveSpeed(int value) { moveSpeed = value; };
	// Получить возможность вращения
	bool GetRotate() { return isRotate; };
	// Задать возможность вращения
	void SetRotate(bool value) { isRotate = value; };
	// Получить скорость вращения
	int GetRotateSpeed() { return rotateSpeed; };
	// Задать возможность вращения
	void SetRotateSpeed(int value) { rotateSpeed = value; };

	// Обновление данных
	virtual void Update() override;
	// Передвинуть элемент
	virtual bool MoveTo(int x, int y);

	// Задать родителя опции
	virtual void SetParent(AdvancedElement * value) override { parent = value; parent->AddOption(this); };
protected:
	// Скорость перемещения
	int moveSpeed;
	// Переключатель возможности поворота
	bool isRotate;
	// Скорость поворота
	int rotateSpeed;

	// Новые координаты по оси X
	int x;
	// Новые координаты по оси Y
	int y;
	// Переключатель состояния
	bool isFreeze;
private:
	// Старые координаты по оси X
	int oldX;
	// Старые координаты по оси Y
	int oldY;

	// Текущий оступ слева
	int currentLeft;
	// Текущий отступ сверху
	int currentTop;
	// Новый отступ слева
	int left;
	// Новый отступ сверху
	int top;
	// Размер одного шага
	int moveStepSize;
	// Блокировка других действий при перемещении
	bool isMoveLock;

	// Новая сторона
	SideType side;
	// Текущее значение поворота
	int currentRotate;
	// Новое значение поворота
	int rotate;
	// Размер одного шага
	int rotateStepSize;
	// Блокировка других действий при повороте
	bool isRotateLock;

	// Заполнить все данные координат
	void FillVariableForNewPoint(int x, int y);
};