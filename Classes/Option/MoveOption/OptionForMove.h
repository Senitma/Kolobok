//#pragma once
//
//#include "OptionForOneStep.h"
//
//// Перечисление возможных типов перемещения
//enum class MoveType;
//
//// Опция для движения элемента
//class OptionForMove : public OptionForOneStep
//{
//public:
//	// Получить переключатель вида движения
//	MoveType GetMoveType() { return moveType; };
//	// Задать переключатель типа движения
//	void SetMoveType(MoveType value) { moveType = value; };
//
//	// Обновление данных
//	virtual void Update() override;
//	// Передвинуть элемент
//	virtual bool MoveTo(int x, int y) override;
//protected:
//	// Тип перемещения
//	MoveType moveType;
//private:
//	// Список точек для движения
//	cocos2d::Vector<FieldPoint *> points;
//	// Создание пути
//	cocos2d::Vector <FieldPoint *> GeneratePath(MoveType type, int x, int y);
//	// Создание пути по прямой
//	cocos2d::Vector <FieldPoint *> GenerateLinePath(int x, int y);
//	// Создание пути в обход препятствий
//	cocos2d::Vector <FieldPoint *> GenerateByPassPath(int x, int y);
//
//	// Передвинуть элемент
//	bool MoveTo(MoveType type, int x, int y);
//};