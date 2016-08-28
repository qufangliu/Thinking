#include "HelloWorldScene.h"


#include "Manager/QFLManager.hpp"
#include "GameClass/QFLCtrl.hpp"

//测试层
#include "TestClass/TestNotification.hpp"

#include <iostream>

USING_NS_CC;

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
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    else {
        this->initData();
        this->addUI();
        return true;
    }
}

void HelloWorld::initData()
{
    m_nItemCount = 0;
    m_pMenu = nullptr;
}

void HelloWorld::addUI()
{
    //背景
    QFL_MANAGER->getTools()->addNoTouchLayerColor(this);
    
    //添加菜单
    m_pMenu = Menu::create();
    m_pMenu->setPosition(Vec2::ZERO);
    this->addChild(m_pMenu);
    
    //各个测试按钮
    
    //TestNotification
    this->addMenuItem("TestNotification", [=](){
        this->addChild(TestNotification::create());
    });
    
    //TestMVC
    this->addMenuItem("TestMVC", [=](){
        QFLCtrl::getInstance()->initWorld();
        
        Director::getInstance()->getScheduler()->scheduleUpdate(QFLCtrl::getInstance(), 1, false);
    });
}

void HelloWorld::addMenuItem(const std::string &strText, const std::function<void()> &funcCallback)
{
    m_nItemCount++;
    auto sizeScreen = Director::getInstance()->getVisibleSize();
    
    auto pBtn = MenuItemFont::create(strText, [=](Ref*){
        if (funcCallback) {
            funcCallback();
        }
        else {}
    });
    
    pBtn->setPosition(Vec2(sizeScreen.width * 0.5, sizeScreen.height - m_nItemCount * 40));
    m_pMenu->addChild(pBtn);
}

