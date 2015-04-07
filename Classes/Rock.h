/**
 *  @Date  2015/04/04 10:56
 *  @File  Rock.h 
 *  
 *  @Author LiangJian Liu
 *  @Contact janestar92@163.com
 *  
 *  @brief
 *	
 */
#ifndef __Rock__H__
#define __Rock__H__

#include "Base.h"
#include "cocos2d.h"

class Rock : public Base
{
public:
	virtual bool init();
	void initBody();
	CREATE_FUNC(Rock);

};

#endif