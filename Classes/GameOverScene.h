// GameOverScene.h

#ifndef _THEORDINARYRUN_GAMEOVERSCENE_H
#define _THEORDINARYRUN_GAMEOVERSCENE_H

#include <cocos2d.h>

class GameOver : public cocos2d::LayerColor
{
public:
	virtual bool init();
	CREATE_FUNC(GameOver);

	static cocos2d::Scene* createScene();

private:
	cocos2d::Size _visibleSize;
};

#endif
