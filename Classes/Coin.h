/**
 *  @Date  2015/04/04 10:56
 *  @File  Coin.h 
 *  
 *  @Author LiangJian Liu
 *  @Contact janestar92@163.com
 *  
 *  @brief
 *	
 */
#ifndef __Coin__H__
#define __Coin__H__

#include "Base.h"

class Coin : public Base
{
public:
	virtual bool init();
    void initBody();
	CREATE_FUNC(Coin);
	cocos2d::Animate* createAnimate(cocos2d::SpriteFrameCache* frameCache);
};

#endif