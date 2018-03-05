#pragma once

#include "cocos2d.h"
#include "cocostudio/WidgetReader/NodeReader/NodeReader.h"

USING_NS_CC;

// Динамическая конвертация узлов в элементы при их создании
class ElementReader : public cocostudio::NodeReader
{
public:
	// Регистрация класса
	static void Registration();
	// Получение ссылки на единственный экземпляр
	static ElementReader * getInstance();
	// Создание нового элемента
	static Node * CreateNewElement(char * nodeName);

	static void purge();

	Node * createNodeWithFlatBuffers(const flatbuffers::Table* nodeOptions);
};