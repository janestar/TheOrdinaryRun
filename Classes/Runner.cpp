/**
 * @file Runner.cpp
 * @date 2015/04/01
 *
 * @author Yilin Gui
 * Contact: yilin.gui@gmail.com
 *
 * @brief  Implementation of the Runner class
 * 
 * TODO: 
 *
 */

#include "Runner.h"
#include "FlashTool.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;
using namespace CocosDenshion;

bool Runner::init()
{
	_runnerSprite = Sprite::create();
	_runnerSprite->setContentSize(Size(44, 52));

	_twoStepJump = false;  // 二段跳标志
	_superRush = false;  // 超级冲刺标志

	addChild(_runnerSprite);
	_state = running;  // 初始状态为奔跑

	initBody();  // 初始化物理刚体

	scheduleUpdate();  // 启动定时器

	return true;
}

void Runner::initActionSet(cocos2d::SpriteFrameCache *frameCache)
{

}

void Runner::doAction(const std::string &actionName)
{
	if (actionName == "running")
	{
		auto runningAction = RepeatForever::create(FlashTool::readJsonSpriteSheet("Hero.json", 0.3f));
		_runnerSprite->runAction(runningAction);
	}
}

void Runner::initBody()
{
	auto runnerBody = PhysicsBody::createBox(Size(44, 52), PHYSICSBODY_MATERIAL_DEFAULT);  
	this->setPhysicsBody(runnerBody);  

	getPhysicsBody()->getShape(0)->setRestitution(0.0f);  // 设置抵抗力为0
	getPhysicsBody()->getShape(0)->setFriction(0.0f);  // 设置摩擦力为0
	getPhysicsBody()->setRotationEnable(false);  // 禁止刚体旋转

	// 设置碰撞检测标识
	getPhysicsBody()->setCategoryBitmask(1);
	getPhysicsBody()->setCollisionBitmask(1);
	getPhysicsBody()->setContactTestBitmask(1);
}

void Runner::update(float delta)
{
	auto velocity = getPhysicsBody()->getVelocity();
	if (_state == jumpUp && velocity.y < 0.1)
	{
		_state = jumpDown;
		//_runnerSprite->stopAllActions();
		//doAction("jumpDown");
	}
	else if (_state == jumpDown && velocity.y == 0.0)
	{
		_state = running;
		//_runnerSprite->stopAllActions();
		//doAction("running");
	}
}

void Runner::Run()
{
	_state = running;
	doAction("running");
}

void Runner::Jump()
{
	if (_state == running)
	{
		_state = jumpUp;
		getPhysicsBody()->setVelocity(Vec2(0, 600));
		// 需要播放特效声音
		auto audioEngine = SimpleAudioEngine::getInstance();
		audioEngine->playEffect("jump.wav");
		//_runnerSprite->stopAllActions();
		//doAction("jumpUp");
	}
}