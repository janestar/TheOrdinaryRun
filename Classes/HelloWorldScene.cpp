/**
 * @file HelloWorldScene.cpp
 * @date 2015/04/01
 *
 * @author Yilin Gui
 * Contact: yilin.gui@gmail.com
 *
 * @brief  Implementation of the "Main Menu" Scene class
 * 
 * TODO: 
 *
 */

#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
#include "PlayScene.h"

USING_NS_CC;
using namespace CocosDenshion;


Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();

    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    // super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    _visibleSize = Director::getInstance()->getVisibleSize();
	CCLOG("ths size width is %f the size height is %f",_visibleSize.width,_visibleSize.height);
	_centerPoint = Vec2(_visibleSize.width / 2, _visibleSize.height / 2);

	preLoadMusic();           // load music
	createBackGround();    // create background
	createButton(_centerPoint + Vec2(0, -50));  // create button

    return true;
}

void HelloWorld::createBackGround()
{
	// create a Sprite instance with an image
	auto spriteBG = Sprite::create("putong_bg2.png");
	spriteBG->setPosition(_centerPoint);
	addChild(spriteBG);
}

void HelloWorld::createButton(const cocos2d::Vec2& pt)
{
	auto menuItem = MenuItemImage::create(
		"start_1.png", 
		"start_1.png", 
		CC_CALLBACK_0(HelloWorld::startGame, this));

	auto menu = Menu::create(menuItem, NULL);
	menu->setPosition(pt);
	addChild(menu);
}

void HelloWorld::preLoadMusic()
{
	auto audioEngine = SimpleAudioEngine::getInstance();
	audioEngine->preloadBackgroundMusic("putong_disco.wav");
	audioEngine->preloadEffect("dash_sound.wav");
	audioEngine->preloadEffect("jump.wav");
	audioEngine->preloadEffect("pickup_coin.wav");
}

void HelloWorld::startGame()
{
	//MessageBox("Game Start!", "start");
	Scene *playScene = TransitionFade::create(1.0f, PlayScene::createScene());
	Director::getInstance()->replaceScene(playScene);
}