//#pragma once
//
//#include "OptionForMove.h"
//
//// Интерфейс опции для патрулирования
//class OptionForPatrol : public OptionForMove
//{
//public:
//	// Получить переключатель патруля
//	bool GetPatrol() { return isPatrol; };
//	// Задать переключатель патруля
//	void SetPatrol(bool value) { isPatrol = value; };
//	// Получить переключатель значения по кругу
//	bool GetCircle() { return isCircle; };
//	// Задать переключатель значения по кругу
//	void SetCircle(bool value) { isCircle = value; };
//	// Получить переключатель самоуничтожения в конце пути
//	bool GetDestroyInEnd() { return isDestroyInEnd; };
//	// Задать переключатель самоуничтожения в конце пути
//	void SetDestroyInEnd(bool value) { isDestroyInEnd = value; };
//
//	// Обновление данных
//	void Update() override;
//protected:
//	// Переключатель патрулирования
//	bool isPatrol;
//	// Патрулирование по кругу
//	bool isCircle;
//	// Самоуничтожение в конце пути
//	bool isDestroyInEnd;
//private:
//	// Индекс текущей основной точки
//	int currentIndex;
//	// Переключатель возвращения (патруль идет в обратную сторону)
//	bool isReturn;
//	// Расчитать новый индекс
//	void CalcNewIndex();
//};