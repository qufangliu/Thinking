//
//  Observer.hpp
//  TestDesignPattern
//
//  Created by QuFangliu on 16/8/2.
//  Copyright © 2016年 QuFangliu. All rights reserved.
//

/*
 简要说明
 
    观察者模式
 
    观察者模式可以理解为广播，它是对订阅了某条消息的观察者进行广播。通常需要一个单例来保存这些观察者的消息，这个单例可以称为消息中心。
 
    注意：
        1.观察者实现了目标对象和观察者之间的抽象耦合，相对于持有强引用的方式来说，观察者模式并不会导致循环引用的问题。
        2.观察者模式增强了程序扩展性。
        3.观察者模式通常使用单例模式实现。
 */

#ifndef Observer_hpp
#define Observer_hpp

#include <stdio.h>
#include <string>
#include <map>
#include <vector>
#include <functional>

//观察者
class NotifycationObserver
{
public:
    NotifycationObserver();
    NotifycationObserver(std::string strEventName, std::function<void()> funcCallback);
    ~NotifycationObserver();
    
    void execute(); //执行回调
    std::string getEventName() { return m_strEventName; }
    
private:
    std::string m_strEventName; //观察的事件名
    std::function<void()> m_funcCallback;   //回调处理事件
};

//消息中心
class NotifycationCenter
{
public:
    static NotifycationCenter* getInstance();
    
    void addObserver(NotifycationObserver *observer);   //添加观察者
    void notifyEvent(const std::string &strEvent);  //某个事件的所有观察者
    
private:
    NotifycationCenter();
    ~NotifycationCenter();
    
private:
    static NotifycationCenter* m_pInstance;
    
    std::map<std::string, std::vector<NotifycationObserver*>> m_mapObserver;    //用于存储观察者和事件信息的map
};

#endif /* Observer_hpp */
