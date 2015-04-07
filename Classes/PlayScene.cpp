/**
 * @file PlayScene.cpp
 * @date 2015/04/01
 *
 * @author Yilin Gui
 * Contact: yilin.gui@gmail.com
 *
 * @brief  Implementation of the PlayScene class
 * 
 * TODO: 
 *
 */

#include "PlayScene.h"
#include "SimpleAudioEngine.h"
#include "BaseManager.h"
#include "GameOverScene.h"

USING_NS_CC;
using namespace CocosDenshion;

Scene* PlayScene::createScene()
{
	auto scene = Scene::createWithPhysics();
	//scene->getPhysicsWorld()->
	//	setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
	scene->getPhysicsWorld()->setGravity(Vec2(0, -1200));

	auto layer = PlayScene::create();
	layer->setPhysicsWorld(scene->getPhysicsWorld());
	scene->addChild(layer);

	return scene;
}

bool PlayScene::init()
{
	if (!LayerColor::initWithColor(Color4B(255, 255, 255, 255)))
	{
		return false;
	}

	_groundHeight = 57;  // 地面高度
	_runnerPosX = 144;   // 角色x坐标位置
	_bgMoveSpeed = 4;  // 背景滚动速度

	SimpleAudioEngine::getInstance()->
		playBackgroundMusic("putong_disco.wav", true);

	initPhysicsWorld();  // 初始化物理世界

	initBG();  // 初始化背景

	// 创建奔跑角色对象
	_runner = Runner::create();
	_runner->setPosition(_runnerPosX, _groundHeight + 26);
	_runner->Run();
	addChild(_runner);

	// 创建道具管理对象
	auto _baseManager =BaseManager::create();
	_baseManager->setBgMoveSpeed(_bgMoveSpeed);
	addChild(_baseManager);

	addEventListeners();  // 添加触摸事件监听
	addContactListeners();  // 添加碰撞检测监听

	scheduleUpdate();  // 启动定时器

	return true;
}

void PlayScene::initPhysicsWorld()
{
	auto visibleSize = Director::getInstance()->getVisibleSize();  
	auto origin = Director::getInstance()->getVisibleOrigin();

	auto groundBody = PhysicsBody::createEdgeSegment(origin, 
		Vec2(visibleSize.width, 0), PHYSICSBODY_MATERIAL_DEFAULT, 1);

	auto groundNode = Node::create();
	groundNode->setPhysicsBody(groundBody);
	groundNode->setPosition(0, _groundHeight);
	
	addChild(groundNode);
}

void PlayScene::initBG()
{
	auto visibleSize = Director::getInstance()->getVisibleSize();

	// 背景图片1
	_bgSprite1 = Sprite::create("Map00.png");
	_bgSprite1->setPosition(visibleSize/2);
	addChild(_bgSprite1);

	// 地面图片1
	_groundSprite1 = Sprite::create("Ground00.png");
	_groundSprite1->setPosition(visibleSize.width / 2, 
		_groundSprite1->getContentSize().height / 2);
	addChild(_groundSprite1);

	// 背景图片2
	_bgSprite2 = Sprite::create("Map01.png");
	_bgSprite2->setPosition(
		_bgSprite1->getContentSize().width + visibleSize.width / 2, 
		visibleSize.height / 2);
	addChild(_bgSprite2);

	// 地面图片2
	_groundSprite2 = Sprite::create("Ground01.png");
	_groundSprite2->setPosition(
		_groundSprite1->getContentSize().width + visibleSize.width / 2, 
		_groundSprite2->getContentSize().height / 2);
	addChild(_groundSprite2);
}

void PlayScene::update(float delta)
{
	int posX1 = _bgSprite1->getPositionX();
	int posX2 = _bgSprite2->getPositionX();

	// 背景、地面向左滚动
	posX1 -= _bgMoveSpeed;
	posX2 -= _bgMoveSpeed;

	auto mapSize = _bgSprite1->getContentSize();
	if (posX1 < -mapSize.width / 2)
	{
		posX1 = mapSize.width + mapSize.width / 2;
		posX2 = mapSize.width / 2;
	}

	if (posX2 < -mapSize.width / 2)
	{  
		posX2 = mapSize.width + mapSize.width / 2;  
		posX1 = mapSize.width / 2;  
	}  

	_bgSprite1->setPositionX(posX1);  
	_bgSprite2->setPositionX(posX2);  
	_groundSprite1->setPositionX(posX1);  
	_groundSprite2->setPositionX(posX2);  
}

void PlayScene::addEventListeners()
{
    auto touchListener = EventListenerTouchOneByOne::create();
	touchListener->onTouchBegan = [this](Touch *t, Event *e)
	{
		_runner->Jump();
		return false;
	};
	Director::getInstance()->getEventDispatcher()->
		addEventListenerWithSceneGraphPriority(touchListener, this);
}

void PlayScene::addContactListeners()
{
	auto contactListenner = EventListenerPhysicsContact::create();  
	contactListenner->onContactBegin = [this](PhysicsContact &contact)
	{
		//MessageBox("aaa", "test");
		auto b_1 = (Sprite* )contact.getShapeA()->getBody()->getNode();  
		auto b_2 = (Sprite* )contact.getShapeB()->getBody()->getNode();

		// 与金币碰撞
		if (b_1->getTag() == coinTag || b_2->getTag() == coinTag)
		{  
			b_1->setVisible(false);  
		}  

		// 与障碍物碰撞
		//if (b_1->getTag() == rockTag || b_2->getTag() == rockTag)
		//{  
		//	// 停止定时器
		//	this->unscheduleUpdate();
		//	Director::getInstance()->
		//		replaceScene(GameOver::createScene());
		//}  

		return false;
	};

	Director::getInstance()->getEventDispatcher()->
		addEventListenerWithSceneGraphPriority(contactListenner, this);
}