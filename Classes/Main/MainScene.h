#pragma once

#include "cocos2d.h"

class MainScene : public cocos2d::Layer
{
public:
	// Инициализация переменных
	CREATE_FUNC(MainScene);

	static cocos2d::Scene* createScene();

	virtual bool init();
private:
	// Событие ввода данных
	void onEnter() override;
	// Событие обновления изображения
	void update(float delta) override;
};