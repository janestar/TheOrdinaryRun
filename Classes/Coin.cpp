/**
 *  @Date  2015/04/04 10:56
 *  @File  Coin.cpp 
 *  
 *  @Author LiangJian Liu
 *  @Contact janestar92@163.com
 *  
 *  @brief
 *	
 */
#include "Coin.h"

USING_NS_CC;

bool Coin::init()
{
	if(!Node::init())
	{
		return false;
	}

	auto frameCache = SpriteFrameCache::getInstance();
	frameCache->addSpriteFramesWithFile("parkour.plist","parkour.png");

	auto sprite = Sprite::createWithSpriteFrameName("coin0.png");

	setSprite(sprite);
	getSprite()->runAction(createAnimate(frameCache));
	initBody();

	return true;
}

Animate* Coin::createAnimate(SpriteFrameCache* frameCache)
{
	SpriteFrame* frame = NULL;
	Vector<SpriteFrame*>frameArray;
	for(int i = 0; i <= 7; i++) 
	{
		frame = frameCache->spriteFrameByName(
			String::createWithFormat("coin%d.png", i)->getCString());
		frameArray.pushBack(frame);
	} 

	auto animation = Animation::createWithSpriteFrames(frameArray);

	animation->setLoops(-1);

	animation->setDelayPerUnit(0.1f);

	auto action = Animate::create(animation);

	return action;
}

void Coin::initBody()
{	
	auto phyBody = PhysicsBody::createCircle(
		getSprite()->getContentSize().width / 2);
	phyBody->setDynamic(false);
	phyBody->setCategoryBitmask(1);
	phyBody->setCollisionBitmask(1);
	phyBody->setContactTestBitmask(1);

	this->setPhysicsBody(phyBody);
}
