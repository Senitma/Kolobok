#pragma once

#include "cocos2d.h"

using namespace cocos2d;

// Перечисление возможных направлений
enum SideType;
// Перечисление возможных анимаций
enum class AnimationType;

// Анимация элемента
class ElementAnimation
{
public:
	// Инициализация перменных
	ElementAnimation() {}

	// Загрузка анимации
	void LoadAnimation(Node * node, const float & interval, const int & frameCount, const int & width, const int & height, const SideType & startSide);
	// Проигрывание анимации
	void RunAnimation(AnimationType type);
private:
	// Главный спрайт для анимации
	Sprite * mainSprite;

	// Список кадров для анимации
	Vector<SpriteFrame *> leftupFrames;
	// Шаблон анимации
	Animation * leftupAnimation;
	// Анимация
	Animate * leftupAnimate;
	// Список кадров для анимации
	Vector<SpriteFrame *> upleftFrames;
	// Шаблон анимации
	Animation * upleftAnimation;
	// Анимация
	Animate * upleftAnimate;

	// Список кадров для анимации
	Vector<SpriteFrame *> uprightFrames;
	// Шаблон анимации
	Animation * uprightAnimation;
	// Анимация
	Animate * uprightAnimate;
	// Список кадров для анимации
	Vector<SpriteFrame *> rightupFrames;
	// Шаблон анимации
	Animation * rightupAnimation;
	// Анимация
	Animate * rightupAnimate;

	// Список кадров для анимации
	Vector<SpriteFrame *> rightdownFrames;
	// Шаблон анимации
	Animation * rightdownAnimation;
	// Анимация
	Animate * rightdownAnimate;
	// Список кадров для анимации
	Vector<SpriteFrame *> downrightFrames;
	// Шаблон анимации
	Animation * downrightAnimation;
	// Анимация
	Animate * downrightAnimate;

	// Список кадров для анимации
	Vector<SpriteFrame *> downleftFrames;
	// Шаблон анимации
	Animation * downleftAnimation;
	// Анимация
	Animate * downleftAnimate;
	// Список кадров для анимации
	Vector<SpriteFrame *> leftdownFrames;
	// Шаблон анимации
	Animation * leftdownAnimation;
	// Анимация
	Animate * leftdownAnimate;
};