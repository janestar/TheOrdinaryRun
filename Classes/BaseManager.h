/**
 *  @Date  2015/04/04 10:55
 *  @File  BaseManager.h 
 *  
 *  @Author LiangJian Liu
 *  @Contact janestar92@163.com
 *  
 *  @brief
 *	
 */
#ifndef __BaseManager__H__
#define __BaseManager__H__

#include "cocos2d.h"
#include "Coin.h"
#include "Rock.h"

#define coinNum 4
#define coinTag 2
#define rockNum 2
#define rockTag 3

USING_NS_CC;

class BaseManager : public cocos2d::Node
{
public:
	CREATE_FUNC(BaseManager);
	virtual bool init();
	virtual void update(float dt);
<<<<<<< HEAD

	
=======
>>>>>>> 1043a7655c67544bcbbee3943afdfed3e7e6c89a

private:
	// important method!
	void manageObject(const Size&,const Vec2&);
<<<<<<< HEAD
	void setCoinCount(int x);
	int  getCoinCount();
	void setRockCount(int x);
	int getRockCount();
=======
>>>>>>> 1043a7655c67544bcbbee3943afdfed3e7e6c89a
	
	Vector<Coin*> _coinVec;
	Vector<Rock*> _rockVec;
<<<<<<< HEAD
=======

	float _randTime;
>>>>>>> 1043a7655c67544bcbbee3943afdfed3e7e6c89a
	int _coinCount;
	int _rockCount;

	float _bgMoveSpeed;

public:
	Vector<Coin*>& getCoins()
	{
		return _coinVec;
	}

	void setBgMoveSpeed(float speed)
	{
		_bgMoveSpeed = speed;
	}

	float getBgMoveSpeed() const
	{
		return _bgMoveSpeed;
	}

	void setCoinCount(int x)
	{
		this->_coinCount=x;
	}

	int getCoinCount() const
	{
		return this->_coinCount;
	}

	void setRockCount(int x)
	{
		this->_rockCount=x;
	}

	int getRockCount() const
	{
		return this->_rockCount;
	}

	void setRandTime(float y)
	{
		this->_randTime=y;
	}

	float getRandTime() const
	{
		return this->_randTime;
	}
};

#endif