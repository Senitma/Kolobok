#pragma once

// Список всех возможных опций
#include "CreateOption\OptionForCreate.h"
#include "CreateOption\OptionForIntervalCreate.h"
#include "CreateOption\OptionForMouseCreateDestroy.h"

#include "MoveOption\MoveType.h"
#include "MoveOption\OptionForMouseMove.h"
#include "MoveOption\OptionForMove.h"
#include "MoveOption\OptionForOneStep.h"
#include "MoveOption\OptionForPatrol.h"

// Класс управления данными элемента
class Element;
// Модуль управления опциями
namespace Options
{
	// Тип опции
	template<class T>
	// Создание опции
	T & Create(Element & parent)
	{
		static_assert(std::is_base_of<ISOption, T>::value, "Not ISOption");

		std::shared_ptr<T> option = std::make_shared<T>(parent);

		RegisterMouse<T>(option);
		RegisterInterval<T>(option);

		return *option.get();
	}

	// Тип опции
	template<class T>
	// Регистрация опции с мышкой
	typename std::enable_if<std::is_base_of<ISMouse, T>::value, void>::type RegisterMouse(std::shared_ptr<T> option)
	{
		static_assert(std::is_base_of<ISOption, T>::value, "Not ISOption");

		ISMouse::Register(option);
	}
	// Тип опции
	template<class T>
	// Регистрация опции с мышкой
	typename std::enable_if<std::is_base_of<ISInterval, T>::value, void>::type RegisterMouse(std::shared_ptr<T> option){}

	// Тип опции
	template<class T>
	// Регистрация опции с обновлением
	typename std::enable_if<std::is_base_of<ISInterval, T>::value, void>::type RegisterInterval(std::shared_ptr<T> option)
	{
		static_assert(std::is_base_of<ISOption, T>::value, "Not ISOption");

		ISInterval::Register(option);
	}
	// Тип опции
	template<class T>
	// Регистрация опции с обновлением
	typename std::enable_if<std::is_base_of<ISMouse, T>::value, void>::type RegisterInterval(std::shared_ptr<T> option) {}
}