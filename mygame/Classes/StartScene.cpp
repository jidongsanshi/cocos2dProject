#include "StartScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "WalkScene.h"

USING_NS_CC;

using namespace cocostudio::timeline;

Scene* CStartScene::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	CStartScene *layer = CStartScene::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool CStartScene::init()
{
	if (!Layer::init())
	{
		return false;
	}
	auto rootNode = CSLoader::createNode("StartScene.csb");

	addChild(rootNode);


	Button *btn_start = static_cast<Button *>(rootNode->getChildByName("start"));
	btn_start->addClickEventListener(CC_CALLBACK_1(CStartScene::onClick_start, this));
	return true;
}

void CStartScene::onClick_start(Ref *pSender) {

	Director::getInstance()->setDepthTest(true);
	Scene *scene = Scene::create();
	CWalkScene *layer = CWalkScene::create();
	scene->addChild(layer);
	auto ss = TransitionFade::create(0.5f, scene);
	Director::getInstance()->replaceScene(ss);
}
