#include "cocostudio/CocoStudio.h"
#include "ElementReader.h"

USING_NS_CC;

static ElementReader * instancePieceReader = nullptr;
static bool isInit = false;

void ElementReader::Registration()
{
	CSLoader* instance = CSLoader::getInstance();
	instance->registReaderObject("ElementReader", (ObjectFactory::Instance) ElementReader::getInstance);

	isInit = true;
}
ElementReader * ElementReader::getInstance()
{
	if (!instancePieceReader)
	{
		instancePieceReader = new ElementReader();
	}
	return instancePieceReader;
}
Node * ElementReader::CreateNewElement(char * nodeName)
{
	if (isInit == false)
	{
		ElementReader::Registration();
	}
	return dynamic_cast<Node *>(CSLoader::createNode(nodeName));
}

void ElementReader::purge()
{
	CC_SAFE_DELETE(instancePieceReader);
}
Node* ElementReader::createNodeWithFlatBuffers(const flatbuffers::Table *nodeOptions)
{
	Node * node = Node::create();
	setPropsWithFlatBuffers(node, nodeOptions);

	return node;
}