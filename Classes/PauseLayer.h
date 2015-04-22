#ifndef __THEORDINARYRUN_PAUSELAYER_H__
#define __THEORDINARYRUN_PAUSELAYER_H__

#include "cocos2d.h"

class PauseLayer : public cocos2d::LayerColor
{
public:
	bool init();
	CREATE_FUNC(PauseLayer);

	void buildUI();
	void addEventListeners();
	
	void home(cocos2d::Ref *ref);
	void back(cocos2d::Ref *ref);

private:
	cocos2d::EventListenerTouchOneByOne *_listener;
};

#endif