#include "WalkScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

USING_NS_CC;

using namespace cocostudio::timeline;

Scene* CWalkScene::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = CWalkScene::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool CWalkScene::init()
{

	if (!Layer::init())
	{
		return false;
	}

	auto rootNode = CSLoader::createNode("WalkScene.csb");
	addChild(rootNode);
	//加载plist文件
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("protagonist.plist", "protagonist.png");

	//加载动画函数
	CWalkScene::createAnimation0("protagonist_down","down0");
	CWalkScene::createAnimation0("protagonist_up", "up0");
	CWalkScene::createAnimation0("protagonist_left" ,"left0");
	CWalkScene::createAnimation0("protagonist_right","right0");
	CWalkScene::createAnimation1("protagonist_down", "down1");
	CWalkScene::createAnimation1("protagonist_up", "up1");
	CWalkScene::createAnimation1("protagonist_left", "left1");
	CWalkScene::createAnimation1("protagonist_right", "right1");

	//初始化精灵
	p_protagonist = Sprite::createWithSpriteFrameName("protagonist_up1.png");
	p_protagonist->setPosition(Vec2(200, 200));
	this->addChild(p_protagonist);

	//按钮
	//Button *btn_package = static_cast<Button *>(rootNode->getChildByName("package"));
	//btn_package->addClickEventListener(CC_CALLBACK_1(CWalkScene::onClick_package, this));
	
	//键盘监听
	auto listener = EventListenerKeyboard::create();
	listener->onKeyPressed = [=](EventKeyboard::KeyCode keyCode, Event *event) {
		log("key pressed");
		keys[keyCode] = true;
	};
	listener->onKeyReleased = [=](EventKeyboard::KeyCode keyCode, Event *event) {
		log("key released");
		keys[keyCode] = false;
	};
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
	this->scheduleUpdate();
	//this->schedule(schedule_selector(CWalkScene::PressAni), 0.32f);
	//this->schedule(schedule_selector(CWalkScene::PressMove));
	return true;
}
bool CWalkScene::createAnimation0(string name, string tag ) {
	//加载精灵帧
	SpriteFrame* frame = NULL;
	Vector<SpriteFrame*> animFrames;
	for (int i = 0; i <= 1; i++) {
		string str = StringUtils::format("%s%d.png", name.c_str(), i);
		auto frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(str);
		animFrames.pushBack(frame);
	}
	//创建动画
	Animation *amt = Animation::createWithSpriteFrames(animFrames, 0.1f);
	//把动画加入缓存
	AnimationCache::getInstance()->addAnimation(amt, tag);
	return true;
}
bool CWalkScene::createAnimation1(string name, string tag) {
	//加载精灵帧
	SpriteFrame* frame = NULL;
	Vector<SpriteFrame*> animFrames;
	for (int i = 2; i <= 3; i++) {
		string str = StringUtils::format("%s%d.png", name.c_str(), i);
		auto frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(str);
		animFrames.pushBack(frame);
	}
	//创建动画
	Animation *amt = Animation::createWithSpriteFrames(animFrames,0.1f);
	//把动画加入缓存
	AnimationCache::getInstance()->addAnimation(amt, tag);
	return true;
}
/*void CWalkScene::PressMove(float delta) {
	auto up = EventKeyboard::KeyCode::KEY_W;
	auto down = EventKeyboard::KeyCode::KEY_S;
	auto left = EventKeyboard::KeyCode::KEY_A;
	auto right = EventKeyboard::KeyCode::KEY_D;
	if (keys[up]) {
		KeyPressMove(up);
	}
	if (keys[down]) {
		KeyPressMove(down);
	}
	if (keys[left]) {
		KeyPressMove(left);
	}
	if (keys[right]) {
		KeyPressMove(right);
	}
}



void CWalkScene::PressAni(float delta) {
	auto up = EventKeyboard::KeyCode::KEY_W;
	auto down = EventKeyboard::KeyCode::KEY_S;
	auto left = EventKeyboard::KeyCode::KEY_A;
	auto right = EventKeyboard::KeyCode::KEY_D;
	if (keys[up]) {
		KeyPressAni(up);
	}
	if (keys[down]) {
		KeyPressAni(down);
	}
	if (keys[left]) {
		KeyPressAni(left);
	}
	if (keys[right]) {
		KeyPressAni(right);
	}
}
	
void CWalkScene::KeyPressMove(EventKeyboard::KeyCode keyCode) {
	int X = 0;int Y = 0;
	switch (keyCode)
	{
	case(EventKeyboard::KeyCode::KEY_W):
		Y = 4;
		break;
	case(EventKeyboard::KeyCode::KEY_S):
		Y = -4;
		break;
	case(EventKeyboard::KeyCode::KEY_A):
		X = -4;
		break;
	case(EventKeyboard::KeyCode::KEY_D):
		X = 4;
		break;
	default:
	break;
	}
	MoveBy *mb = MoveBy::create(0.2f, Vec2(X, Y));
	p_protagonist->runAction(mb);
}
void CWalkScene::KeyPressAni(EventKeyboard::KeyCode keyCode) {
	string tag;
	switch (keyCode)
	{
	case(EventKeyboard::KeyCode::KEY_W):
		tag = "up";
		break;
	case(EventKeyboard::KeyCode::KEY_S):
		tag = "down";
		break;
	case(EventKeyboard::KeyCode::KEY_A):
		tag = "left";
		break;
	case(EventKeyboard::KeyCode::KEY_D):
		tag = "right";
		break;
	default:
		break;
	}
	Animate *ate = Animate::create(AnimationCache::getInstance()->getAnimation(tag));
	p_protagonist->runAction(ate);
}*/

void CWalkScene::update(float delta) {
	auto up = EventKeyboard::KeyCode::KEY_W;
	auto down = EventKeyboard::KeyCode::KEY_S;
	auto left = EventKeyboard::KeyCode::KEY_A;
	auto right = EventKeyboard::KeyCode::KEY_D;
	if (keys[up]) {
		RoleMove(up);
		this->unscheduleUpdate();
		this->scheduleOnce(schedule_selector(CWalkScene::repeat), 0.2f);
	}
	if (keys[down]) {
		RoleMove(down);
		this->unscheduleUpdate();
		this->scheduleOnce(schedule_selector(CWalkScene::repeat), 0.2f);
	}
	if (keys[left]) {
		RoleMove(left);
		this->unscheduleUpdate();
		this->scheduleOnce(schedule_selector(CWalkScene::repeat), 0.2f);
	}
	if (keys[right]) {
		RoleMove(right);
		this->unscheduleUpdate();
		this->scheduleOnce(schedule_selector(CWalkScene::repeat), 0.2f);
	}
}
void CWalkScene::repeat(float delta) {
	this->scheduleUpdate();
}
void CWalkScene::RoleMove(EventKeyboard::KeyCode keyCode) {
	int X = 0;int Y = 0;string tag;
	switch (keyCode)
	{
	case(EventKeyboard::KeyCode::KEY_W):
		Y = 32;tag = "up";
		whichAni[tag] = !whichAni[tag];
		break;
	case(EventKeyboard::KeyCode::KEY_S):
		Y = -32;tag = "down";
		whichAni[tag] = !whichAni[tag];
		break;
	case(EventKeyboard::KeyCode::KEY_A):
		X = -32;tag = "left";
		whichAni[tag] = !whichAni[tag];
		break;
	case(EventKeyboard::KeyCode::KEY_D):
		X = 32;tag = "right";
		whichAni[tag] = !whichAni[tag];
		break;
	default:
		break;
	}

	auto pos = Vec2(X+p_protagonist->getPosition().x, Y+p_protagonist->getPosition().y);
	if (1)
		X, Y = 0;

	MoveBy *mb = MoveBy::create(0.2f, Vec2(X, Y));
	if (whichAni[tag]) {
		Animate *ate = Animate::create(AnimationCache::getInstance()->getAnimation(tag + std::to_string(1)));
		Spawn *sp = Spawn::create(mb, ate, NULL);
		p_protagonist->runAction(sp);
	}
	else {
		Animate *ate = Animate::create(AnimationCache::getInstance()->getAnimation(tag + std::to_string(0)));
		Spawn *sp = Spawn::create(mb, ate, NULL);
		p_protagonist->runAction(sp);
		}	
}

