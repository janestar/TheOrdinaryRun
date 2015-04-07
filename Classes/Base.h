/**
 *  @Date  2015/04/04 10:56
 *  @File  Base.h 
 *  
 *  @Author LiangJian Liu
 *  @Contact janestar92@163.com
 *  
 *  @brief
 *	
 */
#ifndef __Base__H__
#define __Base__H__

#include "cocos2d.h"
USING_NS_CC;

//all of the barriers like the coins,rock,etc are derived from this class
class Base : public cocos2d::Node
{
public:
	Base();
	~Base();
	void setSprite(cocos2d::Sprite *sprite);
	cocos2d::Sprite *getSprite();
    virtual void initBody() = 0;
	cocos2d::Size getConSize();
	
private:
	cocos2d::Sprite *m_sprite;
	
};

#endif