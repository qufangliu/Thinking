//
//  TestNotification.cpp
//  QFLTestMVC
//
//  Created by QuFangliu on 16/8/26.
//
//

#include "TestNotification.hpp"

USING_NS_CC;

TestNotification::TestNotification()
{
    m_nItemCount = 0;
    m_pMenu = nullptr;
    m_pListener1 = nullptr;
    m_pListener2 = nullptr;
}

TestNotification::~TestNotification()
{
    
}

bool TestNotification::init()
{
    if (!Layer::init()) {
        return false;
    }
    else {
        this->addUI();
        return true;
    }
}

void TestNotification::addUI()
{
    //添加背景
    QFL_MANAGER->getTools()->addNoTouchLayerColor(this);
    
    //初始化监听器
    m_pListener1 = QFLNotificationListener::create();
    m_pListener1->addAttention("SayHello", [=](){
        log("Listener1->Hello");
    });
    
    m_pListener2 = QFLNotificationListener::create();
    m_pListener2->addAttention("SayHello", [=](){
        log("Listener2->Hello");
    });

    //菜单
    m_pMenu = Menu::create();
    m_pMenu->setPosition(Vec2::ZERO);
    this->addChild(m_pMenu);
    
    //添加关闭按钮
    m_pMenu->addChild(QFL_MANAGER->getTools()->getCloseMenuItem(this));
    
    //测试菜单项
    //添加listener1
    this->addMenuItem("AddListener1", [=](){
        log("-----------AddListener1");
        QFL_MANAGER->getNotificationCenter()->addNotificationListener(m_pListener1);
    });
    //添加listener2
    this->addMenuItem("AddListener2", [=](){
        log("-----------AddListener2");
        QFL_MANAGER->getNotificationCenter()->addNotificationListener(m_pListener2);
    });
    
    
    //删除listener1
    this->addMenuItem("RemoveListener1", [=](){
        log("-----------RemoveListener1");
        QFL_MANAGER->getNotificationCenter()->removeNotificationListener(m_pListener1);
    });
    //删除listener2
    this->addMenuItem("RemoveListener2", [=](){
        log("-----------RemoveListener2");
        QFL_MANAGER->getNotificationCenter()->removeNotificationListener(m_pListener2);
    });
    
    
    //发送事件SayHello
    this->addMenuItem("Event:SayHello", [=](){
        log("-----------SayHello");
        QFL_MANAGER->getNotificationCenter()->notifyEvent("SayHello");
    });
    //发送事件SayNo
    this->addMenuItem("Event:SayNo", [=](){
        log("-----------SayNo");
        QFL_MANAGER->getNotificationCenter()->notifyEvent("SayNo");
    });
    //发送事件SayHi
    this->addMenuItem("Event:SayHi", [=](){
        log("-----------SayHi");
        QFL_MANAGER->getNotificationCenter()->notifyEvent("SayHi");
    });
    
    
    //listener1添加SayHello
    this->addMenuItem("Listener1 + SayHello", [=](){
        log("-----------Listener1-Add-SayHello");
        m_pListener1->addAttention("SayHello", [=](){
            log("Listener1->Hello");
        });
    });
    //listener1添加SayNo
    this->addMenuItem("Listener1 + SayNo", [=](){
        log("-----------Listener1-Add-SayNo");
        m_pListener1->addAttention("SayNo", [=](){
            log("Listener1->No");
        });
    });
    //listener1添加SayHi
    this->addMenuItem("Listener1 + SayHi", [=](){
        log("-----------Listener1-Add-SayHi");
        m_pListener1->addAttention("SayHi", [=](){
            log("Listener1->Hi");
        });
    });
    //listener1移除SayHello
    this->addMenuItem("Listener1 - SayHello", [=](){
        log("-----------Listener1-Remove-SayHello");
        m_pListener1->removeAttention("SayHello");
    });
    //listener1移除SayNo
    this->addMenuItem("Listener1 - SayNo", [=](){
        log("-----------Listener1-Remove-SayNo");
        m_pListener1->removeAttention("SayNo");
    });
    //listener1移除SayHi
    this->addMenuItem("Listener1 - SayHi", [=](){
        log("-----------Listener1-Remove-SayHi");
        m_pListener1->removeAttention("SayHi");
    });
    
    
    //listener2添加SayHello
    this->addMenuItem("Listener2 + SayHello", [=](){
        log("-----------Listener2-Add-SayHello");
        m_pListener2->addAttention("SayHello", [=](){
            log("Listener2->Hello");
        });
    });
    //listener2添加SayHi
    this->addMenuItem("Listener2 + SayHi", [=](){
        log("-----------Listener2-Add-SayHi");
        m_pListener2->addAttention("SayHi", [=](){
            log("Listener2->Hi");
        });
    });
    //listener2添加SayNo
    this->addMenuItem("Listener2 + SayNo", [=](){
        log("-----------Listener2-Add-SayNo");
        m_pListener2->addAttention("SayNo", [=](){
            log("Listener2->No");
        });
    });
    //listener2移除SayHello
    this->addMenuItem("Listener2 - SayHello", [=](){
        log("-----------Listener2-Remove-SayHello");
        m_pListener2->removeAttention("SayHello");
    });
    //listener2移除SayHi
    this->addMenuItem("Listener2 - SayHi", [=](){
        log("-----------Listener2-Remove-SayHi");
        m_pListener2->removeAttention("SayHi");
    });
    //listener2移除SayNo
    this->addMenuItem("Listener2 - SayNo", [=](){
        log("-----------Listener2-Remove-SayNo");
        m_pListener2->removeAttention("SayNo");
    });
}

void TestNotification::addMenuItem(const std::string &strText, const std::function<void ()> &funcCallback)
{
    //计数，为了摆放位置
    m_nItemCount ++;
    
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