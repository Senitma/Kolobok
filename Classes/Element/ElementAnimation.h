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
	// Список кадров для анимации
	Vector<SpriteFrame *> upleftFrames;
	// Список кадров для анимации
	Vector<SpriteFrame *> uprightFrames;
	// Список кадров для анимации
	Vector<SpriteFrame *> rightupFrames;
	// Список кадров для анимации
	Vector<SpriteFrame *> rightdownFrames;
	// Список кадров для анимации
	Vector<SpriteFrame *> downrightFrames;
	// Список кадров для анимации
	Vector<SpriteFrame *> downleftFrames;
	// Список кадров для анимации
	Vector<SpriteFrame *> leftdownFrames;
};