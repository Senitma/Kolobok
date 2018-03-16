#pragma once

#include "queue"
#include "memory"

namespace cocos2d
{
	// Узел для прорисовки
	class Node;
}
// Данные элемента
struct ElementData;
// Перечисление возможных имен
enum class ElementNameType;
// Перечисление возможных типов
enum ClassType;
// Перечисление возможных направлений
enum SideType;
// Координаты элемента
struct Axes;

// Класс управления данными элемента
class Element
{
public:
	// Инициализация переменных
	Element(cocos2d::Node * node, ElementNameType name, ClassType type);
	// Копирование элемента
	Element(const Element & value);
	// Удаление данных
	~Element();
	// Выключить автоматическое удаление прорисовок
	static void OffAutoDrawDelete();

	// Получить персональный идентификатор
	int GetID() const;
	// Получить имя
	ElementNameType GetName() const;
	// Получить тип
	ClassType GetType() const;
	// Получить сторону поворота
	SideType GetSide() const;
	// Изменить направление
	void SetSide(const SideType & value);

	// Получить координату по оси X
	int GetX() const;
	// Получить координату по оси Y
	int GetY() const;
	// Получить координаты
	Axes GetAxes() const;

	// Получить смещение слева
	int GetLeft() const;
	// Получить смещение сверху
	int GetTop() const;
	// Изменить смещение
	void SetPosition(const int & x, const int & y);
	// Получить угол вращения
	int GetRotation() const;
	// Измениь угол вращения
	void SetRotation(const int & value);
	// Получить статус элемента
	bool GetDestroyStatus() const;
	// Изменить статус элемента
	void SetDestroyStatus(const bool & value);

	// Добавить точку для патрулирования
	void AddPoint(const int & x, const int & y);
	// Получить точку для патрулирования
	std::queue<Axes> & GetPoints();

	// Копирование элемента
	Element operator= (const Element & value) const;
	// Сравнение двух координат
	bool operator== (const Element & value) const;
	// Сравнение двух координат
	bool operator!= (const Element & value) const;
protected:
	// Изменить положение по оси X
	void SetX(const int & value);
	// Изменить положение по оси Y
	void SetY(const int & value);
	// Изменить порядок отображения прорисовки
	void SetOrder(const int & value);
private:
	// Данные элемента
	std::shared_ptr<ElementData> data;

	// Удаление конструктора по умолчанию
	Element() = delete;
};