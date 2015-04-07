/**
 *  @Date  2015/04/04 10:56
 *  @File  Base.cpp 
 *  
 *  @Author LiangJian Liu
 *  @Contact janestar92@163.com
 *  
 *  @brief
 *	
 */
#include "Base.h"

USING_NS_CC;

Base::Base()
{
	m_sprite = NULL;
}

Base::~Base(){};

void Base::setSprite(Sprite* sprite)
{
	m_sprite = sprite; 
	this->addChild(m_sprite);
}

Sprite* Base::getSprite()
{
	return m_sprite;
}

Size Base::getConSize()
{
	return m_sprite->getContentSize();
}
