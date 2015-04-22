#include "PauseLayer.h"
#include "PlayScene.h"
#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;
using namespace CocosDenshion;

bool PauseLayer::init()
{
	if (!LayerColor::initWithColor(Color4B(162, 162, 162, 128)))
	{
		return false;
	}

	buildUI();
	addEventListeners();

	return true;
}

void PauseLayer::buildUI()
{
	auto homeItem = MenuItemImage::create(
		"to_home.png", "to_home_selected.png", 
		CC_CALLBACK_1(PauseLayer::home, this));
	auto continueItem = MenuItemImage::create(
		"continue.png", "continue_selected.png", 
		CC_CALLBACK_1(PauseLayer::back, this));

	auto visibleSize = Director::getInstance()->getVisibleSize();
	auto origin = Director::getInstance()->getVisibleOrigin();

	homeItem->setPosition(visibleSize.width / 3, visibleSize.height / 2);
	continueItem->setPosition(visibleSize.width * 2 / 3, visibleSize.height / 2);

	auto menu = Menu::create(homeItem, continueItem, NULL);
	menu->setPosition(origin);

	addChild(menu);
}

void PauseLayer::addEventListeners()
{
	_listener = EventListenerTouchOneByOne::create();
	_listener->onTouchBegan = [&](Touch *t, Event *e)
	{
		return true;
	};
	_listener->setSwallowTouches(true);
	Director::getInstance()->getEventDispatcher()->
		addEventListenerWithSceneGraphPriority(_listener, this);
}

void PauseLayer::home(cocos2d::Ref *ref)
{
	Director::getInstance()->getEventDispatcher()->
		removeEventListener(_listener);

	// 这里必须执行一次 Director::getInstance()->resume();
	// 否则回到标题场景会出错
	Director::getInstance()->resume();

	Director::getInstance()->replaceScene(HelloWorld::createScene());

	// 关闭背景音乐
	auto audioEngine = SimpleAudioEngine::getInstance();
	audioEngine->playEffect("pickup_coin.wav");

	removeFromParent();
}

void PauseLayer::back(cocos2d::Ref *ref)
{
	Director::getInstance()->getEventDispatcher()->
		removeEventListener(_listener);
	auto playScene = (PlayScene*)this->getParent();
	playScene->onGameResume();

	removeFromParent();
}
