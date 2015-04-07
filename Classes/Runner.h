/**
 * @file Runner.h
 * @date 2015/04/01
 *
 * @author Yilin Gui
 * Contact: yilin.gui@gmail.com
 *
 * @brief  Definition of the Runner class
 * 
 * TODO: 
 *
 */

#ifndef __THEORDINARYRUN_RUNNER_H__
#define __THEORDINARYRUN_RUNNER_H__

#include "cocos2d.h"
#include <string>

// enumeration type to represent the runner's states
enum runnerState
{
	running,
	jumpUp,
	jumpDown,
};

class Runner : public cocos2d::Node
{
public:

	/**
	 * @brief      Some initialization works
	 * @return    true if initialization succeeds, else return false
	 */
	virtual bool init();

	// implement the "static create()" method by MARCO defined in Cocos2d-x
	CREATE_FUNC(Runner);

	/**
	 * @brief    Initialization of action set of the runner
	 * @param [in] frameCache    Pointer to a cocos2d::SpriteFrameCache instance
	 */
	void initActionSet(cocos2d::SpriteFrameCache *frameCache);

	/**
	 * @brief    Perform an action by a specified action name
	 * @param [in] actionName    a cpp string instance which indicates an action
	 */
	void doAction(const std::string &actionName);

	/**
	 * @brief   Initialization of Physics Body
	 */
	void initBody();

	virtual void update(float delta);

	/**
	 * @brief    Getter of _state attribute
	 * @return    the state of the runner
	 */
	runnerState getState() const
	{
		return _state;
	}

	void Run();

	void Jump();

private:
	cocos2d::Sprite *_runnerSprite;
	runnerState _state;
	bool _twoStepJump;
	bool _superRush;
};

#endif