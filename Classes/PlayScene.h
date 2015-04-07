/**
 * @file PlayScene.h
 * @date 2015/04/01
 *
 * @author Yilin Gui
 * Contact: yilin.gui@gmail.com
 *
 * @brief  Definition of the PlayScene class
 * 
 * TODO: 
 *
 */

#ifndef __THEORDINARYRUN_PLAYSCENE_H__
#define __THEORDINARYRUN_PLAYSCENE_H__

#include "cocos2d.h"
#include "Runner.h"

class PlayScene : public cocos2d::LayerColor
{
public:
	/**
	 * @brief      Create an instance of cocos2d::Scene
	 * @return    the instance pointer
	 */
	static cocos2d::Scene* createScene();

	/**
	 * @brief      Some initialization works
	 * @return    true if initialization succeeds, else return false
	 */
	virtual bool init();

	// implement the "static create()" method by MARCO defined in Cocos2d-x
	CREATE_FUNC(PlayScene);

	/**
	 * @brief      Initialization of background
	 */
	void initBG();

	/**
	 * @brief      Callback function, using with scheduleUpdate()
	 */
	virtual void update(float delta);

	/**
	 * @brief    Setter of private member "_physicsWorld"
	 * @param [in] world    Pointer of a cocos2d::PhysicsWorld instance
	 */
	void setPhysicsWorld(cocos2d::PhysicsWorld *world)
	{
		_physicsWorld = world;
	}

	/**
	 * @brief    Getter of private member "_physicsWorld"
	 * @return  the _physicsWorld attribute
	 */
	cocos2d::PhysicsWorld* getPhysicsWorld() const
	{
		return _physicsWorld;
	}

private:
	void initPhysicsWorld();
	void addEventListeners();
	void addContactListeners();

private:
	cocos2d::PhysicsWorld *_physicsWorld;

	float _groundHeight;
	float _runnerPosX;

	Runner *_runner;

	cocos2d::Sprite *_bgSprite1;
	cocos2d::Sprite *_bgSprite2;
	cocos2d::Sprite *_groundSprite1;
	cocos2d::Sprite *_groundSprite2;
	
    float _bgMoveSpeed;
};

#endif