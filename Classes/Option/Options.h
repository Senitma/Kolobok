#pragma once

// ������ ���� ��������� �����
#include "CreateOption\OptionForCreate.h"
#include "CreateOption\OptionForIntervalCreate.h"
#include "CreateOption\OptionForMouseCreateDestroy.h"

#include "MoveOption\MoveType.h"
#include "MoveOption\OptionForMouseMove.h"
#include "MoveOption\OptionForMove.h"
#include "MoveOption\OptionForOneStep.h"
#include "MoveOption\OptionForPatrol.h"

// ����� ���������� ������� ��������
class Element;
// ������ ���������� �������
namespace Options
{
	// ��� �����
	template<class T>
	// �������� �����
	T & Create(Element & parent)
	{
		static_assert(std::is_base_of<ISOption, T>::value, "Not ISOption");

		std::shared_ptr<T> option = std::make_shared<T>(parent);

		RegisterMouse<T>(option);
		RegisterInterval<T>(option);

		return *option.get();
	}

	// ��� �����
	template<class T>
	// ����������� ����� � ������
	typename std::enable_if<std::is_base_of<ISMouse, T>::value, void>::type RegisterMouse(std::shared_ptr<T> option)
	{
		static_assert(std::is_base_of<ISOption, T>::value, "Not ISOption");

		ISMouse::Register(option);
	}
	// ��� �����
	template<class T>
	// ����������� ����� � ������
	typename std::enable_if<std::is_base_of<ISInterval, T>::value, void>::type RegisterMouse(std::shared_ptr<T> option){}

	// ��� �����
	template<class T>
	// ����������� ����� � �����������
	typename std::enable_if<std::is_base_of<ISInterval, T>::value, void>::type RegisterInterval(std::shared_ptr<T> option)
	{
		static_assert(std::is_base_of<ISOption, T>::value, "Not ISOption");

		ISInterval::Register(option);
	}
	// ��� �����
	template<class T>
	// ����������� ����� � �����������
	typename std::enable_if<std::is_base_of<ISMouse, T>::value, void>::type RegisterInterval(std::shared_ptr<T> option) {}
}