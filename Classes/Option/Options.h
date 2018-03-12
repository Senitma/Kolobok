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
	// �������� �����
	template<class T>
	T & Create(Element & parent)
	{
		static_assert(std::is_base_of<ISOption, T>::value, "Not ISOption");

		std::shared_ptr<T> option = std::make_shared<T>(parent);

		if (std::is_base_of<ISMouse, T>::value == true)
		{
			ISMouse::Register(option);
		}

		return *option.get();
	}
}