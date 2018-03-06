#pragma once

#include "BaseAxes.h"

// Класс координат на поле
class FieldAxes : public BaseAxes
{
public:
	// Инициализация переменных
	FieldAxes() : FieldAxes(0, 0) {};
	// Инициализация переменных
	FieldAxes(const int &x, const int &y) : BaseAxes(x, y) {};

	// Получить оригинальное положение по оси X
	int GetOriginalX() const { return originalX; };
	// Получить оригинальное положение по оси Y
	int GetOriginalY() const { return originalY; };
	// Получить переключатель выхода за границы поля 
	bool GetOutsideStatus() const { return CheckOutside(); };

	// Изменить положение по оси X
	void SetX(const int &value) override;
	// Изменить положение по оси Y
	void SetY(const int &value) override;

	// Конвертировать положение по оси X в смещение слева
	int ToLeft() const;
	// Конвертировать положение по оси Y в смещение сверху
	int ToTop() const;
	// Конвертировать координаты в вектор
	cocos2d::Vec2 ToVec2() const;
private:
	// Неизмененное положение по оси X
	int originalX;
	// Неизмененное положение по оси Y
	int originalY;

	// Проверить выход за край поля
	bool CheckOutside() const;
};