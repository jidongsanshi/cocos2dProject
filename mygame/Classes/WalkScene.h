#ifndef _WALK_SCENE_H__
#define __WALK_SCENE_H__

#include "cocos2d.h"
using namespace std;
using namespace cocos2d;
using namespace cocos2d::ui;

class CWalkScene : public cocos2d::Layer
{
public:
	// there's no 'id' in cpp, so we recommend returning the class instance pointer
	static cocos2d::Scene* createScene();

	// Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
	virtual bool init();

	// implement the "static create()" method manually
	//void onClick_package(Ref *pSender);
	CREATE_FUNC(CWalkScene);
	static bool createAnimation0(string name, string tag);
	static bool createAnimation1(string name, string tag);
	/*void PressAni(float delta) ;//每0.2秒执行一次，监控键盘来播放人物动画
	void KeyPressMove(EventKeyboard::KeyCode keyCode);//判断位移方向
	void KeyPressAni(EventKeyboard::KeyCode keyCode);//判断动画方向
	void PressMove(float delta);//每帧执行，每帧监控键盘来位移*/
	void RoleMove(EventKeyboard::KeyCode keyCode);
	void update(float delta) override;
	void repeat(float delta);
private:
	Sprite *p_protagonist;
	std::map<cocos2d::EventKeyboard::KeyCode, bool> keys;
	std::map<string, bool> whichAni;
};

#endif // __WALK_SCENE_H__
