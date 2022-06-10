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
	/*void PressAni(float delta) ;//ÿ0.2��ִ��һ�Σ���ؼ������������ﶯ��
	void KeyPressMove(EventKeyboard::KeyCode keyCode);//�ж�λ�Ʒ���
	void KeyPressAni(EventKeyboard::KeyCode keyCode);//�ж϶�������
	void PressMove(float delta);//ÿִ֡�У�ÿ֡��ؼ�����λ��*/
	void RoleMove(EventKeyboard::KeyCode keyCode);
	void update(float delta) override;
	void repeat(float delta);
private:
	Sprite *p_protagonist;
	std::map<cocos2d::EventKeyboard::KeyCode, bool> keys;
	std::map<string, bool> whichAni;
};

#endif // __WALK_SCENE_H__
