#pragma once

#include "queue"
#include "OptionForOneStep.h"
#include "Field\Axes.h"

// Перечисление возможных типов перемещения
enum class MoveType;

// Опция для движения элемента
class OptionForMove : public OptionForOneStep
{
public:
	// Инициализация переменных
	OptionForMove(const Element & parent) : OptionForOneStep(parent) {}

	// Получить переключатель вида движения
	MoveType GetMoveType() { return moveType; };
	// Задать переключатель типа движения
	void SetMoveType(MoveType value) { moveType = value; };

	// Передвинуть элемент
	virtual void MoveTo(const int & x, const int & y) override { MoveTo(moveType, x, y); };
protected:
	// Элемент остановился
	virtual void Standed() override;
private:
	// Очередь из точек для движения
	std::queue<Axes> points;
	// Тип перемещения
	MoveType moveType;
	// Новое положение по оси X
	int nextX;
	// Новое положение по оси Y
	int nextY;

	// Создание пути
	std::queue<Axes> OptionForMove::GeneratePath(const MoveType & type, const int & x, const int & y);
	// Создание пути по прямой
	std::queue<Axes> OptionForMove::GenerateLinePath(const int & x, const int & y);
	// Создание пути в обход препятствий
	std::queue<Axes> OptionForMove::GenerateByPassPath(const int & x, const int & y);

	// Передвинуть элемент
	void MoveTo(const MoveType & type, const int & x, const int & y);
};