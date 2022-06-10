#ifndef _START_SCENE_H__
#define __START_SCENE_H__

#include "cocos2d.h"

using namespace cocos2d;
using namespace cocos2d::ui;

class CStartScene : public cocos2d::Layer
{
public:
	// there's no 'id' in cpp, so we recommend returning the class instance pointer
	static cocos2d::Scene* createScene();

	// Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
	virtual bool init();

	// implement the "static create()" method manually
	void onClick_start(Ref *pSender);
	CREATE_FUNC(CStartScene);
};

#endif // __STSRT_SCENE_H__
