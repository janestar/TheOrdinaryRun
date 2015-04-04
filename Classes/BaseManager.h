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
class BaseManager : public cocos2d::Node{
public:
	CREATE_FUNC(BaseManager);
	virtual bool init();
	virtual void update(float dt);

	

private:
	void manageObject(const Size&,const Vec2&);
	void setCoinCount(int x);
	int  getCoinCount();
	void setRockCount(int x);
	int getRockCount();
	

	Vector<Coin*> _coinVec;
	Vector<Rock*> _rockVec;
	int _coinCount;
	int _rockCount;

};/**/

#endif