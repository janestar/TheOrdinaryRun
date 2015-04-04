/**
 *  @Date  2015/04/04 10:56
 *  @File  Rock.cpp 
 *  
 *  @Author LiangJian Liu
 *  @Contact janestar92@163.com
 *  
 *  @brief
 *	
 */
#include "Rock.h"

USING_NS_CC;

bool Rock::init(){
	if(!Node::init()){
		return false;
	}

	auto frameCache = SpriteFrameCache::getInstance();
	frameCache->addSpriteFramesWithFile("parkour.plist","parkour.png");

	auto sprite = Sprite::createWithSpriteFrameName("rock.png");

	setSprite(sprite);

	initBody();

	return true;
}

void Rock::initBody(){
	auto phyBody = PhysicsBody::createEdgeBox(getSprite()->getContentSize());
	phyBody->setCategoryBitmask(1);
	phyBody->setCollisionBitmask(1);
	phyBody->setContactTestBitmask(1);
	this->setPhysicsBody(phyBody);
}
