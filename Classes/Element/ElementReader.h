#pragma once

#include "cocos2d.h"
#include "cocostudio/WidgetReader/NodeReader/NodeReader.h"

USING_NS_CC;

// ������������ ����������� ����� � �������� ��� �� ��������
class ElementReader : public cocostudio::NodeReader
{
public:
	// ����������� ������
	static void Registration();
	// ��������� ������ �� ������������ ���������
	static ElementReader * getInstance();
	// �������� ������ ��������
	static Node * CreateNewElement(char * nodeName);

	static void purge();

	Node * createNodeWithFlatBuffers(const flatbuffers::Table* nodeOptions);
};