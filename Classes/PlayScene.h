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
#include "BaseManager.h"

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

	/**
	 * @brief    Pause the game
	 */
	void onGamePause();

	/**
	 * @brief    Resume the game
	 */
	void onGameResume();

	/**
	 * @brief    Start "Super Dash"
	 */
	void startDash();

	/**
	 * @brief    Stop "Super Dash"
	 */
	void stopDash();

	// 位置比例缩放因子
	static double POS_X_SCALE_FACTOR;
	static double POS_Y_SCALE_FACTOR;

	// 单位时间得分值
	static int SCORE_PER_SEC;

	// 单个金币得分值
	static int SCORE_PER_COIN;

private:
	/**
	 * @brief      Initialization of background
	 */
	void initBG();

	/**
	 * @brief      Build UI componets. (pause button, score label, etc.)
	 */
	void buildUI();

	///@brief 初始化物理世界
	void initPhysicsWorld();   

	///@brief 添加事件监听（触摸屏幕等）
	void addEventListeners();

	///@brief 添加碰撞检测事件监听
	void addContactListeners();

	void startTimer();

	void stopTimer();

	enum BG_SPEED
	{
		NORMAL_SPEED = 4,
		DASH_SPEED = 12
	};

private:
	cocos2d::Size _visibleSize;  // 窗口大小

	cocos2d::PhysicsWorld *_physicsWorld;  // 物理世界

	float _groundHeight;    // 地面高度
	float _runnerPosX;        // 人物位置(X轴)

	Runner *_runner;                           // 人物对象
	BaseManager *_baseManager;       // 道具管理对象

	// 下面四个精灵用于实现背景和地面的循环滚动
	cocos2d::Sprite *_bgSprite1;           // 背景精灵1
	cocos2d::Sprite *_bgSprite2;           // 背景精灵2
	cocos2d::Sprite *_groundSprite1;    // 地面精灵1
	cocos2d::Sprite *_groundSprite2;    // 地面精灵2

	cocos2d::Sprite *_pauseButton;      // 暂停按钮

	// FORTEST, 加速按钮
	cocos2d::Sprite *_dashButton;

	long _remainedDashTime;  // 剩余加速时间，用于控制加速
	bool _isDash;  // 是否为冲刺状态

	bool _timerRunning;  // 是否计时（控制计时标签更新数字）
	long _accumTime;     // 累计时间

    float _bgMoveSpeed;  // 奔跑速度（人物跑动速度）

	unsigned int _countCoins;  // 金币计数
	unsigned int _score;  // 得分计数

	// 计时标签
	cocos2d::Label *_timeTextLabel;
	cocos2d::Label *_timeLabel;  

	// 得分标签
	cocos2d::Label *_scoreTextLabel;
	cocos2d::Label *_scoreLabel;
};

#endif