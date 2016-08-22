//
//  Observer.cpp
//  TestDesignPattern
//
//  Created by QuFangliu on 16/8/2.
//  Copyright © 2016年 QuFangliu. All rights reserved.
//

#include "Observer.hpp"

//观察者
NotifycationObserver::NotifycationObserver()
{
    
}

NotifycationObserver::NotifycationObserver(std::string strEventName, std::function<void()> funcCallback)
{
    m_strEventName = strEventName;
    m_funcCallback = funcCallback;
}
NotifycationObserver::~NotifycationObserver()
{
    
}
void NotifycationObserver::execute()
{
    m_funcCallback();
}


//消息中心
NotifycationCenter::NotifycationCenter()
{
    
}

NotifycationCenter::~NotifycationCenter()
{
    
}

NotifycationCenter* NotifycationCenter::getInstance()
{
    if (!m_pInstance) {
        m_pInstance = new NotifycationCenter();
    }
    return m_pInstance;
}

void NotifycationCenter::addObserver(NotifycationObserver *observer)
{
    std::vector<NotifycationObserver*> vectorObserver;
    
    if (m_mapObserver.find(observer->getEventName()) == m_mapObserver.end()) {
        vectorObserver.push_back(observer);
        
        m_mapObserver[observer->getEventName()] = vectorObserver;
    }
    else {
        vectorObserver = m_mapObserver[observer->getEventName()];
        
        if (std::find(vectorObserver.begin(), vectorObserver.end(), observer) == vectorObserver.end()) {
            m_mapObserver[observer->getEventName()].push_back(observer);
        }
        else {
            //已经有这个观察者了
        }
    }
}

void NotifycationCenter::notifyEvent(const std::string &strEvent)
{
    if (m_mapObserver.find(strEvent) != m_mapObserver.end()) {
        for (auto &it : m_mapObserver[strEvent]) {
            it->execute();//所有观察者执行事件
        }
    }
    else {
        //没有这个消息的观察者
    }
}











