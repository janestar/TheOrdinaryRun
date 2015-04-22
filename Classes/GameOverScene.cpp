// GameOverScene.cpp

#include "GameOverScene.h"
#include "HelloWorldScene.h"

USING_NS_CC;

bool GameOver::init()
{
	LayerColor::initWithColor(Color4B::WHITE);

	_visibleSize = Director::getInstance()->getVisibleSize();

	auto label = Label::create();
	label->setString("Game Over");
	label->setSystemFontSize(40);
	label->setColor(Color3B::BLACK);
	addChild(label);
	label->setPosition(_visibleSize.width/2, _visibleSize.height/2 + 40);

	auto label2 = Label::create();
	label2->setString("touch to the title");
	label2->setSystemFontSize(25);
	label2->setColor(Color3B::BLACK);
	addChild(label2);
	label2->setPosition(_visibleSize.width/2, _visibleSize.height/2 - 20);

	auto director = Director::getInstance();

	auto touchListener = EventListenerTouchOneByOne::create();
	touchListener->onTouchBegan = [director](Touch *t, Event *e)
	{
		director->replaceScene(HelloWorld::createScene());
		return false;
	};
	director->getEventDispatcher()->
		addEventListenerWithSceneGraphPriority(touchListener, this);

	return true;
}

Scene* GameOver::createScene()
{
	auto s = Scene::create();
	auto l = GameOver::create();
	s->addChild(l);

	return s;
}
