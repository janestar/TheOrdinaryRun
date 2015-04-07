/**
 *  @Date  2015/04/04 12:35
 *  @File  BaseManager.cpp 
 *  
 *  @Author LiangJian Liu
 *  @Contact janestar92@163.com
 *  
 *  @brief
 *	
 */

#include "BaseManager.h"

#define ground_hight 59

USING_NS_CC;


int shape[4][4][4] = 
{
	{ 1, 1, 1, 1,
	  0, 0, 0, 0,
	  0, 0, 0, 0,
	  0, 0, 0, 0 },

	{ 0, 1, 1, 1,
      0, 0, 1, 0,
      0, 0, 0, 0,
      0, 0, 0, 0 },

    { 0, 1, 1, 0,
      0, 0, 1, 0,
      0, 0, 1, 0,
      0, 0, 0, 0},

    { 0, 1, 0, 0,
      0, 1, 0, 0,
      0, 1, 0, 0,
      0, 1, 0, 0 }
};

bool BaseManager::init()
{
	if ( !Node::init() )
	{
		return false;
	}
	auto size=Director::getInstance()->getVisibleSize();
	auto origin=Director::getInstance()->getVisibleOrigin();

	_bgMoveSpeed = 2;

	manageObject(size, origin);
	this->setCoinCount(0);
	this->setRockCount(0);
	this->scheduleUpdate();

	return true;
}


<<<<<<< HEAD

void BaseManager::manageObject(const Size& size,const Vec2& origin){
	Rock* rock=nullptr;
	Coin* coin=Coin::create();
	auto _coinx=coin->getConSize().width;
	auto _coiny=coin->getConSize().height;
	int xcoordinate=origin.x+size.width*2/3;
	for (int i=1;i<=rockNum;i++){
		rock=Rock::create();
		rock->setTag(rockTag);
		rock->setPosition(xcoordinate,ground_hight+rock->getConSize().height/2);
		int gap=CCRANDOM_0_1()*320+480;
		xcoordinate+=gap;
		this->addChild(rock);
		_rockVec.pushBack(rock);
	 }
	
	int randx=(int)(CCRANDOM_0_1()*size.width);
	int randy=(int)(CCRANDOM_0_1()*(size.height-4*_coiny*3/2-ground_hight)+ground_hight);
	int rock_x=_rockVec.at(0)->getPositionX();
	int rock_x2=_rockVec.at(1)->getPositionX();
	if(!((randx+4*_coinx*3/2<(rock_x-rock->getConSize().width/2))||randx>rock_x2+rock->getConSize().width/2)){
		randy=ground_hight+rock->getConSize().height+coin->getConSize().height/2;
=======
void BaseManager::manageObject(const Size &size, const Vec2 &origin)
{
	Rock *rock = nullptr;
	Coin *coin = Coin::create();
	auto _coinx = coin->getConSize().width;
	auto _coiny = coin->getConSize().height;

	int xcoordinate = origin.x + size.width * 2 / 3;
	for (int i = 1; i <= rockNum; ++i)
	{
		rock = Rock::create();
		rock->setTag(rockTag);
		rock->setPosition( xcoordinate,ground_hight + 
			rock->getConSize().height / 2 );
		this->addChild(rock);

		int gap = CCRANDOM_0_1() * 320 + 480;
		xcoordinate += gap;

		_rockVec.pushBack(rock);
	}

	int randx = (int)(CCRANDOM_0_1() * size.width);
	int randy = (int)( CCRANDOM_0_1() * 
		(size.height - 4 * _coiny * 3 / 2 - ground_hight) + ground_hight );

	int rock_x = _rockVec.at(0)->getPositionX();
	int rock_x2 = _rockVec.at(1)->getPositionX();
>>>>>>> 1043a7655c67544bcbbee3943afdfed3e7e6c89a

	if ( !( ( randx + 4 * _coinx * 3 / 2 < ( rock_x - rock->getConSize().width / 2 ) ) || 
		      randx>rock_x2+rock->getConSize().width/2 ) )
	{
		randy = ground_hight + 
			rock->getConSize().height + coin->getConSize().height / 2;
	} 

	int num = CCRANDOM_0_1() * 3;
	for (int j = 3; j >= 0; --j)
	{
		for (int k = 0; k <= 3; ++k)
		{
			if ( shape[num][j][k] )
			{
				Coin* _coin = Coin::create();
				_coin->setPosition( 
					Vec2(randx + k * _coinx * 3 / 2, randy + (3 - j) * _coiny) );
				_coin->setTag(coinTag);
				this->addChild(_coin);
				_coinVec.pushBack(_coin);
			}
		}
	}
}



void BaseManager::update(float dt)
{
	auto size = Director::getInstance()->getVisibleSize();
	auto origin = Director::getInstance()->getVisibleOrigin();

	for (auto coin : _coinVec)
	{
		if ( coin->getPositionX() < coin->getConSize().width / 2 * (-1) )
		{
			coin->setVisible(false);
			coin->setPosition( Vec2(10000, 320) );

			if (_coinCount < 4)
			{
				++_coinCount;
			}
		}
		else
		{
			coin->setPositionX(coin->getPositionX() - _bgMoveSpeed);
		}
	}

	for(auto rock : _rockVec)
	{
		if( rock->getPositionX() < rock->getConSize().width / 2 * (-1) )
		{
			rock->setVisible(false);
			rock->setPosition( Vec2(100000, 300) );

			if(_rockCount<2)
				_rockCount++;
		}
		else
		{
			rock->setPositionX(rock->getPositionX() - _bgMoveSpeed);
		}
	}
<<<<<<< HEAD
	
	if(_rockCount==2&&_coinCount==4){
		
		CCLOG("the origin x is %f,the y is %f",origin.x,origin.y);
		int xcoordinate=size.width+size.width/2;
		for(auto rock:_rockVec){
=======

	if (_rockCount == 2 && _coinCount == 4)
	{
		int xcoordinate = size.width + size.width / 2;
		for (auto rock : _rockVec)
		{
>>>>>>> 1043a7655c67544bcbbee3943afdfed3e7e6c89a
			rock->setPosition(xcoordinate,ground_hight+rock->getConSize().height/2);
			int gap=CCRANDOM_0_1()*200+200;
			xcoordinate+=gap;
			rock->setVisible(true);
		}

		int coiny_ = _rockVec.at(0)->getConSize().height;
		int coinx_ = _rockVec.at(0)->getConSize().width;

		int randx = (int)(CCRANDOM_0_1() * size.width + size.width);
		int randy = (int)(CCRANDOM_0_1() * 
			(size.height - 4 * coiny_ * 3 / 2 - ground_hight) + ground_hight);

		int rock_x = _rockVec.at(0)->getPositionX();
		int rock_x2 = _rockVec.at(1)->getPositionX();

		int rock_height = _rockVec.at(0)->getConSize().height;
		int rock_width = _rockVec.at(0)->getConSize().width;

		if ( !( ( randx + 4 * coinx_ * 3 / 2 < (rock_x-rock_width/2 )) || 
			      randx > rock_x2 + rock_width / 2 ) )
		{
			randy = ground_hight + rock_height+coiny_ / 2;

<<<<<<< HEAD
}



void BaseManager::setCoinCount(int x){

	this->_coinCount=x;
}
int BaseManager::getCoinCount(){
	return this->_coinCount;

}

void BaseManager::setRockCount(int x){
	this->_rockCount=x;

}
int BaseManager::getRockCount(){

	return this->_rockCount;
}

=======
		} 

		int num = CCRANDOM_0_1() * 3;
		int cnt = 0;
		for (int j = 3; j >= 0; --j)
		{
			for (int k = 0; k <= 3; ++k)
			{
				if ( shape[num][j][k] )
				{
					auto coin = _coinVec.at(cnt);
					coin->setPosition( 
						Vec2(randx + k * coinx_ * 3 / 2, randy + (3 - j) * coiny_) );
					coin->setVisible(true);
					++cnt;
				}
			}
		}

		_rockCount = 0;
		_coinCount = 0;
	}
}
>>>>>>> 1043a7655c67544bcbbee3943afdfed3e7e6c89a
